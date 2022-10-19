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
const int LIM=1e5+7, INF=1e9+7;
int T[LIM];
void solve() {
	int n, mi=INF, p=-1;
	cin >> n;
	vector<pair<pair<int,int>,pair<int,int>>>ans;
	rep(i, n) {
		cin >> T[i];
		if(T[i]<mi) {
			mi=T[i];
			p=i;
		}
	}
	int akt=0;
	for(int i=p-1; i>=0; --i) {
		ans.pb({{i, p}, {INF+akt, T[p]}});
		akt^=1;
	}
	akt=0;
	for(int i=p+1; i<n; ++i) {
		ans.pb({{p, i}, {T[p], INF+akt}});
		akt^=1;
	}
	cout << ans.size() << '\n';
	for(auto i : ans) {
		cout << i.st.st+1 << " " << i.st.nd+1 << " " << i.nd.st << " " << i.nd.nd << '\n';
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t=1;
	cin >> t;
	while(t--) solve();
}