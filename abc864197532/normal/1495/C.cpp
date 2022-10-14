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
const int mod = 1e9 + 7, abc = 864197532, N = 504, K = 111;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        string s[n];
        for (int i = 0; i < n; ++i) cin >> s[i];
        int st = (n % 3 ? 0 : 1);
        for (int i = st; i < n; i += 3) {
            s[i] = string(m, 'X');
        }
        for (int i = st + 1; i + 1 < n; i += 3) {
            if (count(all(s[i]), 'X')) {
                for (int j = 0; j < m; ++j) {
                    if (s[i][j] == 'X') {
                        s[i + 1][j] = 'X';
                        break;
                    }
                }
            } else if (count(all(s[i + 1]), 'X')) {
                for (int j = 0; j < m; ++j) {
                    if (s[i + 1][j] == 'X') {
                        s[i][j] = 'X';
                        break;
                    }
                }
            } else {
                s[i][0] = s[i + 1][0] = 'X';
            }
        }
        for (int i = 0; i < n; ++i) cout << s[i] << endl;
    }
}