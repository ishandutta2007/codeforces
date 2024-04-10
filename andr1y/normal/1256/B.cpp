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
#define N 105
#define INF 101111111111111
using namespace std;
ll a[N];
ll n;
ll run_from(ll off){
	ll minv = INF, minp = -1;
	if(off >= n) return -1;
	for(ll i =off;i<n;i++) if(a[i] < minv) minv = a[i], minp = i;
	ll changed = 0;
	for(ll i = minp-1;i>=off;i--, changed++) swap(a[i], a[i+1]);
	if(changed > 0) return minp;
	else return minp+1;
}
int main(){
	FAST;
	ll q;
	cin >> q;
	while(q--){
		cin >> n;
		for(ll i =0;i<n;i++) cin >> a[i];
			ll x = 0;
		while((x = run_from(x)) != -1);
		for(ll i =0;i<n;i++) cout << a[i] << " ";
		cout << endl;
	}
}