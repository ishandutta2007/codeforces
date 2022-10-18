#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

int arr[100005], seg[800005], lazy[800005], num[200005];
ll sum[100005];
vector<int> brr[100005];

void build(int l, int r, int rt) {
    lazy[rt] = 0;
    if (l == r)
        return seg[rt] = num[l], void();
    int mid = (l + r) >> 1;
    build(l, mid, rt << 1), build(mid + 1, r, rt << 1 | 1);
    seg[rt] = min(seg[rt << 1], seg[rt << 1 | 1]);
}

int query(int L, int R, int l, int r, int rt) {
    if (L <= l && R >= r)
        return seg[rt];
    int mid = (l + r) >> 1;
    if (R <= mid) return query(L, R, l, mid, rt << 1) + lazy[rt << 1];
    if (L > mid) return query(L, R, mid + 1, r, rt << 1 | 1) + lazy[rt << 1 | 1];
    return min(query(L, R, l, mid, rt << 1) + lazy[rt << 1], query(L, R, mid + 1, r, rt << 1 | 1) + lazy[rt << 1 | 1]);
}

void modify(int L, int R, int l, int r, int rt, int v) {
    if (L <= l && R >= r)
        return lazy[rt] += v, void();
    int mid = (l + r) >> 1;
    if (L <= mid) modify(L, R, l, mid, rt << 1, v);
    if (R > mid) modify(L, R, mid + 1, r, rt << 1 | 1, v);
    seg[rt] = min(seg[rt << 1] + lazy[rt << 1], seg[rt << 1 | 1] + lazy[rt << 1 | 1]);
}

int get_min() {
    return seg[1] + lazy[1];
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        vector<pll> srt;
        string ans = "";
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; ++i)
            cin >> arr[i], srt.pb(pll(arr[i], -1));
        for (int i = 1; i <= m; ++i) {
            int k;
            sum[i] = 0;
            cin >> k, brr[i].resize(k);
            for (int j = 0; j < k; ++j)
                cin >> brr[i][j], sum[i] += brr[i][j];
            srt.pb(pll(sum[i], k));
        }
        sort(ALL(srt), [](pll a, pll b) {
            int fa = 0, fb = 0;
            if (a.Y == -1) a.Y = 1, fa = 1;
            if (b.Y == -1) b.Y = 1, fb = 1;
            if (a.X * b.Y == b.X * a.Y)
                return fa > fb;
            return a.X * b.Y > b.X * a.Y;
        });
        int nw = 0;
        for (int i = 0; i < SZ(srt); ++i) {
            if (srt[i].Y == -1)
                ++nw;
            else
                --nw;
            num[i] = nw;
        }
        build(0, SZ(srt) - 1, 1);
        for (int i = 1; i <= m; ++i) {
            int pl = lower_bound(ALL(srt), pll(sum[i], SZ(brr[i])), [](pll a, pll b) {
                int fa = 0;
                if (a.Y == -1) a.Y = 1, fa = 1;
                if (a.X * b.Y == b.X * a.Y)
                    return fa > 0;
                return a.X * b.Y > b.X * a.Y;
            }) - srt.begin();
            for (int j : brr[i]) {
                int npl = lower_bound(ALL(srt), pll(sum[i] - j, SZ(brr[i]) - 1), [](pll a, pll b) {
                    int fa = 0;
                    if (a.Y == -1) a.Y = 1, fa = 1;
                    if (a.X * b.Y == b.X * a.Y)
                        return fa > 0;
                    return a.X * b.Y > b.X * a.Y;
                }) - srt.begin();
                if (npl == 0) {
                    ans.pb('0');
                    continue;
                }
                if (pl + 1 < npl)
                    modify(pl, npl - 2, 0, SZ(srt) - 1, 1, 1);
                else if (npl < pl)
                    modify(npl - 1, pl - 1, 0, SZ(srt) - 1, 1, -1);
                if (get_min() < 0)
                    ans.pb('0');
                else
                    ans.pb('1');
                if (pl + 1 < npl)
                    modify(pl, npl - 2, 0, SZ(srt) - 1, 1, -1);
                else if (npl < pl)
                    modify(npl - 1, pl - 1, 0, SZ(srt) - 1, 1, 1);
            }
        }
        cout << ans << "\n";
    }
}