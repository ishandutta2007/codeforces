#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ui long long
#define ull unsigned long long
#define db double
#define pii pair<int,int>
#define pli pair<ll,int>
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define vii vector<vi>
#define lb lower_bound
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,b,a) for(int i=(b);i>=(a);--i)
#define rep0(i,a,b) for(int i=(a);i<(b);++i)
#define fore(i,a) for(int i=0;i<a.size();++i)
#define gc() getchar()
#define ls x<<1,l,m
#define rs x<<1|1,m+1,r
inline int rd()
{
	int x=0,w=1;char c=gc();while(!isdigit(c)&&c!='-')c=gc();
	if(c=='-')c=gc(),w=-1;while(isdigit(c))x=x*10+c-48,c=gc();return x*w;
}
const int N=500005,K=51;
int n,m,k,q,tp,u[N],v[N],a[N],c[N],lst[N],col[N],f[K][N*2],d[K][N*2];vi E[N*2];
struct st{int o,x,t;}stk[N*2];
void ins(int x,int l,int r,int tl,int tr,int v)
{
	if(tl<=l&&r<=tr){E[x].pb(v);return;}int m=l+r>>1;
	if(tl<=m)ins(ls,tl,tr,v);if(tr>m)ins(rs,tl,tr,v);
}
inline int fnd(int o,int x){while(x!=f[o][x])x=f[o][x];return x;}
inline void uni(int o,int x,int y)
{
	if(x==y)return;if(d[o][x]>d[o][y])swap(x,y);f[o][x]=y;
	int t=d[o][x]==d[o][y];stk[++tp]=(st){o,x,t};d[o][y]+=t;
}
void dfs(int x,int l,int r)
{
	int t=tp; 
	for(int t:E[x])
	{
		int e=a[t],o=c[t],x=u[e],y=v[e];if(!o)continue;
		uni(o,fnd(o,x),fnd(o,n+y));uni(o,fnd(o,n+x),fnd(o,y));
	} 
    if(l==r)
    {
		int e=a[l],o=c[l],x=u[e],y=v[e];
		if(fnd(o,x)==fnd(o,y))puts("NO"),c[l]=col[e];else puts("YES"),col[e]=o;
	}
	else{int m=l+r>>1;dfs(ls);dfs(rs);}
    while(tp>t)
    {
    	int o=stk[tp].o,x=stk[tp].x,t=stk[tp].t;
    	tp--;d[o][f[o][x]]-=t;f[o][x]=x;
	}
}
int main()
{
	n=rd();m=rd();k=rd();q=rd();
	rep(i,1,n)rep(j,1,k)f[j][i]=i,f[j][i+n]=i+n;
	rep(i,1,m)u[i]=rd(),v[i]=rd(),lst[i]=q+1;
	rep(i,1,q)a[i]=rd(),c[i]=rd();
	per(i,q,1)
	{
		int t=a[i];
		if(i+1<=lst[t]-1)ins(1,1,q,i+1,lst[t]-1,i);
		lst[t]=i;
	}
	rep(i,1,m)lst[i]=0;
	dfs(1,1,q);return 0;
}