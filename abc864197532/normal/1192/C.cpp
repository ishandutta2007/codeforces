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
const int mod = 998244353, abc = 864197532, N = 100087, logN = 17, K = 333;

int pre[62][62][62], way[8] = {1, 4, 6, 12, 4, 12, 12, 24};

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector <string> a[11];
    string s;
    string all_char;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        all_char += s;
        int m = s.length();
        a[m].pb(s);
        reverse(all(s));
        a[m].pb(s);
    }
    sort(all(all_char));
    all_char.resize(unique(all(all_char)) - all_char.begin());
    int m = all_char.length();
    int ans = 0;
    for (int len = 3; len <= 10; ++len) {
        sort(all(a[len]));
        a[len].resize(unique(all(a[len])) - a[len].begin());
        vector <vector <int>> cnt(m, vector <int> (m, 0));
        for (string s : a[len]) {
            cnt[lower_bound(all(all_char), s[0]) - all_char.begin()][lower_bound(all(all_char), s.back()) - all_char.begin()]++;
        }
        for (int i = 0; i < m; ++i) {
            for (int j = i; j < m; ++j) {
                for (int ii = j; ii < m; ++ii) {
                    pre[i][j][ii] = 0;
                    for (int k = 0; k < m; ++k) {
                        pre[i][j][ii] += 1ll * cnt[i][k] * cnt[j][k] * cnt[ii][k] % mod;
                        if (pre[i][j][ii] >= mod) pre[i][j][ii] -= mod;
                    }
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = i; j < m; ++j) {
                for (int ii = j; ii < m; ++ii) {
                    for (int jj = ii; jj < m; ++jj) {
                        int cntt = (i != j) | ((j != ii) << 1) | ((ii != jj) << 2);
                        ans += 1ll * pre[i][j][ii] * pre[i][j][jj] % mod * pre[i][ii][jj] % mod * pre[j][ii][jj] % mod * way[cntt] % mod;
                        if (ans >= mod) ans -= mod;
                    }
                }
            }
        }
    }
    cout << ans << endl;
}