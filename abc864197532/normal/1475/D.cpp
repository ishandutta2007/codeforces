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
    cout << '\n';\
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
const int mod = 1e9 + 7, abc = 864197532, N = 200008, logN = 18, K = 500;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int testcase;
    cin >> testcase;
    while (testcase--) {
        int n, m;
        cin >> n >> m;
        vector <int> a[2], b(n);
        for (int i = 0; i < n; ++i) cin >> b[i];
        for (int i = 0, x; i < n; ++i) cin >> x, a[--x].pb(b[i]);
        sort(rall(a[0])); sort(rall(a[1]));
        vector <lli> pre1 = {0}, pre2 = {0};
        for (int i : a[0]) pre1.pb(pre1.back() + i);
        for (int i : a[1]) pre2.pb(pre2.back() + i);
        int ans = 2 * n + 1;
        for (int i = 0; i < pre1.size(); ++i) {
            int j = lower_bound(all(pre2), m - pre1[i]) - pre2.begin();
            if (j != pre2.size()) ans = min(ans, j * 2 + i);
        }
        if (ans == 2 * n + 1) ans = -1;
        cout << ans << endl;
    }
}