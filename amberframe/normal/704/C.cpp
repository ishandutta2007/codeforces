#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <iostream>
#include <math.h>
using namespace std;
typedef long long LL;
const LL mod = 1e9+7;
const int maxn = 100005;
int ehead[maxn],ecnt,deg[maxn],las[maxn];
struct edge{
	int u,v,next;
}edg[maxn*2];
void add(int u,int v) {
	edg[++ecnt]=(edge){u,v,ehead[u]};
	ehead[u]=ecnt;deg[u]++;
	edg[++ecnt]=(edge){v,u,ehead[v]};
	ehead[v]=ecnt;deg[v]++;
}
int abs(int x){return x>0?x:-x;}
int infomu[maxn];
struct fomu{
	int len,x1,x2;
	void read(int id) {
		scanf("%d %d",&len,&x1);
		if (las[abs(x1)]) add(las[abs(x1)],id);
		else las[abs(x1)]=id;
		infomu[abs(x1)]=1;
		if (len!=1) {
			scanf("%d",&x2);
			if (las[abs(x2)]) add(las[abs(x2)],id);
			else las[abs(x2)]=id;
			infomu[abs(x2)]=1;
		}
	}
	int calc(int fx1,int fx2=0) {
		if (len==1) return x1>0?fx1:fx1^1;
		else return (x1>0?fx1:fx1^1)|(x2>0?fx2:fx2^1);
	}
}fomu[maxn];
bool vis[maxn];int n,m;
LL f[maxn][2][2][2];int cnt;
bool check(int x,int fx,int y,int fy) {
	if (abs(x)!=abs(y)) return true;
	else if (x==0) return true;
	else if (y==0) return true;
	else return fx==fy;
}
pair<LL,LL> dp(int s) {
//	cerr<<"dp"<<s<<endl;
	LL sum0=0,sum1=0;
	int sx1=fomu[s].x1,sx2=fomu[s].x2;
	for (int fsx1=0;fsx1<2;fsx1++) 
	for (int fsx2=0;fsx2<fomu[s].len;fsx2++) {
		if (!check(sx1,fsx1,sx2,fsx2)) continue;
		f[1][0][0][0]=f[1][0][1][0]=f[1][1][0][0]=f[1][1][1][0]=0;
		f[1][0][0][1]=f[1][0][1][1]=f[1][1][0][1]=f[1][1][1][1]=0;
		f[1][fsx1][fsx2][fomu[s].calc(fsx1,fsx2)]=1;
		cnt=1;vis[s]=true;int fa=0,cur=s;
		while (true) {
			for (int j=ehead[cur];j;j=edg[j].next)
			if (edg[j].v!=fa&&edg[j].v!=s) {
				fa=cur;vis[cur=edg[j].v]=true;++cnt;
				for (int fx1=0;fx1<2;fx1++)
				for (int fx2=0;fx2<fomu[cur].len;fx2++)
				for (int dat=0;dat<2;dat++) {
					LL sum=0;
					for (int _fx1=0;_fx1<2;_fx1++)
					for (int _fx2=0;_fx2<fomu[fa].len;_fx2++) 
					for (int _dat=0;_dat<2;_dat++) {
						int _x1=fomu[fa].x1,x1=fomu[cur].x1;
						int _x2=fomu[fa].x2,x2=fomu[cur].x2;
						if (!check(_x1,_fx1,x1,fx1)) continue; 
						if (!check(_x1,_fx1,x2,fx2)) continue; 
						if (!check(_x2,_fx2,x1,fx1)) continue; 
						if (!check(_x2,_fx2,x2,fx2)) continue; 
						if (!check(sx1,fsx1,x1,fx1)) continue; 
						if (!check(sx2,fsx2,x1,fx1)) continue; 
						if (!check(sx1,fsx1,x2,fx2)) continue; 
						if (!check(sx2,fsx2,x2,fx2)) continue;
						if (_dat^fomu[cur].calc(fx1,fx2)==dat)
							sum+=f[cnt-1][_fx1][_fx2][_dat];
					}
					f[cnt][fx1][fx2][dat]=sum%mod;
				}
				goto loop;
			}
			break;loop:;
		}
		for (int fx1=0;fx1<2;fx1++)
		for (int fx2=0;fx2<fomu[cur].len;fx2++) {
			sum0+=f[cnt][fx1][fx2][0];
			sum1+=f[cnt][fx1][fx2][1];
		}
	}
	return pair<LL,LL> (sum0%mod,sum1%mod);
}
LL g[maxn][2];int tot;
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("widow.in","r",stdin);
		freopen("widow.out","w",stdout);
	#endif
	scanf("%d %d",&n,&m);g[0][0]=1;
	for (int i=1;i<=n;i++) fomu[i].read(i);
	for (int i=1;i<=n;i++)
	if (!vis[i]&&deg[i]<2) {
		pair<LL,LL> tmp=dp(i);++tot;
//		cerr<<i<<" "<<tmp.first<<" "<<tmp.second<<endl;
		g[tot][0]=(g[tot-1][0]*tmp.first+g[tot-1][1]*tmp.second)%mod;
		g[tot][1]=(g[tot-1][1]*tmp.first+g[tot-1][0]*tmp.second)%mod;
//		cerr<<g[tot][0]<<" "<<g[tot][1]<<endl;
	}
	for (int i=1;i<=n;i++)
	if (!vis[i]) {
		pair<LL,LL> tmp=dp(i);++tot;
//		cerr<<i<<" "<<tmp.first<<" "<<tmp.second<<endl;
		g[tot][0]=(g[tot-1][0]*tmp.first+g[tot-1][1]*tmp.second)%mod;
		g[tot][1]=(g[tot-1][1]*tmp.first+g[tot-1][0]*tmp.second)%mod;
//		cerr<<g[tot][0]<<" "<<g[tot][1]<<endl;
	}
	LL ans=g[tot][1];
	for (int i=1;i<=m;i++)
		if (!infomu[i]) (ans<<=1)%=mod;
	printf("%I64d\n",ans);
	return 0;
}