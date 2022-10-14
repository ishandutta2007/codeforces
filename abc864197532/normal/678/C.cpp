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

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    lli n, a, b, p, q;
    cin >> n >> a >> b >> p >> q;
    lli lcm = a * b / __gcd(a, b);
    lli R = n / a, B = n / b;
    if (p > q) B -= n / lcm;
    else R -= n / lcm;
    cout << R * p + B * q << endl;
}