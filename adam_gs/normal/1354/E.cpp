#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=5e3+7;
vector<int>V[LIM], P[2*LIM];
int kol[LIM], ile[2*LIM], dp[LIM][LIM];
bool ok=true;
void DFS(int x, int k) {
	kol[x]=k;
	P[k].pb(x);
	++ile[k];
	for(auto i : V[x]) {
		if(kol[i]==-1) DFS(i, k^1);
		else if(kol[i]==k) ok=false;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m, n1, n2, n3;
	cin >> n >> m >> n1 >> n2 >> n3;
	while(m--) {
		int a, b;
		cin >> a >> b; --a; --b;
		V[a].pb(b);
		V[b].pb(a);
	}
	rep(i, n) kol[i]=-1;
	int akt=0;
	rep(i, n) if(kol[i]==-1) {
		DFS(i, 2*akt);
		++akt;
	}
	if(!ok) {
		cout << "NO\n";
		return 0;
	}
	dp[0][0]=1;
	rep(i, akt) {
		rep(j, n+1) {
			if(j-ile[2*i]>=0 && dp[i][j-ile[2*i]]) dp[i+1][j]=1;
			if(j-ile[2*i+1]>=0 && dp[i][j-ile[2*i+1]]) dp[i+1][j]=2;
		}
	}
	if(!dp[akt][n2]) {
		cout << "NO\n";
		return 0;
	}
	string ans="";
	rep(i, n) ans+="3";
	for(int i=akt; i; --i) {
		if(dp[i][n2]==1) {
			for(auto j : P[2*i-2]) ans[j]='2';
			n2-=ile[2*i-2];
		} else {
			for(auto j : P[2*i-1]) ans[j]='2';
			n2-=ile[2*i-1];
		}
	}
	rep(i, n) if(n1 && ans[i]=='3') {
		ans[i]='1';
		--n1;
	}
	cout << "YES\n" << ans << '\n';
}