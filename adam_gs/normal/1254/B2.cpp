#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const ll INF=1e18+7;
const int LIM=1e6+7;
ll T[LIM], P[LIM], n;
ll solve(ll x) {
	rep(i, n) P[i]=T[i];
	vector<ll>V;
	ll sum=0, ans=0;
	rep(i, n) {
		if(sum+P[i]>=x) {
			P[i]-=x-sum;
			V.pb(x-sum);
			sum=x;
		}
		if(sum==x) {
			ll ind=-1, akt=0;
			rep(i, V.size()) {
				akt+=V[i];
				if(akt>=(x+1)/2) {
					ind=i;
					break;
				}
			}
			rep(i, ind) ans+=V[i]*(ind-i);
			for(ll i=ind+1; i<V.size(); ++i) ans+=V[i]*(i-ind);
			V.clear();
			sum=0;
		}
		P[i]%=x;
		V.pb(P[i]);
		sum+=P[i];
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	ll sum=0;
	rep(i, n) {
		cin >> T[i];
		sum+=T[i];
	}
	if(sum==1) {
		cout << -1 << '\n';
		return 0;
	}
	ll ans=INF;
	for(ll i=2; i*i<=sum; ++i) {
		if(sum%i) continue;
		ans=min(ans, solve(i));
		while(sum%i==0) sum/=i;
	}
	if(sum>1) ans=min(ans, solve(sum));
	cout << ans << '\n';
}