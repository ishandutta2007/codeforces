#include <bits/stdc++.h>
using namespace std;
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
const int mod = 1e9 + 7, x = 864197532, N = 10008, logN = 18, K = 500, C = 100;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector <int> a(n), b;
    fop (i,0,n) cin >> a[i];
    sort(rall(a));
    lli ans = 0, cur = 0;
    fop (i,0,n) {
        ans += cur;
        cur += a[i];
        if (cur < 0) {
            b.pb(cur);
            while ((++i) < n) b.pb(a[i]);
        }
    }
    reverse(all(b));
    for (int i = 0; i < b.size(); ++i) {
        ans += 1ll * b[i] * (i / (k + 1));
    }

    cout << ans << endl;
}