#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define test(x) cout << "Line(" << __LINE__ << ") " #x << ' ' << x << endl;
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
const int mod = 1e9 + 7, abc = 864197532, N = 1000087, logN = 17, K = 333;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector <int> p(n);
    for (int i = 0; i < n; ++i) cin >> p[i], --p[i];
    vector <bool> vis(n, false);
    vector <int> cc;
    for (int i = 0; i < n; ++i) if (!vis[i]) {
        int j = i;
        cc.pb(0);
        while (!vis[j]) {
            vis[j] = true;
            j = p[j];
            cc.back()++;
        }
    }
    if (cc.size() == 1) {
        cout << 1ll * n * n << endl;
        return 0;
    }
    sort(all(cc));
    int x = cc.back();
    cc.pop_back();
    cc.back() += x;
    lli ans = 0;
    for (int i : cc) ans += 1ll * i * i;
    cout << ans << endl;
}