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
const int mod = 1e9 + 7, abc = 864197532, N = 100001, K = 111;

void solve() {
    string s;
    cin >> s;
    bool is = false;
    for (int i : {-1, 1}) for (int j : {-1, 1}) for (int k : {-1, 1}) {
        int d = 0;
        bool ok = true;
        for (char c : s) {
            if (c == 'A') d += i;
            if (c == 'B') d += j;
            if (c == 'C') d += k;
            if (d < 0) ok = false;
        }
        if (ok && d == 0) is = true;
    }
    cout << (is ? "YES\n" : "NO\n");
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