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
const int mod = 1e9 + 7, abc = 864197532, N = 1000, logN = 20, K = 333;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        string s;
        cin >> n >> k >> s;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '*') {
                s[i] = 'X';
                ans++;
                break;
            }
        }
        for (int i = n - 1; ~i; --i) {
            if (s[i] == '*') {
                s[i] = 'X';
                ans++;
                break;
            }
        }
        for (int i = 0; i < n; ++i) if (s[i] == 'X') {
            int j;
            for (j = i + 1; j < n; ++j) {
                if (s[j] == 'X') break;
            }
            if (j == n) break;
            if (j - i > k) {
                for (int j = i + k; j > i; --j) {
                    if (s[j] == '*') {
                        s[j] = 'X';
                        ans++;
                        break;
                    }
                }
            }
        }
        cout << ans << endl;
    }
}