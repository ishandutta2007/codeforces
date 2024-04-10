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
const int mod = 1e9 + 7, x = 864197532, N = 1001, logN = 18, K = 500, C = 1e9;

void solve() {
    int n;
    cin >> n;
    vector <int> a(n);
    vector <int> p[n];
    fop (i,0,n) cin >> a[i], --a[i], p[a[i]].pb(i);
    vector <int> ans(n, 0);
    bool is = true;
    fop (i,0,n) is &= p[i].size() == 1;
    if (is) ans[0] = 1;
    int l = 0, r = n - 1;
    fop (i,0,n) {
        if (p[i].empty()) break;
        ans[n - i - 1] = 1;
        if (p[i].size() != 1) break;
        if (a[l] == i) l++;
        else if (a[r] == i) r--;
        else break;
    }
    fop (i,0,n) cout << ans[i];
    cout << endl;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}