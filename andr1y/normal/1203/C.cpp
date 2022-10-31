#include <bits/stdc++.h>
#define ld long double
#define ll long long
#define ull unsigned ll
#define pll pair<ll, ll>
#define itr(a) begin(a), end(a)
#define pb push_back
#define x first
#define y second
#define endl '\n'
#define FAST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FILES(namein, nameout) freopen(namein, "r", stdin); freopen(nameout, "w", stdout);
#define M 1000000007
#define N 400000
#define INF 101111111111111
using namespace std;
ll a[N];
main(){
    FAST;
    ll n;
    cin >> n;
    ll gc = 0;
    for(ll i=0;i<n;i++){
    	cin >> a[i];
    	gc = __gcd(gc, a[i]);
    }
    ll res = 1, on = gc;
    for(ll i = 2;i*i<=on;i++){
    	ll divc = 0;
    	while(on%i==0){
    		on/=i;
    		divc++;
    	}
    	res *= divc+1;
    }
    if(on != 1) res*=2;
    cout << res;
}