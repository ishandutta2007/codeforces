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
const int mod = 998244353, abc = 864197532, N = 400008, logN = 17, K = 333;

int mask[30];

bool add(int x) {
    for (int i = 29; ~i; --i) if (x & (1 << i)) {
        if (!mask[i]) {
            mask[i] = x;
            return true;
        }
        x ^= mask[i];
    }
    return false;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, ans = 0, xorr = 0;
    cin >> n;
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        xorr ^= x;
        ans += add(x);
    }
    if (xorr) cout << ans << endl;
    else cout << -1 << endl;
}