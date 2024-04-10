#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
int const maxn = 1e5 + 5;
int a[maxn], suff[maxn];
vector < int > in[maxn];
ll pref[maxn], mx[(1 << 18)], psh[(1 << 19)], p[maxn], b[maxn];

void build(int i, int l, int r) {
    if (r - l == 1) {
        mx[i] = pref[l];
    } else {
        int m = (r + l) / 2;
        build(2 * i + 1, l, m);
        build(2 * i + 2, m, r);
        mx[i] = min(mx[2 * i + 1], mx[2 * i + 2]);
    }
}

inline void push(int i) {
    mx[i] += psh[i];
    psh[2 * i + 1] += psh[i];
    psh[2 * i + 2] += psh[i];
    psh[i] = 0;
}

inline void add(int i, int l, int r, int lq, int rq, int x) {
    push(i);
    if (lq >= r || l >= rq) return;
    if (lq <= l && r <= rq) {
        psh[i] += x;
        push(i);
        return;
    }
    int m = (r + l) / 2;
    add(2 * i + 1, l, m, lq, rq, x);
    add(2 * i + 2, m, r, lq, rq, x);
    mx[i] = min(mx[2 * i + 1], mx[2 * i + 2]);
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }
    for (int i = n; i >= 1; --i) suff[i] = max(suff[i + 1], a[i]);
    vector < pair < int, int > > g;
    for (int j = 1; j <= m; ++j) {
        cin >> b[j];
    }
    for (int j = 1; j <= m; ++j) cin >> p[j];
    for (int j = 1; j <= m; ++j) g.push_back({p[j], b[j]});
    build(0, 1, n + 1);
    sort(g.begin(), g.end());
    int answer = 0;
    for (auto key : g) {
        int lef = 0, righ = n + 1;
        while (righ - lef > 1) {
            int mid = (righ + lef) / 2;
            if (suff[mid] >= key.second) lef = mid;
            else righ = mid;
        }
        if (lef != 0) {
            add(0, 1, n + 1, lef, n + 1, -key.first);
            if (mx[0] >= 0) answer++;
            else add(0, 1, n + 1, lef, n + 1, key.first);
        }
    }
    cout << answer << '\n';
    return 0;
}