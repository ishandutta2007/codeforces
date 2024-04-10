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
ll dp[LIM], ile[LIM], l[LIM], r[LIM];
void DFS(int x) {
	ll s=0;
	for(auto i : V[x]) {
		DFS(i);
		s+=ile[i];
		dp[x]+=dp[i];
	}
	s=min(s, r[x]);
	ile[x]=s;
	if(s<l[x]) {
		ile[x]=r[x];
		++dp[x];
	}
}
void solve() {
	int n;
	cin >> n;
	rep(i, n) {
		V[i].clear();
		dp[i]=ile[i]=0;
	}
	rep(i, n-1) {
		int a;
		cin >> a; --a;
		V[a].pb(i+1);
	}
	rep(i, n) cin >> l[i] >> r[i];
	DFS(0);
	cout << dp[0] << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}