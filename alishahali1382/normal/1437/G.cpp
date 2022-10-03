#include <bits/stdc++.h>
using namespace std;

const int MAXN=300010, SGM=26;

int n, m, k, u, v, x, y, t, a, b, ans;
int C[MAXN][SGM], F[MAXN], ts;
int pos[MAXN], Q[MAXN], L, R;
int stt[MAXN], fnt[MAXN], timer;
int sz[MAXN], head[MAXN];
int seg[MAXN<<1], val[MAXN];
set<pair<int, int>> st[MAXN];
vector<int> G[MAXN];
string S;

int AddTrie(string &s){
	int v=0;
	for (char ch:s){
		if (!C[v][ch-'a']) C[v][ch-'a']=++ts;
		v=C[v][ch-'a'];
	}
	return v;
}
void BuildAho(){
	for (int i=0; i<SGM; i++) if (C[0][i]) Q[R++]=C[0][i];
	while (L<R){
		int v=Q[L++];
		G[F[v]].push_back(v);
		for (int i=0; i<SGM; i++){
			if (!C[v][i]) C[v][i]=C[F[v]][i];
			else{
				F[C[v][i]]=C[F[v]][i];
				Q[R++]=C[v][i];
			}
		}
	}
}
int dfs1(int node){
	for (int v:G[node]) sz[node]+=dfs1(v);
	return ++sz[node];
}
void dfs2(int node){
	stt[node]=timer++;
	int big=-1;
	for (int v:G[node]) if (big==-1 || sz[v]>sz[big]) big=v;
	if (big!=-1) head[big]=head[node], dfs2(big);
	for (int v:G[node]) if (v!=big) head[v]=v, dfs2(v);
	fnt[node]=timer;
}
void Set(int pos, int val){
	for (seg[pos+=MAXN]=val; pos>1; pos>>=1) seg[pos>>1]=max(seg[pos], seg[pos^1]);
}
int Get(int l, int r){
	int res=-1;
	for (l+=MAXN, r+=MAXN; l<r; l>>=1, r>>=1){
		if (l&1) res=max(res, seg[l++]);
		if (r&1) res=max(res, seg[--r]);
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for (int i=1; i<=n; i++){
		cin>>S;
		pos[i]=AddTrie(S);
	}
	BuildAho();
	F[0]=-1;
	dfs1(0);
	dfs2(0);
	memset(seg, -1, sizeof(seg));
	for (int i=1; i<=n; i++) Set(stt[pos[i]], 0), st[pos[i]].insert({0, i});
	while (m--){
		cin>>t;
		if (t==1){
			cin>>x>>y;
			st[pos[x]].erase({val[x], x});
			st[pos[x]].insert({val[x]=y, x});
			Set(stt[pos[x]], st[pos[x]].rbegin()->first);
			continue ;
		}
		cin>>S;
		int ans=-1, v=0;
		for (char ch:S){
			v=C[v][ch-'a'];
			int u=v;
			while (u!=-1){
				ans=max(ans, Get(stt[head[u]], stt[u]+1));
				u=F[head[u]];
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}