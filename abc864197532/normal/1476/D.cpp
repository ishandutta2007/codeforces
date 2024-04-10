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
const int mod = 998244353, abc = 864197532, N = 500087, logN = 20, K = 333;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        vector <int> dp0(n, 0), dp1(n, 0);
        for (int i = 0; i < n; ++i) {
            if (!i || s[i] == s[i - 1]) dp0[i] = 1;
            else dp0[i] = dp0[i - 1] + 1;
        }
        for (int i = n - 1; ~i; --i) {
            if (i == n - 1 || s[i] == s[i + 1]) dp1[i] = 1;
            else dp1[i] = dp1[i + 1] + 1;
        }
        for (int i = 0; i <= n; ++i) {
            if (i == 0) cout << (s[i] == 'R' ? dp1[i] : 0) + 1 << ' ';
            else if (i == n) cout << (s[i - 1] == 'L' ? dp0[i - 1] : 0) + 1 << ' ';
            else cout << (s[i - 1] == 'L' ? dp0[i - 1] : 0) + (s[i] == 'R' ? dp1[i] : 0) + 1 << ' ';
        }
        cout << endl;
    }
}