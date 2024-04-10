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
const ll MAXN = (ll) 2e5 + 10;
const ll INF = (ll) 9223372036854775;

pll a[MAXN];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n, h;
    cin >> n >> h;
    for(int i = 0;i<n;i++){
        cin >> a[i].F >> a[i].S;
    }
    a[n] = mp(INF, INF);
    ll m = h;
    ll c = 0;
    ll p1 = 0;
    ll p2 = 0;
    ll h2 = h;
    while(p1 < n){

        while((p2 < n )and(h2 > 0)){
            h2 -= (a[p2+1].F - a[p2].S);
            c += (a[p2].S - a[p2].F);
            p2++;
        }

        m = max(m, c+h);
        //debug(c);
        c -= (a[p1].S - a[p1].F);
        h2 += (a[p1+1].F - a[p1].S);
        //debug(h2);
        p1++;
    }
    cout << m;
    return 0;

}