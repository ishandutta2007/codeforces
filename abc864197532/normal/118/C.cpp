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
const int mod = 1e9 + 7, abc = 864197532, N = 5001, K = 111;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    string s;
    cin >> n >> k >> s;
    string ans;
    int val = -1;
    for (int d = 0; d < 10; ++d) {
        int res = 0, now = k;
        string t = s;
        for (int cd = 0; cd < 10; ++cd) {
            {
                int x = d + cd;
                for (int i = 0; i < n; ++i) if (now && s[i] == '0' + x) {
                        t[i] = d + '0';
                        now--;
                        res += cd;
                    }
            }
            if (cd) {
                int x = d - cd;
                for (int i = n - 1; i >= 0; --i) if (now && s[i] == '0' + x) {
                    t[i] = d + '0';
                    now--;
                    res += cd;
                }
            }
        }
        if (val == -1 || val > res || (val == res && ans > t)) {
            val = res;
            ans = t;
        }
    }
    cout << val << endl << ans << endl;
}