#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define test(x) cout << #x << ' ' << x << endl;
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
const int mod = 1e9 + 7, abc = 864197532, N = 300001, logN = 17;

lli modpow(lli a, lli b) {
    lli ans = 1;
    for (; b; b >>= 1, a = a * a % mod) {
        if (b & 1) ans = ans * a % mod;
    }
    return ans;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    lli a, b, x, n;
    cin >> a >> b >> n >> x;
    if (a == 1) cout << (x + n % mod * b) % mod << endl;
    else {
        lli r = modpow(a, n);
        cout << (r * x % mod + b * (r - 1) % mod * modpow(a - 1, mod - 2)) % mod << endl;
    }
}