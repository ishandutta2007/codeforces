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
const int mod = 1e9 + 7, abc = 864197532, N = 400008, logN = 17, K = 333;

void solve() {
    int n, m;
    cin >> n >> m;
    string s[n];
    for (int i = 0; i < n; ++i) cin >> s[i];
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (s[i][j] == s[j][i]) {
                cout << "YES\n";
                for (int k = 0; k <= m; ++k) {
                    cout << (k & 1 ? i + 1 : j + 1) << " \n"[k == m];
                }
                return;
            } else if (m & 1) {
                cout << "YES\n";
                for (int k = 0; k <= m; ++k) {
                    cout << (k & 1 ? i + 1 : j + 1) << " \n"[k == m];
                }
                return;
            }
        }
    }
    vector <int> outa(n, -1), ina(n, -1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) if (s[i][j] == 'a') {
            outa[i] = j;
            ina[j] = i;
        }
    }
    for (int i = 0; i < n; ++i) if (~ina[i] && ~outa[i]) {
        int j = ina[i], k = outa[i];
        cout << "YES\n";
        if (m % 4 == 0) {
            for (int _i = 0; _i <= m; ++_i) {
                if (_i % 2 == 0) cout << i + 1 << ' ';
                else if (_i % 4 == 1) cout << k + 1 << ' ';
                else if (_i % 4 == 3) cout << j + 1 << ' ';
            }
            cout << endl;
        } else {
            for (int _i = 0; _i <= m; ++_i) {
                if (_i % 2 == 1) cout << i + 1 << ' ';
                else if (_i % 4 == 0) cout << j + 1 << ' ';
                else if (_i % 4 == 2) cout << k + 1 << ' ';
            }
            cout << endl;
        }
        return;
    }
    cout << "NO\n";
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