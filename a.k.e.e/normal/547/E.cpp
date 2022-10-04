#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
#define mp make_pair
#define pb push_back
template <typename TYPE> inline void chkmax(TYPE &x,TYPE y){x<y?x=y:0;}
template <typename TYPE> inline void chkmin(TYPE &x,TYPE y){y<x?x=y:0;}
template <typename TYPE> void readint(TYPE &x)
{
	x=0;int f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+c-'0';
	x*=f;
}
const int MAXN=400005,MAXK=18;

int n,m,lft[MAXN],rgt[MAXN],a[MAXN];
char str[MAXN];
int lrk[MAXN],rrk[MAXN];

struct Suffix
{
	int x,y,id;
	Suffix(){}
	Suffix(int x,int y,int id):x(x),y(y),id(id){}
}wa[MAXN],wb[MAXN];
int rk[MAXN],sa[MAXN],height[MAXN],wcnt[MAXN];
void buildsa()
{
	int tot=0;
	memset(wcnt,0,sizeof(wcnt));
	for(int i=1;i<=m;++i)++wcnt[a[i]];
	for(int i=1;i<=25+n;++i)wcnt[i]+=wcnt[i-1];
	for(int i=m;i;--i)sa[wcnt[a[i]]--]=i;
	for(int i=1;i<=m;++i)rk[sa[i]]=(tot+=(a[sa[i]]!=a[sa[i-1]]));
	for(int k=1;k<=m;k<<=1)
	{
		for(int i=1;i<=m;++i)wa[i]=Suffix(rk[i],i+k>m?0:rk[i+k],i);
		memset(wcnt,0,sizeof(wcnt));
		for(int i=1;i<=m;++i)++wcnt[wa[i].y];
		for(int i=1;i<=tot;++i)wcnt[i]+=wcnt[i-1];
		for(int i=m;i;--i)wb[wcnt[wa[i].y]--]=wa[i];
		memset(wcnt,0,sizeof(wcnt));
		for(int i=1;i<=m;++i)++wcnt[wb[i].x];
		for(int i=1;i<=tot;++i)wcnt[i]+=wcnt[i-1];
		for(int i=m;i;--i)wa[wcnt[wb[i].x]--]=wb[i];
		tot=0;
		for(int i=1;i<=m;++i)rk[wa[i].id]=(tot+=(wa[i].x!=wa[i-1].x || wa[i].y!=wa[i-1].y));
		if(tot==m)break;
	}
	for(int i=1;i<=m;++i)sa[rk[i]]=i;
	a[0]=-1;
	int k=0;
	for(int i=1;i<=m;++i)
	{
		if(k)--k;
		for(int j=sa[rk[i]-1];i+k<=m && j+k<=m && a[i+k]==a[j+k];++k);
		height[rk[i]]=k;
	}
}

int _log2[MAXN],rmq[MAXN][MAXK];
void init_rmq()
{
	_log2[1]=0;
	for(int i=2;i<=m;++i)_log2[i]=_log2[i-1]+(i==1<<(_log2[i-1]+1));
	for(int i=1;i<=m;++i)rmq[i][0]=height[i];
	for(int j=1;j<MAXK;++j)
		for(int i=1;i<=m-(1<<j)+1;++i)
			rmq[i][j]=min(rmq[i][j-1],rmq[i+(1<<(j-1))][j-1]);
}
inline int RMQ(int l,int r)
{
	int t=_log2[r-l+1];
	return min(rmq[l][t],rmq[r-(1<<t)+1][t]);
}

int vs[MAXN],sum[MAXN*41],lch[MAXN*41],rch[MAXN*41],stot;
int modify(int id,int l,int r,int x,int c)
{
	int rt=++stot;
	sum[rt]=sum[id]+c;
	if(l==r)return rt;
	int mid=(l+r)>>1;
	if(x<=mid)lch[rt]=modify(lch[id],l,mid,x,c),rch[rt]=rch[id];
	else lch[rt]=lch[id],rch[rt]=modify(rch[id],mid+1,r,x,c);
	return rt;
}
int query(int lid,int rid,int l,int r,int ql,int qr)
{
	if(l==ql && r==qr)return sum[rid]-sum[lid];
	int mid=(l+r)>>1;
	if(qr<=mid)return query(lch[lid],lch[rid],l,mid,ql,qr);
	if(ql>mid)return query(rch[lid],rch[rid],mid+1,r,ql,qr);
	return query(lch[lid],lch[rid],l,mid,ql,mid)+query(rch[lid],rch[rid],mid+1,r,mid+1,qr);
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
	//freopen("code.out","w",stdout);
	#endif
	int Q,l,r,x;
	readint(n);readint(Q);
	for(int i=1;i<=n;++i)
	{
		scanf("%s",str+1);
		int len=strlen(str+1);
		for(int j=1;j<=len;++j)a[j+m]=str[j]-'a';
		lft[i]=m+1;
		rgt[i]=(m+=len);
		a[++m]=25+i;
	}
	buildsa();
//for(int i=1;i<=m;++i)printf("%-3d:%-3d %-3d %-3d %-3d\n",i,a[i],rk[i],sa[i],height[i]); 
	init_rmq();
	for(int i=1;i<=n;++i)
	{
		int L=1,R=rk[lft[i]]-1,mid,ans=rk[lft[i]];
		while(L<=R)
		{
			mid=(L+R)>>1;
			if(RMQ(mid+1,rk[lft[i]])>=rgt[i]-lft[i]+1) R=mid-1,ans=mid;
			else L=mid+1;
		}
		lrk[i]=ans;
		
		L=rk[lft[i]]+1,R=m,ans=rk[lft[i]];
		while(L<=R)
		{
			mid=(L+R)>>1;
			if(RMQ(rk[lft[i]]+1,mid)>=rgt[i]-lft[i]+1) L=mid+1,ans=mid;
			else R=mid-1;
		}
		rrk[i]=ans;
//cerr<<lrk[i]<<" "<<rrk[i]<<endl;
	}
	for(int i=1;i<=m;++i)
		vs[i]=modify(vs[i-1],1,m,rk[i],1);
	
	while(Q--)
	{
		readint(l);readint(r);readint(x);
		printf("%d\n",query(vs[lft[l]-1],vs[rgt[r]],1,m,lrk[x],rrk[x]));
	}
	return 0;
}