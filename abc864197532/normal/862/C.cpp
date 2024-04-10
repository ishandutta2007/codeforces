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
const int mod = 998244353, x = 864197532, N = 100008, logN = 18, K = 500, C = 100;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x, C = 200000;
    cin >> n >> x;
    if (n == 2 && x == 0) return cout << "NO\n", 0;
    if (n % 4 == 0) {
        cout << "YES\n";
        if (x == 1) {
            for (int i = 3; i < n; ++i) cout << C + i << ' ';
            cout << C + 1 << ' ' << x << ' ' << 2 << endl;
        } else {
            for (int i = 2; i < n; ++i) cout << C + i << ' ';
            cout << 1 << ' ' << x << endl;
        }
    } else if (n % 4 == 1) {
        cout << "YES\n";
        for (int i = 0; i < n - 1; ++i) cout << C + i << ' ';
        cout << x << endl;
    } else if (n % 4 == 2) {
        cout << "YES\n";
        if (x != 0) {
            for (int i = 0; i < n - 2; ++i) cout << C + i << ' ';
            cout << 0 << ' ' << x << endl;
        } else {
            for (int i = 0; i < n - 6; ++i) cout << C + i << ' ';
            cout << "1 2 3 4 8 12\n";
        }
    } else {
        cout << "YES\n";
        for (int i = 0; i < n - 3; ++i) cout << C + i << ' ';
        if (x == 0) cout << "1 2 3\n";
        else if (x == 1) cout << "0 2 3\n";
        else cout << 0 << ' ' << 1 << ' ' << (x ^ 1) << endl;
    }
}