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
	int n, k;
	cin >> n >> k;
	int ile[n], T[n], ans[n], ok[n];
	rep(i, n) {
		cin >> T[i]; --T[i];
		ile[i]=0;
		ans[i]=0;
		ok[i]=0;
	}
	rep(i, n) {
		++ile[T[i]];
		if(ile[T[i]]>=k) ok[T[i]]=1;
	}
	rep(i, n) {
		if(!ok[T[i]]) continue;
		if(ile[T[i]]==0) continue;
		ile[T[i]]=min(ile[T[i]], k);
		ans[i]=ile[T[i]];
		--ile[T[i]];
	}
	vector<pair<int,int>>V;
	rep(i, n) {
		if(ok[T[i]]) continue;
		V.pb({T[i], i});
	}
	sort(all(V));
	rep(i, V.size()-(V.size()%k)) {
		ans[V[i].nd]=(i%k)+1;
	}
	rep(i, n) cout << ans[i] << " ";
	cout << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t=1;
	cin >> t;
	while(t--) solve();
}