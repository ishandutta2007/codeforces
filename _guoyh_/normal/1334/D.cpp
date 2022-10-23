# include <cmath>
# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
int t;
ll n, l, r;
ll work(ll x){
    if (x == n * (n - 1) + 1) return 1;
    ll f = (ll)(ceil((2.0 * n - 1 - sqrt(4 * n * n - 4 * n + 1 - 4 * x)) / 2) + 1e-8);
    ll g = x - (2 * n - f) * (f - 1);
    if (g & 1) return f;
    else return g / 2 + f;
}
int main(){
    scanf("%d", &t);
    while (t--){
        scanf("%lld%lld%lld", &n, &l, &r);
        for (ll i = l; i <= r; i++) printf("%lld ", work(i));
        putchar('\n');
    }
    return 0;
}