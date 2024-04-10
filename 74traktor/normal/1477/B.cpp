#include <bits/stdc++.h>

using namespace std;

int const maxn = 2e5 + 5;
int sum[(1 << 20)];
int psh[(1 << 20)];
string go, good;

void build(int i, int l, int r) {
    if (r - l == 1) {
        sum[i] = go[l] - '0';
    }
    else {
        int m = (r + l) / 2;
        build(2 * i + 1, l, m);
        build(2 * i + 2, m, r);
        sum[i] = sum[2 * i + 1] + sum[2 * i + 2];
    }
}

inline void push(int i, int l, int r) {
    if (psh[i] == -1) return;
    sum[i] = (r - l) * psh[i];
    psh[2 * i + 1] = psh[i];
    psh[2 * i + 2] = psh[i];
    psh[i] = -1;
}

void upd(int i, int l, int r, int lq, int rq, int x) {
    push(i, l, r);
    if (lq >= r || l >= rq) return;
    if (lq <= l && r <= rq) {
        psh[i] = x;
        push(i, l, r);
        return;
    }
    int m = (r + l) / 2;
    upd(2 * i + 1, l, m, lq, rq, x);
    upd(2 * i + 2, m, r, lq, rq, x);
    sum[i] = sum[2 * i + 1] + sum[2 * i + 2];
}

int get(int i, int l, int r, int lq, int rq) {
    push(i, l, r);
    if (lq >= r || l >= rq) return 0;
    if (lq <= l && r <= rq) return sum[i];
    int m = (r + l) / 2;
    return get(2 * i + 1, l, m, lq, rq) + get(2 * i + 2, m, r, lq, rq);
}

int check(int i, int l, int r) {
    push(i, l, r);
    if (r - l == 1) {
        return good[l] == char('0' + sum[i]);
    }
    int m = (r + l) / 2;
    return (check(2 * i + 1, l, m)&check(2 * i + 2, m, r));
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, q, l, r;
        cin >> n >> q;
        string s, f;
        cin >> s >> f;
        go = "#" + f;
        good = "#" + s;
        vector < pair < int, int > > a;
        for (int i = 1; i <= q; ++i) {
            cin >> l >> r;
            a.push_back({l, r});
        }
        reverse(a.begin(), a.end());
        int N = (int)f.size();
        for (int i = 0; i < min(1 << 19, 4 * N); ++i) psh[i] = -1;
        build(0, 1, N + 1);
        int flag = 0;
        for (auto key : a) {
            int w = get(0, 1, N + 1, key.first, key.second + 1);
            if ((key.second - key.first) % 2 == 1 && w == (key.second - key.first + 1) / 2) flag = 1;
            if (w >= (key.second - key.first + 2) / 2) {
                upd(0, 1, N + 1, key.first, key.second + 1, 1);
            }
            else upd(0, 1, N + 1, key.first, key.second + 1, 0);
        }
        if (!flag && check(0, 1, N + 1)) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}