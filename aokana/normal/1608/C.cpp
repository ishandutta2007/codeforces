#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxm=1e6+10,maxn=1e5+10;
struct edge{
	int to,nxt;
}e[maxm];
int hd[maxn],len;
inline void addedge(int fr,int to){
	e[++len]={to,hd[fr]};
	hd[fr]=len;
}
int clr,cnt,dfn[maxn],id[maxn],low[maxn],st[maxn],tp;
bool vis[maxn];
inline void ckmin(int &x,int y){if(x>y)x=y;}
void tarjan(int p){
	dfn[p]=low[p]=++cnt;
	st[++tp]=p;
	vis[p]=true;
	for(ri i=hd[p];i;i=e[i].nxt)
		if(!dfn[e[i].to])tarjan(e[i].to),ckmin(low[p],low[e[i].to]);
		else if(vis[e[i].to])ckmin(low[p],dfn[e[i].to]);
	if(dfn[p]==low[p]){
		++clr;
		int k;
		do{
			k=st[tp--];
			id[k]=clr;
			vis[k]=false;
		}while(k!=p);
	}
}
typedef pair<int,int> pii;
#define fi first
#define se second
vector<pii>ed;
int a[maxn],b[maxn],ideg[maxn],n,odeg[maxn],tmp[maxn],t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		len=clr=cnt=tp=0;
		for(ri i=1;i<=n;++i){
			scanf("%d",a+i);
			dfn[i]=low[i]=hd[i]=ideg[i]=odeg[i]=st[i]=0;
			tmp[i]=i;
		}
		sort(tmp+1,tmp+n+1,[&](int x,int y){return a[x]<a[y];});
		for(ri i=1;i<n;++i)addedge(tmp[i],tmp[i+1]);
		for(ri i=1;i<=n;++i)scanf("%d",b+i);
		sort(tmp+1,tmp+n+1,[&](int x,int y){return b[x]<b[y];});
		for(ri i=1;i<n;++i)addedge(tmp[i],tmp[i+1]);
		for(ri i=1;i<=n;++i)
			if(!dfn[i])
				tarjan(i);
		ed.clear();
		for(ri i=1;i<=n;++i)
			for(ri j=hd[i];j;j=e[j].nxt)
				if(id[i]!=id[e[j].to])
					ed.emplace_back(id[i],id[e[j].to]);
		sort(ed.begin(),ed.end());
		ed.erase(unique(ed.begin(),ed.end()),ed.end());
		for(auto i:ed)++odeg[i.fi],++ideg[i.se];
		for(ri i=1;i<=n;++i)printf("%d",!odeg[id[i]]);
		putchar(10);
	}
	return 0;
}