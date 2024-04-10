#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define test(x) cout << #x << ' ' << x << endl
#define printv(x) { \
    for (auto a : x) cout << a << ' '; \
    cout << endl; \
}
#define pii pair<int, int>
#define pll pair<lli, lli>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
const int N = 100, abc = 864197532, K = 700, mod = 1e9 + 7;

lli f(lli n) {
    if (n == 1) return 1;
    lli ans = n;
    for (lli i = 2; i * i <= n; ++i) if (n % i == 0) {
        ans -= ans / i;
        while (n % i == 0) n /= i;
    }
    if (n > 1) ans -= ans / n;
    return ans;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    lli n, k;
    cin >> n >> k;
    k = (k - 1) / 2;
    while (k >= 0) {
        lli nxt = f(n);
        if (n == nxt) break;
        n = nxt;
        --k;
    }
    cout << (n % mod) << endl;
}