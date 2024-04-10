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
    int t;
    cin >> t;
    while (t--) {
        int n, p, k, x, y;
        string s;
        cin >> n >> p >> k >> s >> x >> y;
        vector <int> cnt(k, 0);
        fop (i,0,n) {
            cnt[i % k] += s[i] == '0';
        }
        int ans = 1 << 30;
        for (int i = 0, j = 0; i + p <= n; ++i) {
            while (j < i + p - 1) cnt[j % k] -= s[j] == '0', j++;
            ans = min(ans, y * i + x * cnt[(p + i - 1) % k]);
        }
        cout << ans << endl;
    }
}