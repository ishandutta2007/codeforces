#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=1507, INF=1e9+7;
vector<ll>V[2*LIM], cykl;
ll odw[2*LIM], n, ans;
void DFS(ll x) {
	cykl.pb(x);
	odw[x]=1;
	for(auto i : V[x]) if(!odw[i]) DFS(i);
}
void solve(ll x) {
	cykl.clear();
	DFS(x);
	rep(i, cykl.size()) {
		ll mi1=n-1, ma1=0, mi2=2*n-1, ma2=n;
		rep(j, cykl.size()-1) {
			ll p=cykl[(i+j)%cykl.size()];
			if(p<n) {
				mi1=min(mi1, p);
				ma1=max(ma1, p);
			} else {
				mi2=min(mi2, p);
				ma2=max(ma2, p);
			}
			ll a=cykl[(i-1+cykl.size())%cykl.size()], b=cykl[(i+j+1)%cykl.size()];
			if(a>b) swap(a, b);
			if(mi1<=a && a<=ma1 || mi2<=a && a<=ma2 || mi1<=b && b<=ma1 || mi2<=b && b<=ma2) continue;
			ll ile1=0, ile2=0;
			if(b<n) {
				ile2=(mi2-n+1)*(2*n-ma2);
				if(b<mi1) {
					ile1=(mi1-b)*(n-ma1);
				} else if(a<mi1) {
					ile1=(mi1-a)*(b-ma1);
				} else {
					ile1=(mi1+1)*(a-ma1);
				}
			} else if(a<n) {
				if(a<mi1) {
					ile1=(mi1-a)*(n-ma1);
				} else if(a>ma1) {
					ile1=(mi1+1)*(a-ma1);
				}
				if(b<mi2) {
					ile2=(mi2-b)*(2*n-ma2);
				} else if(b>ma2) {
					ile2=(mi2-n+1)*(b-ma2);
				}
			} else {
				ile1=(mi1+1)*(n-ma1);
				if(b<mi2) {
					ile2=(mi2-b)*(2*n-ma2);
				} else if(a<mi2) {
					ile2=(mi2-a)*(b-ma2);
				} else {
					ile2=(mi2-n+1)*(a-ma2);
				}
			}
			ll d=(j+1)/2;
			d*=ile1*ile2;
			ans+=d;
		}
	}
	ll mi1=n-1, ma1=0, mi2=2*n-1, ma2=n;
	for(auto i : cykl) {
		if(i<n) {
			mi1=min(mi1, i);
			ma1=max(ma1, i);
		} else {
			mi2=min(mi2, i);
			ma2=max(ma2, i);
		}
	}
	ll d=cykl.size()/2;
	ll ile1=(mi1+1)*(n-ma1), ile2=(mi2-n+1)*(2*n-ma2);
	d*=ile1*ile2;
	ans+=d;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	rep(i, 2*n) {
		int a, b;
		cin >> a >> b; --a; --b;
		V[a].pb(b);
		V[b].pb(a);
	}
	rep(i, n) if(!odw[i]) solve(i);
	cout << ans << '\n';
}