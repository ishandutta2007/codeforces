#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

const int MN = 2005;

int n, m, k;
ll ans,mod=1e9+7;
ll fastpow(ll a,ll b){
    ll ans=1;
    for(ll i=1;i<=b;i<<=1){
        if(b&i)ans=ans*a%mod;
        a=a*a%mod;
    }
    return ans;
}

int main() {
    boost();

    cin >> n >> m >> k;
    if (k == 1) ans = fastpow(m, n);
    else if (k < n) {
        if (k % 2) {
            ans = m * m;
        } else {
            ans = m;
        }
    } else if (k == n) {
        ll len = (n + 1) / 2;
        ans = fastpow(m, len);
    } else {
        ans = fastpow(m, n);
    }
    printf("%lld\n", ans % mod);

    return 0;
}