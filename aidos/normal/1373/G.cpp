#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
const int maxn = (int) 1e6 + 10;
const int mod = (int) 1e9 + 7;
int n, m, k;
int cnt[maxn * 4];
set< pair<int, int> > S;
pair<int, int> t[maxn * 4];
void build(int v, int l, int r) {
    if(l == r) {
        t[v] = make_pair(0, 1);
    } else {
        int mid = (l + r) >> 1;
        build(v * 2, l, mid);
        build(v * 2 + 1, mid+1, r);
        t[v].first = 0;
        t[v].second = t[v*2].second + t[v*2+1].second;
    }
}

void upd(int v, int l, int r, int pos, int val) {
    if(l == r) {
        cnt[v]+=val;
        if(cnt[v] == 0) {
            t[v] = make_pair(0, 1);
        } else {
            t[v] = make_pair(cnt[v] - 1, 0);
        }
    } else {
        int mid = (l + r)/2;
        if(pos <= mid) {
            upd(v * 2, l, mid, pos, val);
        } else {
            upd(v * 2 + 1, mid + 1, r, pos, val);
        }
        int used = min(t[v*2].first, t[v*2 + 1].second);
        t[v].first = t[v * 2 + 1].first + t[v*2].first - used;
        t[v].second = t[v*2].second + t[v*2+1].second - used;
    }
}
int get_free(int v, int tl, int tr, int l, int r, int sum) {
    if(tl > r || tr < l) return -1;
    if(t[v].second <= sum || t[v].first > 0) {
        return -1;
    }
    if(tl == tr) {
        if(t[v].second == 0) return -1;
        return tl;
    }
    int mid = (tl + tr) >> 1;
    int pos = -1;
    if(t[v * 2 + 1].second == tr - mid) {
        pos = get_free(v * 2, tl, mid, l, r, sum);
    }

    if(pos == -1) {
        return get_free(v * 2 + 1, mid + 1, tr, l, r, max(sum - t[v * 2].second, 0) + t[v*2].first);
    }
    return pos;
}
void solve() {
    cin >> n >> k >> m;
    int max_val = 1e6;
    build(1, 1, max_val);
    for(int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        int d = y + abs(x - k);
        if(S.count(make_pair(x, y))) {
            upd(1, 1, max_val, d, -1);
            S.erase(make_pair(x, y));
        } else {
            upd(1, 1, max_val, d, 1);
            S.insert(make_pair(x, y));
        }

        cout << get_free(1, 1, max_val, n + 1, max_val, 0) - n - 1 << "\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}