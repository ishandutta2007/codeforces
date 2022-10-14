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
#define ld long double
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 100005, logN = 18, K = 600, C = 100, M = 1e9;

void solve() {
    int n, m;
    cin >> n >> m;
    vector <int> p(n);
    fop (i,0,n) cin >> p[i], --p[i];
    int suf = 0;
    FOP (i,n,0) {
        if (p[i] ^ i) {
            suf = i + 1;
            break;
        }
    }
    ld ans = 1.0, one = 1.0;
    fop (i,0,m) {
        int k;
        ld x;
        cin >> k >> x;
        if (k >= suf) {
            ans = ans * (one - x);
        }
    }
    if (suf == 0) {
        cout << fixed << setprecision(10) << 1.0 << endl;
        return;
    }
    cout << fixed << setprecision(10) << one - ans << endl;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}