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
#define N 200000
#define INF 101111111111111
using namespace std;
ll a[N];
main(){
    FAST;
    ll n;
    cin >> n;
    ll maxp = -1, maxv = -1;
    set<ll> ss;
    for(ll i =0;i<n;i++){
    	cin >> a[i];
    	ss.insert(a[i]);
    	if(a[i] > maxv){
    		maxv = a[i];
    		maxp = i;
    	}
    }
    if(ss.size() != n){
    	cout << "NO";
    }else{
    	bool left = true, right = true;
    	for(ll i = maxp-1;i>=0;i--) left = left & (a[i+1] > a[i]);
    	for(ll i = maxp+1;i<n;i++) right = right & (a[i-1] > a[i]);
    	if(left & right) cout << "YES";
    	else cout << "NO";
    }
}