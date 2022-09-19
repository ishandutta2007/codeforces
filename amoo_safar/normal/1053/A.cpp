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

const ll MOD = (ll) 998244353ll;
const ll MAXN = (ll) 1e5 + 10;
const ll INF = (ll) 9223372036854775;


int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n,m,k;
    cin >> n >> m >> k;
    if((2*n*m)%k!= 0){
        cout << "NO";
        return 0;
    }
    ll g = (2*n*m)/k;
    ll f = __gcd(n,k);
    ll ff = k/f;
    ll fff = n/f;
    ll ffff = (2*m)/ff;
    if(ff == 1){
        cout << "YES\n0 0\n" << 2*fff << " 0\n0 " << ffff/2;
    }
    else {
        cout << "YES\n0 0\n" << fff << " 0\n0 " << ffff;
    }

    return 0;

}
/*
1000000000 1000000000 2
*/