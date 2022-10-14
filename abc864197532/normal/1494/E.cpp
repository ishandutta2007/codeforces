#include <bits/stdc++.h>
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
const int mod = 1e9 + 7, abc = 864197532, N = 200001, K = 111;

map <pii, char> m1;
set <pii> same_color_pair, dif_color_pair;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    char t, c;
    int u, v;
    while (q--) {
        cin >> t;
        if (t == '?') {
            cin >> u;
            bool ans = false;
            if (!same_color_pair.empty()) ans = true;
            else if (!dif_color_pair.empty() && u & 1) ans = true;
            cout << (ans ? "YES\n" : "NO\n");
        } else if (t == '+') {
            cin >> u >> v >> c, --u, --v;
            m1[{u, v}] = c;
            if (m1.count({v, u})) {
                if (m1[{v, u}] == c) {
                    if (u < v) swap(u, v);
                    same_color_pair.insert({u, v});
                } else {
                    if (u < v) swap(u, v);
                    dif_color_pair.insert({u, v});
                }
            }
        } else {
            cin >> u >> v, --u, --v;
            bool is = false;
            if (m1.count({u, v}) && m1.count({v, u})) {
                is = true;
            }
            m1.erase({u, v});
            if (is) {
                if (u < v) swap(u, v);
                if (same_color_pair.count({u, v})) same_color_pair.erase({u, v});
                if (dif_color_pair.count({u, v})) dif_color_pair.erase({u, v});
            }
        }
    }
}