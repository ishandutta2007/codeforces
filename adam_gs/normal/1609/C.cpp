#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=1e6+7;
ll cp[LIM], lewo[LIM], prawo[LIM];
ll licz(vector<int>&V) {
	rep(i, V.size()+1) lewo[i]=prawo[i]=0;
	for(int i=V.size()-1; i>=0; --i) {
		if(V[i]==1) prawo[i]=prawo[i+1]+1;
	}
	ll ans=0;
	rep(i, V.size()) {
		if(V[i]==1) lewo[i]=(i?lewo[i-1]:0)+1;
		if(!cp[V[i]]) {
			ans+=((i?lewo[i-1]:0)+1)*(prawo[i+1]+1)-1;
		}
	}
	return ans;
}
void solve() {
	int n, e;
	cin >> n >> e;
	int T[n];
	rep(i, n) cin >> T[i];
	ll ans=0;
	rep(i, e) {
		vector<int>V;
		for(int j=i; j<n; j+=e) V.pb(T[j]);
		ans+=licz(V);
	}
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cp[1]=1;
	for(int i=2; i<LIM; ++i) {
		if(cp[i]) continue;
		for(int j=2*i; j<LIM; j+=i) cp[j]=1;
	}
	int _;
	cin >> _;
	while(_--) solve();
}