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
#define N 1005
#define INF 101111111111111
using namespace std;
ll a[N], c[N], s[N];
int main(){
	FAST;
	ll q;
	cin >> q;
	while(q--){
		ll n;
		cin >> n;
		for(ll i =0;i<=n;i++) c[i] = 0;
		for(ll i =0;i<n;i++) {cin >> a[i]; c[a[i]]++;}
		for(ll i = n;i>0;i--){
			s[i] = c[i];
			if(i != n) s[i] += s[i+1];
		}
		ll maxres = 1;
		for(ll i = 1;i<=n;i++){
			maxres = max(maxres, min(i, s[i]));
		}
		cout << maxres << endl;
	}
}