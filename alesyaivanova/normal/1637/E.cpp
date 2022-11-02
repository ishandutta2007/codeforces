#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double
#define all(x) x.begin(), x.end()
#define uniq(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())

const int maxn = 3e5 + 9;
//const int T = 500;
vector<int> g[maxn];
vector<int> x;
int a[maxn];
int cnt[maxn];
int n, m;
int inf = 1e18;

void solve() {
    cin >> n >> m;
    x.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        x[i] = a[i];
        cnt[i] = 0;
    }
    uniq(x);
    for (int i = 0; i < n; i++) {
        int t = lower_bound(all(x), a[i]) - x.begin();
        cnt[t]++;
    }
    n = x.size();
    map<int, vector<int>> by_cnt;
    for (int i = n - 1; i >= 0; i--) {
        by_cnt[cnt[i]].pb(i);
    }
//    for (auto u : by_cnt) {
//        cerr << u.ff << ": ";
//        for (int y : u.ss) {
//            cerr << y << " ";
//        }
//        cerr << "\n";
//    }
    for (int i = 0; i < m; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        v1 = lower_bound(all(x), v1) - x.begin();
        v2 = lower_bound(all(x), v2) - x.begin();
        g[v1].pb(v2);
        g[v2].pb(v1);
    }
    for (int i = 0; i < n; i++) {
        g[i].pb(i);
        sort(g[i].rbegin(), g[i].rend());
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
//        if (cnt[i] >= T) {
//            for (int e = 0; e < n; e++) {
//                if (i == e) {
//                    continue;
//                }
//                if (ans < (cnt[i] + cnt[e]) * (x[i] + x[e])) {
//                    ans = (cnt[i] + cnt[e]) * (x[i] + x[e]);
//                }
//            }
//        } else {
            map<int, vector<int>> cur_by_cnt;
            for (int to : g[i]) {
                cur_by_cnt[cnt[to]].pb(to);
            }
//            cur_by_cnt[cnt[i]].pb(i);
//            sort(all(cur_by_cnt[i]));
//            reverse(all(cur_by_cnt[cnt[i]]));
//            cerr << i << "!!!\n";
//            for (auto u : cur_by_cnt) {
//                cerr << u.ff << ": ";
//                for (int y : u.ss) {
//                    cerr << y << " ";
//                }
//                cerr << "\n";
//            }
            auto j = cur_by_cnt.begin();
            for (auto u = by_cnt.begin(); u != by_cnt.end(); u++) {
                if (j == cur_by_cnt.end() || j->ff != u->ff) {
                    int e = u->ss[0];
//                    if (e == i) {
//                        if (u->ss.size() >= 2) {
//                            e = u->ss[1];
//                        } else {
//                            continue;
//                        }
//                    }
                    if (ans < (cnt[i] + cnt[e]) * (x[i] + x[e])) {
                        ans = (cnt[i] + cnt[e]) * (x[i] + x[e]);
                    }
                } else {
                    int w = 0;
                    for (int y = 0; y < u->ss.size(); y++) {
                        if (w < j->ss.size() && j->ss[w] == u->ss[y]) {
                            w++;
                            continue;
                        }
                        int e = u->ss[y];
//                        if (e == i) {
//                            continue;
//                        }
                        if (ans < (cnt[i] + cnt[e]) * (x[i] + x[e])) {
                            ans = (cnt[i] + cnt[e]) * (x[i] + x[e]);
                        }
                        break;
                    }
                    j++;
                }
            }
//        }
    }
    cout << ans << "\n";
    for (int i = 0; i < n; i++) {
        g[i] = {};
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

/*
1
6 1
6 3 6 7 3 3
3 6
*/