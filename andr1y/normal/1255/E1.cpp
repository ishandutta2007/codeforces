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
#define N 100005
#define INF 101111111111111
using namespace std;
	ll n;
ll a[N], p[N];
ll check(ll g){
	ll s = -1, ns = 0;
	ll res = 0;
	for(ll i =0;i<n;i++){
		if(a[i]==1) ns++;
		if(ns == 1 && a[i] == 1){
			s = i;
		}
		if(ns == g){
			ll minres = INF;
			ll l = 0, r = 0;
			for(ll j = i;j>s;j--){
				if(a[j] == 1) r += j-s;
			}
			for(ll j = s;j<=i;j++){
				minres = min(minres, l+r);
				l += (j > 0 ? p[j-1] : 0)-(s > 0 ? p[s-1] : 0);
				if(a[j] == 1){
					l++;
				}
				r -= p[i]-p[j];
			}
			res+= minres;
			s = -1, ns = 0;
		}
	}
	return res;
}
int main(){
	FAST;
	cin >> n;
	for(ll i =0;i<n;i++){
		cin >> a[i];
		p[i] = a[i];
		if(i != 0) p[i]+=p[i-1];
	}
	ll minv = INF;
	ll on = p[n-1];
	for(ll i = 2;i*i<=p[n-1];i++){
		if(p[n-1]%i!=0) continue;
		if(i*i==p[n-1]){
			minv = min(check(i), minv);
		}else{
			minv = min(check(i), minv);
			minv = min(check(p[n-1]/i), minv);
		}
		while(on%i) on/=i;
	}
	if(on != 1) minv = min(check(on), minv);
	if(minv == INF) cout << -1 << endl;
	else cout << minv << endl;
}