#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
int const maxn = 1e6 + 5;
int a[maxn], b[maxn];
pair < int, int > c[maxn];
int all_elem[2 * maxn];
int cur, inf = 1e9 + 7;
int f[2 * maxn];
int psh[8 * maxn];
pair < int, int > imin[4 * maxn];

inline pair < int, int > unions(pair < int, int > c, pair < int, int > d) {
    if (c.first < d.first || (c.first == d.first && c.second > d.second)) return c;
    return d;
}

void build(int i, int l, int r) {
    psh[i] = 0;
    if (r - l == 1) imin[i] = {0, l};
    else {
        int m = (r + l) / 2;
        build(2 * i + 1, l, m);
        build(2 * i + 2, m, r);
        imin[i] = unions(imin[2 * i + 1], imin[2 * i + 2]);
    }
}

inline void push(int i) {
    imin[i].first += psh[i];
    psh[2 * i + 1] += psh[i];
    psh[2 * i + 2] += psh[i];
    psh[i] = 0;
}

void adds(int i, int l, int r, int lq, int rq, int x) {
    push(i);
    if (lq >= r || l >= rq) return;
    if (lq <= l && r <= rq) {
        psh[i] += x;
        push(i);
        return;
    }
    int m = (r + l) / 2;
    adds(2 * i + 1, l, m, lq, rq, x);
    adds(2 * i + 2, m, r, lq, rq, x);
    imin[i] = unions(imin[2 * i + 1], imin[2 * i + 2]);
}

pair < int, int > get(int i, int l, int r, int lq, int rq) {
    push(i);
    if (lq >= r || l >= rq) return {inf, inf};
    if (lq <= l && r <= rq) return imin[i];
    int m = (r + l) / 2;
    return unions(get(2 * i + 1, l, m, lq, rq), get(2 * i + 2, m, r, lq, rq));
}

inline void add(int i) {
    while (i <= cur) {
        f[i]++;
        i = (i|(i + 1));
    }
}

inline int get(int i) {
    int ans = 0;
    while (i > 0) {
        ans += f[i];
        i = (i&(i + 1)) - 1;
    }
    return ans;
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
        int n, m;
        cur = 0;
        cin >> n >> m;
        build(0, 0, n + 1);
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i <= m; ++i) cin >> b[i];
        sort(b + 1, b + m + 1);
        for (int i = 1; i <= n; ++i) {
            all_elem[++cur] = a[i];
        }
        for (int i = 1; i <= m; ++i) {
            all_elem[++cur] = b[i];
        }
        sort(all_elem + 1, all_elem + cur + 1);
        for (int i = 1; i <= n; ++i) {
            a[i] = lower_bound(all_elem + 1, all_elem + cur + 1, a[i]) - all_elem;
        }
        for (int i = 1; i <= m; ++i) {
            b[i] = lower_bound(all_elem + 1, all_elem + cur + 1, b[i]) - all_elem;
        }
        ll ans = 0;
        for (int i = 0; i <= cur; ++i) f[i] = 0;
        for (int i = n; i >= 1; --i) {
            ans += get(a[i]);
            add(a[i] + 1);
        }
        for (int i = 1; i <= n; ++i) c[i] = {a[i], i};
        sort(c + 1, c + n + 1);
        int pos = n;
        for (int i = 1; i <= n; ++i) {
            adds(0, 0, n + 1, 0, i, 1);
        }
        int lptr = n, rptr = n;
        for (int i = m; i >= 1; --i) {
            if (b[i] != b[i + 1]) {
                while (rptr > lptr) {
                    adds(0, 0, n + 1, c[rptr].second, n + 1, 1);
                    rptr--;
                }
            }
            while (rptr > 0 && b[i] < c[rptr].first) {
                adds(0, 0, n + 1, 0, c[rptr].second, -1);
                adds(0, 0, n + 1, c[rptr].second, n + 1, 1);
                rptr--;
            }
            lptr = min(lptr, rptr);
            while (lptr > 0 && b[i] == c[lptr].first) {
                adds(0, 0, n + 1, 0, c[lptr].second, -1);
                lptr--;
            }
            pair < int, int > best = get(0, 0, n + 1, 0, pos + 1);
            ans += best.first;
            pos = best.second;
        }
        cout << ans << '\n';
    }
    return 0;
}