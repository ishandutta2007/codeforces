#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,fa[100100],deg[100100];
ll f[100100],g[100100];
multiset<ll>s[100100];
void ins(int x){
	if(s[x].empty())return;
	s[0].insert(*s[x].begin()+f[x]/deg[x]);
	s[0].insert(*s[x].rbegin()+f[x]/deg[x]);
}
void del(int x){
//	printf("%d\n",x);
//	for(int i=0;i<=n;i++){printf("%d:",i);for(auto x:s[i])printf("%lld ",x);puts("");}
	if(s[x].empty())return;
	s[0].erase(s[0].find(*s[x].begin()+f[x]/deg[x]));
	s[0].erase(s[0].find(*s[x].rbegin()+f[x]/deg[x]));
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&f[i]);
	for(int i=1;i<=n;i++)scanf("%d",&fa[i]),deg[i]+=2,deg[fa[i]]++;
	for(int i=1;i<=n;i++)g[fa[i]]+=f[i]/deg[i],g[i]+=f[i]-f[i]/deg[i]*(deg[i]-1);
	for(int i=1;i<=n;i++)s[fa[i]].insert(g[i]);
	for(int i=1;i<=n;i++)ins(i);
//	for(int i=0;i<=n;i++){for(auto x:s[i])printf("%lld ",x);puts("");}
	for(int i=1,tp,x;i<=m;i++){
		scanf("%d",&tp);
		if(tp==3){printf("%lld %lld\n",*s[0].begin(),*s[0].rbegin());continue;}
		scanf("%d",&x);
		if(tp==2){printf("%lld\n",g[x]+f[fa[x]]/deg[fa[x]]);continue;}
		del(fa[x]);
		s[fa[x]].erase(s[fa[x]].find(g[x]));
		del(fa[fa[x]]);
		s[fa[fa[x]]].erase(s[fa[fa[x]]].find(g[fa[x]]));
		del(fa[fa[fa[x]]]);
		s[fa[fa[fa[x]]]].erase(s[fa[fa[fa[x]]]].find(g[fa[fa[x]]]));
		
		g[fa[fa[x]]]-=f[fa[x]]/deg[fa[x]];
		g[fa[x]]-=f[x]/deg[x],g[fa[x]]-=f[fa[x]]-f[fa[x]]/deg[fa[x]]*(deg[fa[x]]-1);
		deg[fa[x]]--,g[fa[x]]+=f[fa[x]]-f[fa[x]]/deg[fa[x]]*(deg[fa[x]]-1);
		g[fa[fa[x]]]+=f[fa[x]]/deg[fa[x]];
		
		s[fa[fa[fa[x]]]].insert(g[fa[fa[x]]]);
		ins(fa[fa[fa[x]]]);
		s[fa[fa[x]]].insert(g[fa[x]]);
		ins(fa[fa[x]]);
		
		ins(fa[x]);
		scanf("%d",&fa[x]);
		del(fa[x]);
		
		del(fa[fa[x]]);
		s[fa[fa[x]]].erase(s[fa[fa[x]]].find(g[fa[x]]));
		del(fa[fa[fa[x]]]);
		s[fa[fa[fa[x]]]].erase(s[fa[fa[fa[x]]]].find(g[fa[fa[x]]]));
		
		g[fa[fa[x]]]-=f[fa[x]]/deg[fa[x]];
		g[fa[x]]+=f[x]/deg[x],g[fa[x]]-=f[fa[x]]-f[fa[x]]/deg[fa[x]]*(deg[fa[x]]-1);
		deg[fa[x]]++,g[fa[x]]+=f[fa[x]]-f[fa[x]]/deg[fa[x]]*(deg[fa[x]]-1);
		g[fa[fa[x]]]+=f[fa[x]]/deg[fa[x]];
		
		s[fa[fa[fa[x]]]].insert(g[fa[fa[x]]]);
		ins(fa[fa[fa[x]]]);
		s[fa[fa[x]]].insert(g[fa[x]]);
		ins(fa[fa[x]]);
		s[fa[x]].insert(g[x]);
		ins(fa[x]);
	}
	return 0;
}