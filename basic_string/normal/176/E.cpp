#include<cstdio>
#include<set>
using std::set;
const int N=100009,M=200009;
int he[N],to[M],len[M],ne[M];
int fa[N],sz[N],sn[N],tp[N],f[N],g[N],ct,d[N];
long long dis[N];
void dfs1(int x,int y){
	d[x]=d[y]+1,fa[x]=y,sz[x]=1,f[x]=++ct;
	g[ct]=x;
	for(register int i=he[x],j;i;i=ne[i]){
		j=to[i];
		if(j!=y){
			dis[j]=dis[x]+len[i],dfs1(j,x),sz[x]+=sz[j];
			if(sz[sn[x]]<sz[j])sn[x]=j;
		}
	}
}
void dfs2(int x,int y){
	tp[x]=y;
	if(!sn[x])return;
	dfs2(sn[x],y);
	for(register int i=he[x],j;i;i=ne[i]){
		j=to[i];
		if(j!=sn[x]&&j!=fa[x])dfs2(j,j);
	}
}
int lca(int x,int y){
	register int i;
	while(tp[x]!=tp[y]){
		if(d[tp[x]]<d[tp[y]])i=x,x=y,y=i;
		x=fa[tp[x]];
	}
	return d[x]<d[y]?x:y;
}
inline long long getd(int x,int y){
	return dis[x]+dis[y]-(dis[lca(x,y)]<<1);
}
set<int>s;
set<int>::iterator it,pr,nx;
int main(){
	int n,m,i,j,k,l,t=0;
	long long ans=0;
	char ch;
	scanf("%d",&n);
	for(i=1;i<n;++i){
		scanf("%d%d%d",&j,&k,&l);
		ne[++t]=he[j],to[t]=k,len[t]=l,he[j]=t;
		ne[++t]=he[k],to[t]=j,len[t]=l,he[k]=t;
	}
	dfs1(1,0),dfs2(1,1);
	scanf("%d",&m);
	bool fl;
	while(m--){
		scanf(" %c",&ch);
		if(ch=='?'){printf("%lld\n",fl?0:ans/2);continue;}
		scanf("%d",&i);fl=0;
		it=s.find(f[i]);
		if(it==s.end()){
			it=s.insert(f[i]).first;
			if(s.size()==1){
				fl=1;
				continue;
			}
			if(it==s.begin())pr=--s.end();
			else{
				pr=--it;
				++it;
			}
			nx=++it;
			if(nx==s.end())nx=s.begin();
			j=g[*pr],k=g[*nx];
			ans+=getd(i,j)+getd(i,k)-getd(j,k);
		}else{
			if(s.size()==1){
				s.erase(it),fl=1;
				continue;
			}
			if(it==s.begin())pr=--s.end();
			else{
				pr=--it;
				++it;
			}
			nx=++it;
			--it;
			if(nx==s.end())nx=s.begin();
			j=g[*pr],k=g[*nx];
			ans-=getd(i,j)+getd(i,k)-getd(j,k),s.erase(it);
		}
	}
	return 0;
}