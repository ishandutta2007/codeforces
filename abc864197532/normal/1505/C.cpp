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
const int mod = 998244353, abc = 864197532, N = 200005, K = 111;

vector <int> f = {1, 2, 3, 5, 8, 13, 21, 34, 55, 89};

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    bool is = true;
    for (int i = 2; i < s.length(); ++i) {
        is &= (s[i - 2] - 'A' + s[i - 1] - 'A') % 26 == s[i] - 'A';
    }
    cout << (is ? "YES\n" : "NO\n");
}