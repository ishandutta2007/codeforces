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
const int mod = 1e9 + 7, x = 864197532, N = 300087, logN = 18, K = 500, C = 1 << 20;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n][m];
        vector <int> v;
        fop (i,0,n) fop (j,0,m) cin >> a[i][j], v.pb(a[i][j]);
        sort(all(v));
        v.resize(unique(all(v)) - v.begin());
        fop (k,0,v.size()) {
            fop (i,0,n) fop (j,0,m) {
                if (a[i][j] == v[k]) {
                    if ((i + j) % 2 == k % 2) {
                        a[i][j]++;
                    }
                }
            }
        }
        fop (i,0,n) fop (j,0,m) cout << a[i][j] << " \n"[j == m - 1];
    }
}