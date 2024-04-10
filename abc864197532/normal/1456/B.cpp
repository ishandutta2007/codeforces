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
    int n;
    cin >> n;
    vector <int> a(n);
    vector <int> xorr(n + 1, 0);
    fop (i,0,n) cin >> a[i], xorr[i + 1] = xorr[i] ^ a[i];
    if (n > 100) {
        cout << 1 << endl;
        return 0;
    }
    int ans = n + 87;
    fop (i,0,n) fop (k,i,n) fop (j,k + 1,n) {
        if ((xorr[k + 1] ^ xorr[i]) > (xorr[j + 1] ^ xorr[k + 1])) {
            ans = min(ans, j - i - 1);
        }
    }
    if (ans == n + 87) cout << -1 << endl;
    else cout << ans << endl;
    /*
     a, b, c
     a ^ b <= c => a <= b ^ c
     x ^ c <= c
     x = 6;
     110
     c
     00001
     00010
     00100
     00110
     */
}