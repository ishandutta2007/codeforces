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
const int mod = 1e9 + 7, abc = 864197532, N = 100005, logN = 20, K = 333;

bool check(string s, string t) {
    for (int i = 0; i <= t.length() - s.length(); ++i) {
        if (t.substr(i, s.length()) == s) return true;
    }
    return false;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector <string> s(n);
    for (int i = 0; i < n; ++i) cin >> s[i];
    sort(all(s), [](string a, string b) {
        return a.length() < b.length();
    });
    bool is = true;
    for (int i = 0; i < n - 1; ++i) is &= check(s[i], s[i + 1]);
    if (is) {
        cout << "YES\n";
        for (string &a : s) cout << a << endl;
    } else {
        cout << "NO\n";
    }
}