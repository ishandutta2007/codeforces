#include <bits/stdc++.h>
#if defined(__GNUC__)
#pragma GCC optimize ("Ofast")
#endif
using namespace std;
#define all(x) x.begin(), x.end()
#define pb push_back

const int MAXN = 131072, LOG=17;

int n, m, k, l, r;
int G[MAXN][LOG];
unordered_map<int, vector<int>> vec;

int f(int l, int r, int x){ return lower_bound(all(vec[x]), r) - lower_bound(all(vec[x]), l);}

void query(){
	cin>>l>>r;
	r++;
	int x=log2(r-l);
	int g=__gcd(G[l][x], G[r-(1<<x)][x]);
	cout<<r-l-f(l, r, g)<<'\n';
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	for (int i=1; i<=n; i++){
		cin>>G[i][0];
		vec[G[i][0]].pb(i);
	}
	for (int j=1; j<LOG; j++) for (int i=0; i<=n; i++) G[i][j]=__gcd(G[i][j-1], G[i+(1<<(j-1))][j-1]);
	cin>>m;
	while (m--) query();
	
	return 0;
}