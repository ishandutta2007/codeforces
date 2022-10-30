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
#define N 200
#define INF 101111111111111
using namespace std;
ll a[N];
main(){
    FAST;
    ll Q;
    cin >> Q;
    while(Q--){
    	ll n, fp, fv;
    	cin >> n;
    	for(ll i =0;i<n;i++){
    		cin >> a[i];
    		if(a[i] == 1) fp = i;
    		if(a[i] == n) fv = i;
    	}
    	bool can = true;
    	ll pp = 0;
    	for(ll i = 0;i<n;i++){
    		ll p = (i+fp)%n;
    		if(a[p]-pp != 1) can = false;
    		pp = a[p];
    	}
    	if(can){
    		cout << "YES" << endl;
    		continue;
    	}
    	can = true;
    	pp = n+1;
    	for(ll i = 0;i<n;i++){
    		ll p = (i+fv)%n;
    		if(pp - a[p]!= 1) can = false;
    		pp = a[p];
    	}
    	if(can){
    		cout << "YES" << endl;
    	}else{
    		cout << "NO" << endl;
    	}
    }
}