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
const int mod = 1e9 + 7, abc = 864197532, Doludu = 123, N = 601, logN = 18;

bitset <200087> dp;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int sum = 0;
    dp.flip(0);
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i], sum += a[i], dp |= dp << a[i];
    if (sum & 1 || !dp[sum / 2]) {
        cout << 0 << endl;
        return 0;
    }
    while (true) {
        for (int i = 0; i < n; ++i) if (a[i] & 1) {
            cout << 1 << endl << i + 1 << endl;
            return 0;
        }
        for (int i = 0; i < n; ++i) a[i] >>= 1;
    }
}