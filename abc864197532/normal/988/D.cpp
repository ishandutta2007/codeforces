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
const int mod = 1e9 + 7, abc = 864197532, N = 100005, logN = 20, K = 333;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(all(a));
    vector <int> ans;
    auto find = [&](int x) {
        auto it = lower_bound(all(a), x);
        return it != a.end() && *it == x;
    };
    for (int d = 1; d <= 1 << 30; d <<= 1) {
        for (int i = 0; i < n; ++i) {
            vector <int> tmp = {a[i]};
            if (find(a[i] - d)) tmp.pb(a[i] - d);
            if (find(a[i] + d)) tmp.pb(a[i] + d);
            if (ans.size() < tmp.size()) ans = tmp;
        }
        if (d == 1 << 30) break;
    }
    cout << ans.size() << endl;
    printv(ans);
}