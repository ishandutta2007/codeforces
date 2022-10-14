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
        int a, b, n;
        cin >> a >> b >> n;
        vector <lli> cnt1(a, 0), cnt2(b, 0);
        for (int i = 0, x; i < n; ++i) cin >> x, cnt1[--x]++;
        for (int i = 0, x; i < n; ++i) cin >> x, cnt2[--x]++;
        lli ans = 1ll * n * (n - 1) / 2;
        for (lli i : cnt1) ans -= i * (i - 1) / 2;
        for (lli i : cnt2) ans -= i * (i - 1) / 2;
        cout << ans << endl;
    }
}