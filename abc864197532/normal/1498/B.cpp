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
const int mod = 1e9 + 7, abc = 864197532, N = 100000, K = 111;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, w;
        cin >> n >> w;
        vector <int> cnt(21, 0);
        for (int i = 0, x; i < n; ++i) cin >> x, cnt[__lg(x)]++;
        int ans = 0;
        while (accumulate(all(cnt), 0)) {
            ans++;
            int now = w;
            for (int i = 20; ~i; --i) {
                while (now >= (1 << i) && cnt[i]) {
                    cnt[i]--;
                    now -= (1 << i);
                }
            }
        }
        cout << ans << endl;
    }
}