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
const int mod = 998244353, abc = 864197532, N = 200008, logN = 18, K = 500, C = 100;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int testcase;
    cin >> testcase;
    while (testcase--) {
        int n;
        cin >> n;
        string s[n], t;
        for (int i = 0; i < n; ++i) cin >> s[i];
        vector <vector <int>> a(n, vector <int>(n, 0));
        for (int i = 0; i < n; ++i) {
            cin >> t;
            for (int j = 0; j < n; ++j) a[i][j] = s[i][j] ^ t[j];
        }
        bool ans = false;
        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            for (int j = 0; j < n; ++j) cnt += a[i][j];
            if (cnt == 0 || cnt == n) {
                if (i == n - 1) ans = true;
                continue;
            }
            for (int j = 0; j < n; ++j) if (a[i][j]) {
                for (int k = 0; k < n; ++k) {
                    a[k][j] ^= 1;
                }
            }
            bool is = true;
            for (int j = 0; j < n; ++j) {
                cnt = 0;
                for (int k = 0; k < n; ++k) {
                    cnt += a[j][k];
                }
                is &= (cnt == 0 || cnt == n);
            }
            if (is) ans = true;
            break;
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
}