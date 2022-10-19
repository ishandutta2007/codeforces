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
const int LIM=1e5+7;
vector<int>V[LIM], dobre;
int T[LIM], dp[LIM], s, B[LIM], pre[LIM], post[LIM], lpre, lpost;
bool ok;
void DFS(int x, int o) {
	++lpre;
	pre[x]=lpre;
	dp[x]=T[x];
	B[x]=0;
	for(auto i : V[x]) if(i!=o) {
		DFS(i, x);
		dp[x]^=dp[i];
		if(B[i]) B[x]=1;
	}
	if(dp[x]==s) {
		dobre.pb(x);
		B[x]=1;
	}
	if(dp[x]==0) ok=true;
	++lpost;
	post[x]=lpost;
}
bool oc(int a, int b) {
	return pre[a]<=pre[b] && post[a]>=post[b];
}
void solve() {
	int n, k;
	cin >> n >> k; --k;
	s=0;
	rep(i, n) {
		cin >> T[i];
		s^=T[i];
		V[i].clear();
	}
	rep(i, n-1) {
		int a, b;
		cin >> a >> b; --a; --b;
		V[a].pb(b);
		V[b].pb(a);
	}
	if(s==0) {
		cout << "YES\n";
		return;
	}
	if(k==1) {
		cout << "NO\n";
		return;
	}
	ok=false;
	lpre=lpost=0;
	dobre.clear();
	DFS(0, 0);
	int akt=dobre[0];
	for(int i=1; i<dobre.size(); ++i) {
		if(oc(akt, dobre[i])) {
			akt=dobre[i];
		} else if(!oc(dobre[i], akt)) ok=true;
	}
	cout << (ok?"YES":"NO") << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}