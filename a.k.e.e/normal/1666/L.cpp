// xtqqwq
#include<bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

template <typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m,s;
int fr[200005],bel[200005];
vector<int> adj[200005];

void dfs(int u,int t){
	bel[u]=t;
	for(auto v:adj[u]){
		if(v==s) continue;
		if(bel[v]==t) continue;
		if(bel[v]){
			printf("Possible\n");
			vector<int> vec(0);
			for(int i=v;i;i=fr[i]) vec.pb(i);
			vec.pb(s);
			reverse(vec.begin(),vec.end());
			printf("%d\n",vec.size());
			for(auto r:vec) printf("%d ",r);
			printf("\n");
			vec.clear();
			for(int i=u;i;i=fr[i]) vec.pb(i);
			vec.pb(s);
			reverse(vec.begin(),vec.end());
			vec.pb(v);
			printf("%d\n",vec.size());
			for(auto r:vec) printf("%d ",r);
			printf("\n");
			exit(0);
		}
		fr[v]=u;
		dfs(v,t);
	}
}

int main(){
	n=readint(); m=readint(); s=readint();
	int x,y;
	for(int i=1;i<=m;i++){
		x=readint(); y=readint();
		adj[x].pb(y);
	}
	for(auto v:adj[s]){
		if(bel[v]){
			printf("Possible\n");
			vector<int> vec(0);
			for(int i=v;i;i=fr[i]) vec.pb(i);
			vec.pb(s);
			reverse(vec.begin(),vec.end());
			printf("%d\n",vec.size());
			for(auto r:vec) printf("%d ",r);
			printf("\n");
			vec.clear();
			vec.pb(s);
			vec.pb(v);
			printf("%d\n",vec.size());
			for(auto r:vec) printf("%d ",r);
			printf("\n");
			exit(0);
		}
		else dfs(v,v);
	}
	printf("Impossible\n");
	return 0;
}