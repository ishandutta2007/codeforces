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
const int mod = 1e9 + 7, abc = 864197532, N = 200087, logN = 17, K = 333;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int ans = 0, n;
    cin >> n;
    vector <vector <int>> a(n);
    for (int i = 0, sz; i < n; ++i) {
        cin >> sz;
        a[i].resize(sz);
        for (int &j : a[i]) cin >> j;
        sort(all(a[i]));
    }
    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n, k = (i + n - 1) % n;
        for (int t = 0; t < a[i].size() - 1; ++t) {
            int l = a[i][t], r = a[i][t + 1];
            if (lower_bound(all(a[j]), r) - lower_bound(all(a[j]), l) != lower_bound(all(a[k]), r) - lower_bound(all(a[k]), l)) {
                ans++;
            }
        }
    }
    cout << ans << endl;
}