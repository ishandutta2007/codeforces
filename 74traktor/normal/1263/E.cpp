#include<bits/stdc++.h>

using namespace std;

int const maxn = 1e6 + 5;
char a[maxn];
int imax[4 * maxn], psh[8 * maxn], imin[4 * maxn];

inline void push(int i) {
    imax[i] += psh[i], imin[i] += psh[i];
    psh[2 * i + 1] += psh[i], psh[2 * i + 2] += psh[i];
    psh[i] = 0;
}

void update(int i, int l, int r, int lq, int rq, int val) {
    push(i);
    if (lq >= r || l >= rq) return;
    if (lq <= l && r <= rq) {
        psh[i] += val;
        push(i);
        return;
    }
    int m = (r + l) / 2;
    update(2 * i + 1, l, m, lq, rq, val);
    update(2 * i + 2, m, r, lq, rq, val);
    imax[i] = max(imax[2 * i + 1], imax[2 * i + 2]);
    imin[i] = min(imin[2 * i + 1], imin[2 * i + 2]);
}

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, bal = 0, pos = 0;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < maxn; ++i) a[i] = '0';
    for (auto c : s) {
        if (c == 'L') {
            pos--;
            pos = max(pos, 0);
        }
        else if (c == 'R') pos++;
        else {
            if (a[pos] == '(') {
                update(0, 0, maxn, pos, maxn, -1);
                bal--;
            }
            else if (a[pos] == ')') {
                update(0, 0, maxn, pos, maxn, 1);
                bal++;
            }
            a[pos] = c;
            if (c == '(') update(0, 0, maxn, pos, maxn, 1), bal++;
            else if (c == ')') update(0, 0, maxn, pos, maxn, -1), bal--;
        }
        if (bal == 0 && imin[0] == 0) cout << imax[0] << " ";
        else cout << -1 << " ";
    }
    return 0;
}