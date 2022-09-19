#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define debug(x)  cerr << #x << " = " << x << endl
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld Pi = 3.14159265359;

const ll MOD = (ll) 1e9 + 7;
const ll MAXN = (ll) 3e5 + 10;
const ll INF = (ll) 3e18;
const ld EPS = (ld) 1e-8;



ll dp[19][4];



ll cl(ll n, ll m){
    //debug(n);
    //debug(m);
    //if(m == 0) return 1ll;
    if(n == 0) return 1;
    ll ans = 0;
    ll p = (ll)1e18;
    ll t = 18;
    while(p > 0){
        if(n/p != 0){
            if(m == 0){
                return cl(p - 1ll, m);
            }
            ll d = n/p;
            ans = cl(n%p,m-1);
            for(int i =0;i<=m-1;i++){
                ans += (d-1)*dp[t][i];
            }
            for(int i =0;i<=m;i++){
                ans += dp[t][i];
            }
            return ans;
            //return cl(n%p,m-1) + (d-1)*cl(p - 1ll,m -  1) + cl(p - 1ll, m);
            //return cl(n%p,m-1) + (d-1)*dp[t][m -  1] + dp[t][m];
        }
        p/=10;
        t--;
    }
}



int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    dp[0][0] = 1;
    dp[1][1] = 9;
    dp[1][0] = 1;
    for(int i = 2;i<19;i++){
        dp[i][0] = dp[i-1][0];
        dp[i][1] = dp[i-1][1] + 9 * dp[i-1][0];
        dp[i][2] = dp[i-1][2] + 9 * dp[i-1][1];
        dp[i][3] = dp[i-1][3] + 9 * dp[i-1][2];
    }

    //debug(cl(1000,3));
    //debug(cl(89,3));

    ll T,r, l, f;

    cin >> T;
    while(T--){
        cin >> l >> r;
        f = cl(r,3) - cl(l, 3);
        ll c = 0;
        while(l > 0){
            if(l%10 != 0) c++;
            l/=10;
        }
        if(c <= 3) cout << f + 1 << endl;
        else cout << f << endl;
    }
    return 0;
}

/*
*/