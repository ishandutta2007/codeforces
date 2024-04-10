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
ll a[N], b[N], c[N], d[N], posa[N];
int main(){
	FAST;
	ll q;
	cin >> q;
	while(q--){
		ll n, m;
		cin >> n >> m;
		for(ll i =0;i<n;i++) {cin >> a[i]; posa[a[i]] = i;}
		for(ll j =0;j<m;j++) cin >> b[j];
		for(ll i =0;i<n;i++) c[i] = INF;
		for(ll i =0;i<m;i++) c[posa[b[i]]] = i+1, d[i+1] = posa[b[i]];
		ll mr = 0, res = 0;
		for(ll i =1;i<=m;i++){
			if(d[i] <= mr) res++;
			else{
				res += (d[i]-i+1)*2+1;
				mr = d[i];
			} 
		}
		cout << res << endl;
	}
}