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
const int mod = 1e9 + 7, abc = 864197532, N = 1001, K = 111;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k = 100000;
    cin >> n >> m;
    vector <int> ans(m + 1, -1);
    ans[0] = 0;
    for (int num = 1; num <= n; ++num) {
        lli t, x, y;
        cin >> t >> x >> y;
        vector <int> ty(m + 1, 0);
        if (t == 1) {
            for (int i = 0; i < m; ++i) if (ans[i] != -1 && ty[i] < y) {
                int ni = i + (x + k - 1) / k;
                if (ni <= m && ans[ni] == -1) ans[ni] = num, ty[ni] = ty[i] + 1;
            }
        } else {
            for (int i = 0; i < m; ++i) if (ans[i] != -1 && ty[i] < y) {
                lli ni = (1ll * i * x + k - 1) / k;
                if (ni <= m && ans[ni] == -1) ans[ni] = num, ty[ni] = ty[i] + 1;
            }
        }
    }
    for (int i = 1; i <= m; ++i) cout << ans[i] << " \n"[i == m];
}