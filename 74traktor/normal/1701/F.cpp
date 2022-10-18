#include<bits/stdc++.h>

using namespace std;

#define int long long

int const maxn = 2e5 + 5;
int ans[(1 << 19)], sval[(1 << 19)], psh[(1 << 19)], len[(1 << 19)];

void push(int i, int lenn) {
    if (lenn > 1) {
        ans[i] -= psh[i] * len[i];
        ans[i] += 2 * psh[i] * sval[i] + len[i] * psh[i] * psh[i];
        sval[i] += psh[i] * len[i];
        psh[2 * i + 1] += psh[i];
        psh[2 * i + 2] += psh[i];
        psh[i] = 0;
    } else {
        ans[i] = len[i] * (psh[i] * psh[i] - psh[i]);
        sval[i] = psh[i] * len[i];
    }
}

void in(int i, int l, int r, int lq, int t) {
    push(i, r - l);
    if (!(l <= lq && lq < r)) return;
    if (r - l == 1) {
        len[i] = t;
        push(i, r - l);
    } else {
        push(i, r - l);
        int m = (r + l) / 2;
        in(2 * i + 1, l, m, lq, t);
        in(2 * i + 2, m, r, lq, t);
        ans[i] = ans[2 * i + 1] + ans[2 * i + 2];
        sval[i] = sval[2 * i + 1] + sval[2 * i + 2];
        len[i] = len[2 * i + 1] + len[2 * i + 2];
    }
}

void upd(int i, int l, int r, int lq, int rq, int add) {
    push(i, r - l);
    if (lq >= r || l >= rq) return;
    if (lq <= l && r <= rq) {
        psh[i] += add;
        push(i, r - l);
        return;
    }
    int m = (r + l) / 2;
    upd(2 * i + 1, l, m, lq, rq, add);
    upd(2 * i + 2, m, r, lq, rq, add);
    ans[i] = ans[2 * i + 1] + ans[2 * i + 2];
    sval[i] = sval[2 * i + 1] + sval[2 * i + 2];
    len[i] = len[2 * i + 1] + len[2 * i + 2];
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q, d, x;
    cin >> q >> d;
    set < int > used;
    for (int i = 1; i <= q; i++) {
        cin >> x;
        if (used.find(x) != used.end()) {
            in(0, 1, maxn, x, 0);
            upd(0, 1, maxn, max((long long)1, x - d), x, -1);
            used.erase(x);
        } else {
            in(0, 1, maxn, x, 1);
            upd(0, 1, maxn, max((long long)1, x - d), x, 1);
            used.insert(x);
        }
        cout << ans[0] / 2 << '\n';
        /*int stupid = 0;
        for (auto key : used) {
            for (auto elem : used) {
                for (auto q : used) {
                    if (key < elem && elem < q && q - key <= d) stupid++;
                }
            }
        }
        cout << stupid << '\n';*/
    }
    return 0;
}