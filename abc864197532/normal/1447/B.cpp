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
const int mod = 1e9 + 7, x = 864197532, N = 100087, logN = 18, K = 500, C = 100;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n][m], cntneg = 0, cnt0 = 0;
        int sum = 0;
        fop (i,0,n) fop (j,0,m) {
            cin >> a[i][j];
            if (a[i][j] == 0) cnt0++;
            if (a[i][j] < 0) cntneg++;
            sum += abs(a[i][j]);
        }
        if (cntneg % 2 && cnt0 == 0) {
            int mn = 101;
            fop (i,0,n) fop (j,0,m) mn = min(mn, abs(a[i][j]));
            cout << sum - mn - mn << endl;
        } else {
            cout << sum << endl;
        }
    }
}