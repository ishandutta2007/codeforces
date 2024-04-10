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
    /*
     pre[r] - pre[l] >= (pre[r - 1] - pre[l + 1) * 2
     pre[r] - pre[r - 1] * 2 >= pre[l] - pre[l + 1] * 2;
      */
    lli ans = 0;
    int n;
    cin >> n;
    vector <lli> a(n), pre(n + 1, 0);
    fop (i,0,n) cin >> a[i], pre[i + 1] = pre[i] + a[i];
    set <pair <lli, int>> s;
    fop (i,2,n + 1) s.insert({pre[i] - pre[i - 1] * 2, i});
    fop (i,0,n) {
        if (i + 2 <= n) {
            s.erase({pre[i + 2] - pre[i + 1] * 2, i + 2});
        }
        for (auto it = s.lower_bound({pre[i] - pre[i + 1] * 2, -1}); it != s.end(); ++it) {
            lli v;
            int j;
            tie(v, j) = *it;
            if ((a[i] ^ a[j - 1]) == pre[j - 1] - pre[i + 1]) {
                ans++;
            }
        }
    }
    cout << ans << endl;
}