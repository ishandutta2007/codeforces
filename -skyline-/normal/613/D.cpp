#include<bits/stdc++.h>
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
#define fi   first
#define se   second
using namespace std;
int n,q,k,dfn[100005],d[100005],f[100005][17],_;
int h[100005],nx[100005],t[100005],s[200005],S,ans;
pair<int,int> p[100005];
bool b[100005];
vector<int> v[100005];
void ope(int x,int y){
	f[x][0]=y,d[x]=d[y]+1,dfn[x]=++_;
	for(int i=0;i<16;++i)f[x][i+1]=f[f[x][i]][i];
	for(int i=0;i<v[x].size();++i)if(v[x][i]!=y)ope(v[x][i],x);
}
int lca(int x,int y){
	if(d[y]>d[x])swap(x,y);
	for(int i=16;i>=0;--i)if((d[x]-d[y])&(1<<i))x=f[x][i];
	if(x==y) return x;
	for(int i=16;i>=0;--i)if(f[x][i]!=f[y][i])x=f[x][i],y=f[y][i];
	return f[x][0];
}
void add(int x,int y){
	++_,nx[_]=h[x],h[x]=_,t[_]=y;
}
int dfs(int x){
	if(b[x]){
		for(;h[x];h[x]=nx[h[x]])ans+=dfs(t[h[x]]);
		return 1;
	}
	int s=0;
	for(;h[x];h[x]=nx[h[x]])s+=dfs(t[h[x]]);
	if(s>1){
		++ans;
		return 0;
	}
	return s;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].pb(y),v[y].pb(x);
	}
	ope(1,0);
	scanf("%d",&q);
	while(q--){
		scanf("%d",&k);
		for(int i=1;i<=k;++i)scanf("%d",&p[i].se),b[p[i].se]=1,p[i].fi=dfn[p[i].se];
		bool ok=1;
		for(int i=1;i<=k;++i)if(b[f[p[i].se][0]])ok=0;
		if(!ok){
			for(int i=1;i<=k;++i)b[p[i].se]=0;
			printf("-1\n");
			continue;
		}
		_=0;
		sort(p+1,p+k+1);
		s[S=1]=p[1].se;
		for(int i=2;i<=k;++i){
			int x=p[i].se,y=lca(x,s[S]);
			while(S>1&&d[y]<d[s[S-1]]){
				add(s[S-1],s[S]);
				--S;
			}
			if(d[y]<d[s[S]])add(y,s[S--]);
			if(!S||s[S]!=y)s[++S]=y;
			s[++S]=x;
		}
		while(S>1){
			add(s[S-1],s[S]);
			--S;
		}
		ans=0;
		dfs(s[1]);
		printf("%d\n",ans);
		for(int i=1;i<=k;++i)b[p[i].se]=0;
	}
    return 0;
}