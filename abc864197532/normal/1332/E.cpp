#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define X first
#define Y second
const int mod = 998244353;

lli modpow(lli a, lli b) {
    lli ans = 1;
    for (; b; a = a * a % mod, b >>= 1) {
        if (b & 1) ans = ans * a % mod;
    }
    return ans;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    lli n, m, l, r;
    cin >> n >> m >> l >> r;
    lli ans = modpow(r - l + 1, n * m);
    if ((n != 1 and n & 1) and (m != 1 and m & 1)) {
        cout << ans << '\n';
    } else {
        if ((r & 1) == (l & 1)) ans++;
        cout << ans % mod * modpow(2, mod - 2) % mod << '\n';
    }
}