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
const int mod = 1e9 + 7, abc = 864197532, N = 1001, K = 111;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector <int> d(n + 1);
    for (int i = 1; i <= n; ++i) cin >> d[i];
    vector <pair<int, pii>> v;
    for (int i = 1; i <= n; ++i) for (int j = i + 1; j <= n; ++j) {
        v.pb(mp(abs(d[i] - d[j]), mp(i, j)));
    }
    sort(rall(v));
    for (auto A : v) {
        int a = A.X, x, y;
        tie(x, y) = A.Y;
        if (d[x] < d[y]) swap(x, y);
        cout << "? " << x << ' ' << y << endl;
        string s;
        cin >> s;
        if (s == "Yes") {
            cout << "! " << x << ' ' << y << endl;
            return 0;
        }
    }
    cout << "! 0 0" << endl;
    return 0;
}