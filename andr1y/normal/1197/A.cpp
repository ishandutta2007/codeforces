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
#define N 100000
#define INF 101111111111111
using namespace std;
ll a[N];
main(){
    FAST;
    ll Q;
    cin >> Q;
    while(Q--){
    	ll n;
    	cin >> n;
    	for(ll i =0;i<n;i++){
    		cin >> a[i];
    	}
    	sort(a, a+n);
    	if(a[n-2] > 1) cout << min(a[n-2]-1, n-2);
    	else cout << 0;
    	cout << endl;
    }
}