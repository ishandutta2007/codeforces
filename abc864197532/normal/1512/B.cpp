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
const int mod = 1e9 + 7, abc = 864197532, N = 300001, K = 111;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s[n];
        for (int i = 0; i < n; ++i) cin >> s[i];
        vector <int> row(n, 0), col(n, 0);
        for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (s[i][j] == '*') {
            row[i]++;
            col[j]++;
        }
        bool is = true;
        for (int i = 0; i < n; ++i) if (row[i] == 2) {
            int k = i == n - 1 ? i - 1 : i + 1;
            for (int j = 0; j < n; ++j) if (s[i][j] == '*') s[k][j] = '*';
            is = false;
        }
        for (int j = 0; j < n; ++j) if (col[j] == 2) {
            int k = j == n - 1 ? j - 1 : j + 1;
            for (int i = 0; i < n; ++i) if (s[i][j] == '*') s[i][k] = '*';
            is = false;
        }
        if (is) {
            for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (row[i] == 1 && col[j] == 1) {
                s[i][j] = '*';
            }
        }
        for (int i = 0; i < n; ++i) cout << s[i] << endl;
    }
}