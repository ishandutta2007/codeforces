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


int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n;
    cin >> n;
    ll l = 2;
    ll v;
    for(ll i = 1;i < n+1;i++){
        if(i == 1){
            cout << 2 << endl;
            continue;
        }
        cout << i*(i+1)*(i+1) - (i-1) << endl;
        //v = ((ll) i)*(i-1ll)*i*(i-1ll);
        //debug(v);
        //cout << (v - l)/(i-1) << endl;
        //l = i*(i - 1);
        //debug(l);
    }
    return 0;
}