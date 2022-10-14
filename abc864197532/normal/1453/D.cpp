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
const int mod = 1e9 + 7, x = 864197532, N = 1001, logN = 18, K = 500, C = 100;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        lli n;
        cin >> n;
        if (n & 1) {
            cout << -1 << endl;
        } else {
            n >>= 1;
            vector <int> ans;
            FOP (i,60,1) {
                lli a = (1ll << i) - 1;
                while (n >= a) {
                    n -= a;
                    ans.pb(i);
                }
            }
            int re = 0;
            for (int i : ans) re += i;
            cout << re << endl;
            for (int i : ans) {
                cout << 1 << ' ';
                fop (j,1,i) cout << 0 << ' ';
            }
            cout << endl;
        }
    }
}