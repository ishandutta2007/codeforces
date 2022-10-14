#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << endl;\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<lli,lli>
#define ld long double;
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 500005, logN = 18, K = 600, C = 100, M = 1e9;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    set <pii> s;
    vector <int> a(n), p(n);
    fop (i,0,n) cin >> a[i], s.insert({i, --a[i]}), p[a[i]] = i;
    vector <int> ans(n, -1);
    int now = 0, cur = n - 1;
    while (s.size()) {
        while (~ans[p[cur]]) --cur;
        auto it = s.lower_bound({p[cur], cur});
        int t = 0;
        vector <int> group = {it->X};
        for (auto it1 = it; t <= k && it1 != s.end(); ++it1, ++t) {
            if (it1 == it) continue;
            group.pb(it1->X);
        }
        t = 0;
        for (auto it1 = it; t <= k; --it1, ++t) {
            if (it == s.begin()) break;
            if (it1 == it) continue;
            group.pb(it1->X);
            if (it1 == s.begin()) break;
        }
        for (int i : group) {
            s.erase({i, a[i]});
            ans[i] = now + 1;
        }
        now ^= 1;
    }
    fop (i,0,n) cout << ans[i];
}