#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

const int MAXN = 600010;

int n, m, k, u, v, x, y, t, a, b;
int par[MAXN], col[MAXN];
ll s0[MAXN], s1[MAXN], ans;
vector<int> vec[MAXN];
string S;

pii Getpar(int x){
	if (par[x]==x) return {x, 0};
	pii p=Getpar(par[x]);
	return {par[x]=p.first, col[x]^=p.second};
}

void Join(int u, int v, int w){
	pii x=Getpar(u);
	pii y=Getpar(v);
	if (x.first==y.first) return ;
	
	ans-=min(s1[x.first], s0[x.first]);
	ans-=min(s1[y.first], s0[y.first]);
	
	if (w^x.second^y.second){
		swap(s1[y.first], s0[y.first]);
		col[y.first]=1;
	}
	par[y.first]=x.first;
	s1[x.first]+=s1[y.first];
	s0[x.first]+=s0[y.first];
	
	ans+=min(s1[x.first], s0[x.first]);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>k>>S; 
	for (int i=1; i<=k; i++){
		par[i]=i, s0[i]=1;
		cin>>x;
		while (x--){
			cin>>y;
			vec[y].pb(i);
		}
	}
	S="."+S;
	for (int i=1; i<=n; i++){
		if (vec[i].size()==1){
			par[k+i]=k+i;
			s0[k+i]=k+1;
			Join(vec[i][0], k+i, S[i]=='0');
		}
		if (vec[i].size()==2) Join(vec[i][0], vec[i][1], S[i]=='0');
		cout<<ans<<'\n';
	}
	
	return 0;
}