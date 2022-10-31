#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
int const maxn = 3e5 + 5;
int a[maxn];
vector < pair < int, int > > ask[maxn];
ll ans[maxn];
int imin[(1 << 20)], inf = 1e9 + 7;
int nxt[maxn];
ll sum[(1 << 21)];
ll psh[(1 << 22)];

void builds(int i, int l, int r) {
    psh[i] = 0;
    if (r - l == 1) sum[i] = 0;
    else {
        int m = (r + l) / 2;
        builds(2 * i + 1, l, m);
        builds(2 * i + 2, m, r);
        sum[i] = sum[2 * i + 1] + sum[2 * i + 2];
    }
}

inline void push(int i, int l, int r) {
    sum[i] += psh[i] * (ll)(r - l);
    psh[2 * i + 1] += psh[i];
    psh[2 * i + 2] += psh[i];
    psh[i] = 0;
}

void adds(int i, int l, int r, int lq, int rq, int x) {
    push(i, l, r);
    if (lq >= r || l >= rq) return;
    if (lq <= l && r <= rq) {
        psh[i] += x;
        push(i, l, r);
        return;
    }
    int m = (r + l) / 2;
    adds(2 * i + 1, l, m, lq, rq, x);
    adds(2 * i + 2, m, r, lq, rq, x);
    sum[i] = sum[2 * i + 1] + sum[2 * i + 2];
}

ll gett(int i, int l, int r, int lq, int rq) {
    push(i, l, r);
    if (lq >= r || l >= rq) return  0;
    if (lq <= l && r <= rq) return sum[i];
    int m = (r + l) / 2;
    return gett(2 * i + 1, l, m, lq, rq) + gett(2 * i + 2, m, r, lq, rq);
}

void build(int i, int l, int r) {
    if (r - l == 1) imin[i] = a[l];
    else {
        int m = (r + l) / 2;
        build(2 * i + 1, l, m);
        build(2 * i + 2, m, r);
        imin[i] = min(imin[2 * i + 1], imin[2 * i + 2]);
    }
}

int get(int i, int l, int r, int lq, int rq) {
    if (lq >= r || l >= rq) return inf;
    if (lq <= l && r <= rq) return imin[i];
    int m = (r + l) / 2;
    return min(get(2 * i + 1, l, m, lq, rq), get(2 * i + 2, m, r, lq, rq));
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q, k, l, r;
    cin >> n >> q >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    vector < int > st;
    for (int i = n; i >= 1; --i) {
        while ((int)st.size() > 0 && a[i] <= a[st.back()]) st.pop_back();
        if ((int)st.size() == 0) nxt[i] = n + 1;
        else nxt[i] = st.back();
        st.push_back(i);
    }
    build(0, 1, n + 1);
    for (int i = 1; i <= q; ++i) {
        cin >> l >> r;
        if (nxt[l] > r) {
            ans[i] = (ll)a[l] * (ll)((r - l + k) / k);
        }
        else {
            ans[i] = (ll)a[l] * (ll)((nxt[l] - l + k - 1) / k);
            int pos = k * ((nxt[l] - l + k - 1) / k) + l - 1;
            if (pos > r) continue;
            int lst = ((r - l + k) / k - 1) * k + l;
            ask[pos - k + 2].push_back({lst, i});
        }
    }
    for (int i = 1; i <= k; ++i) {
        vector < int > L;
        for (int j = i; j <= n; j += k) {
            L.push_back(j);
        }
        vector < pair < int, int > > go;
        builds(0, 0, (int)L.size());
        for (int j = (int)L.size() - 1; j >= 0; --j) {
            int val = get(0, 1, n + 1, L[j], min(n, L[j] + k - 1) + 1);
            int cnt = 1;
            while ((int)go.size() > 0 && val < go.back().first) {
                adds(0, 0, (int)L.size(), j + cnt, j + cnt + go.back().second, -go.back().first);
                cnt += go.back().second;
                go.pop_back();
            }
            adds(0, 0, (int)L.size(), j, j + cnt, val);
            go.push_back({val, cnt});
            for (auto key : ask[L[j]]) {
                int R = upper_bound(L.begin(), L.end(), key.first) - L.begin();
                ans[key.second] += gett(0, 0, (int)L.size(), j, R);
            }
        }
    }
    for (int i = 1; i <= q; ++i) cout << ans[i] << '\n';
    return 0;
}