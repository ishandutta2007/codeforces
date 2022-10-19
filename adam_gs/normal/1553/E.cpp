#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define lg(a) (31-__builtin_clz(a))
#define all(a) a.begin(), a.end()
ll pow(ll a,ll b,ll c){ll w=1;while(b){if(b&1)w=(w*a)%c;b/=2;a=(a*a)%c;}return w;}
void solve() {
	int n, m;
	cin >> n >> m;
	int ile[n], T[n];
	rep(i, n) {
		cin >> T[i]; --T[i];
		ile[i]=0;
	}
	rep(i, n) {
		if(T[i]<=i) {
			++ile[i-T[i]];
		} else {
			++ile[n-T[i]+i];
		}
	}
	vector<int>ans;
	rep(p, n) if(3*ile[p]>=n) {
		int F[n], odw[n], cykle=0;
		rep(i, n) {
			F[i]=(T[i]+p)%n;
			odw[i]=0;
		}
		rep(i, n) if(!odw[i]) {
			++cykle;
			odw[i]=1;
			int c=F[i];
			while(!odw[c]) {
				odw[c]=1;
				c=F[c];
			}
		}
		if(n-cykle<=m) ans.pb(p);
	}
	cout << ans.size() << " ";
	for(auto i : ans) cout << i << " ";
	cout << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t=1;
	cin >> t;
	while(t--) solve();
}