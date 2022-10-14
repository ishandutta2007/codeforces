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
#define ld long double;
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 500005, logN = 18, K = 600, C = 100, M = 1e9;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n);
    fop (i,0,n) cin >> a[i];
    sort(all(a));
    a.resize(unique(all(a)) - a.begin());
    if (a.size() > 3) cout << -1 << endl;
    else if (a.size() == 3) {
        if (a[2] - a[1] == a[1] - a[0]) cout << a[1] - a[0] << endl;
        else cout << -1 << endl;
    } else if (a.size() == 2) {
        if ((a[0] ^ a[1]) & 1) cout << a[1] - a[0] << endl;
        else cout << (a[1] - a[0]) / 2 << endl;
    } else {
        cout << 0 << endl;
    }
}