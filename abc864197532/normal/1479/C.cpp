#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define test(x) cout << "Line(" << __LINE__ << ") " #x << ' ' << x << endl
#define printv(x) {\
	for (auto i : x) cout << i << ' ';\
	cout << endl;\
}
#define pii pair <int, int>
#define pll pair <lli, lli>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
template<typename A, typename B>
ostream& operator << (ostream& o, pair<A, B> a){
    return o << a.X << ' ' << a.Y;
}
template<typename A, typename B>
istream& operator >> (istream& o, pair<A, B> &a){
    return o >> a.X >> a.Y;
}
const int mod = 1e9 + 7, abc = 864197532, N = 100008, logN = 17, K = 333;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n = 22;
    int l, r;
    cin >> l >> r, r++;
    vector <pair <pii, int>> edge;
    auto add = [&](int u, int v, int w) {
        edge.pb(mp(mp(u, v), w));
    };
    for (int i = 0; i <= 20; ++i) {
        for (int j = 0; j < i; ++j) {
            add(j, i, 1 << max(j - 1, 0));
        }
    }
    if (l == 1) {
        add(0, n - 1, 1);
        l = 2;
    }
    if (l <= r) {
        int d = r - l;
        for (int i = 1; i <= 20; ++i) if (d & (1 << i - 1)) {
            add(i, n - 1, l - 1);
            l += (1 << i - 1);
        }
    }
    cout << "YES\n";
    cout << n << ' ' << edge.size() << endl;
    for (auto A : edge) {
        cout << A.X.X + 1 << ' ' << A.X.Y + 1 << ' ' << A.Y << endl;
    }
}