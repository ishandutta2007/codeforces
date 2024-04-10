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
const int mod = 998244353, x = 864197532, N = 200087, logN = 18, K = 500, C = 100;

int dp[1 << 24]{};

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string ss;
    // 0 1 -1 1
    fop (i,0,n) {
        cin >> ss;
        fop (s,0,8) {
            int k = 0;
            fop (j,0,3) if (s & (1 << j)) k |= 1 << ss[j] - 'a';
            int a = __builtin_popcount(s);
            if (a == 1 || a == 3) dp[k]++;
            else if (a == 2) dp[k]--;
        }
    }
    fop (i,0,24) {
        fop (s,0,1 << 24) {
            if (s & (1 << i)) dp[s] += dp[s ^ (1 << i)];
        }
    }
    int ans = 0;
    fop (s,0,1 << 24) {
        ans ^= (dp[s] * dp[s]);
    }
    cout << ans << endl;
}