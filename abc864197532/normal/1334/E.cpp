#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<lli,lli>
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
    lli d, u, v, q;
    cin >> d >> q;
    vector <lli> prime, frac(200), fracp(200);
    for (lli i = 2; i * i <= d; ++i) {
        if (d % i == 0) {
            prime.pb(i);
            while (d % i == 0) d /= i;
        }
    }
    if (d > 1) prime.pb(d);
    frac[0] = fracp[0] = 1;
    fop (i,1,200) frac[i] = frac[i - 1] * i % mod;
    fop (i,1,200) fracp[i] = modpow(frac[i], mod - 2);
    while (q--) {
        cin >> u >> v;
        lli k = __gcd(u, v);
        u /= k; v /= k;
        auto f = [&](lli x) {
            int all = 0;
            vector <int> ttmp;
            for (lli i : prime) {
                int tmp = 0;
                while (x % i == 0) x /= i, tmp++;
                ttmp.pb(tmp);
                all += tmp;
                //cout << tmp << ' ';
            }
            lli ans = frac[all];
            for (int i : ttmp) ans = ans * fracp[i] % mod;
            return ans;
        };
        cout << f(u) * f(v) % mod << '\n';
    }
}