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
const int mod = 1e9 + 7, abc = 864197532, Doludu = 123, N = 250001, logN = 18;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, a, b, c, d, e, f;
    cin >> n >> a >> b >> c >> d >> e >> f;
    for (int i = b; i >= a; --i) {
        int re = n - i;
        if (c + e <= re && re <= d + f) {
            cout << i << ' ';
            for (int j = d; j >= c; --j) {
                int ree = re - j;
                if (e <= ree && ree <= f) {
                    cout << j << ' ' << ree << endl;
                    return 0;
                }
            }
        }
    }
}