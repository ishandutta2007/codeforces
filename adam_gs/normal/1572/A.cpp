#pragma GCC option("arch=native","tune=native","no-zero-upper") 
#pragma GCC target("avx2","popcnt","rdrnd","bmi2")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=2e5+7;
vector<int>V[LIM];
int in[LIM], dp[LIM];
void solve() {
	int n;
	cin >> n;
	rep(i, n) V[i].clear();
	rep(i, n) {
		int k;
		cin >> k;
		rep(j, k) {
			int a;
			cin >> a; --a;
			V[a].pb(i);
		}
		in[i]=k;
		dp[i]=1;
	}
	queue<int>q;
	int ile=0, ans=0;
	rep(i, n) if(in[i]==0) q.push(i);
	while(!q.empty()) {
		++ile;
		int p=q.front(); q.pop();
		ans=max(ans, dp[p]);
		for(auto i : V[p]) {
			--in[i];
			if(i<p) dp[i]=max(dp[i], dp[p]+1);
			else dp[i]=max(dp[i], dp[p]);
			if(!in[i]) q.push(i);
		}
	}
	if(ile!=n) cout << -1 << '\n';
	else cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}