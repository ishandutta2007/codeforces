#include<bits/stdc++.h>
using namespace std;
long long a,b,c,opp,q,w,o,h[200001],si[200001],son[200001],de[200001],fa[200001],f[200001],id[200001],cnt;
long double d[200001],e,dp[200001][2],sum[200001][2];
struct p
{
	long long q,w;
}l[400001];
struct pp
{
	long double v,ta;
	long long l,r;
}g[1600001];
void add(long long qq,long long ww)
{
	o++;
	l[o].q=ww;
	l[o].w=h[qq];
	h[qq]=o;
}
void dfs(long long qq,long long ww)
{
	dp[qq][0]++;
	for(int i=h[qq];i;i=l[i].w)
	{
		if(l[i].q!=ww)
		{
			dfs(l[i].q,qq);
			dp[qq][1]+=dp[l[i].q][1]+dp[l[i].q][0];
			dp[qq][0]+=dp[l[i].q][1]+dp[l[i].q][0]-(1-d[l[i].q]);
		}
	}
	sum[qq][1]=dp[qq][1];sum[qq][0]=dp[qq][0];
	dp[qq][1]*=d[qq];dp[qq][0]*=(1.00000-d[qq]);
}
void dfs1(long long qq,long long ww)
{
	fa[qq]=ww;
	de[qq]=de[ww]+1;
	si[qq]=1;
	long long gg=0;
	for(int i=h[qq];i;i=l[i].w)
	{
		if(l[i].q!=ww)
		{
			dfs1(l[i].q,qq);
			si[qq]+=si[l[i].q];
			if(si[l[i].q]>gg)
			{
				gg=si[l[i].q];
				son[qq]=l[i].q;
			}
		}
	}
}
void dfs2(long long qq,long long ww)
{
	id[qq]=++cnt;
	f[qq]=ww;
	if(!son[qq]) return;
	dfs2(son[qq],ww);
	for(int i=h[qq];i;i=l[i].w)
	{
		if(de[l[i].q]>de[qq]&&l[i].q!=son[qq])
		{
			dfs2(l[i].q,l[i].q);
		}
	}
}
void pushdown(long long qq)
{
	if(g[qq].ta!=0)
	{
		g[qq<<1].v+=g[qq].ta*(g[qq<<1].r-g[qq<<1].l+1);
		g[qq<<1|1].v+=g[qq].ta*(g[qq<<1|1].r-g[qq<<1|1].l+1);
		g[qq<<1].ta+=g[qq].ta;
		g[qq<<1|1].ta+=g[qq].ta;
		g[qq].ta=0;
	}
}
void pushup(long long qq)
{
	g[qq].v=g[qq<<1].v+g[qq<<1|1].v;
}
void build(long long x,long long ll,long long rr)
{
	g[x].l=ll;g[x].r=rr;
	if(ll==rr)
	{
		return;
	}
	long long mid=((ll+rr)>>1);
	build(x<<1,ll,mid);
	build(x<<1|1,mid+1,rr);
	pushup(x);
}
void change(long long x,long long ll,long long rr,long long qq,long long ww,long double ee)
{
	pushdown(x);
	if(ll>=qq&&rr<=ww)
	{
		g[x].v+=ee*(rr-ll+1),g[x].ta+=ee;
		return;
	}
	long long mid=((ll+rr)>>1);
	if(mid>=ww) change(x<<1,ll,mid,qq,ww,ee);
	else if(mid<qq) change(x<<1|1,mid+1,rr,qq,ww,ee);
	else
	{
		change(x<<1,ll,mid,qq,ww,ee);
		change(x<<1|1,mid+1,rr,qq,ww,ee);
	}
	pushup(x);
}
void change1(long long x,long long ll,long long rr,long long qq)
{
	pushdown(x);
	if(ll==rr)
	{
		g[x].v=0;
		return;
	}
	long long mid=((ll+rr)>>1);
	if(mid>=qq) change1(x<<1,ll,mid,qq);
	else change1(x<<1|1,mid+1,rr,qq);
	pushup(x);
}
long double query(long long x,long long ll,long long rr,long long qq)
{
	pushdown(x);
	if(ll==rr)
	{
		return g[x].v;
	}
	long long mid=((ll+rr)>>1);
	if(mid>=qq)
	{
		return query(x<<1,ll,mid,qq);
	}
	return query(x<<1|1,mid+1,rr,qq);
}
void upchain(long long qq,long long ww,long double ee)
{
	while(f[qq]!=f[ww])
	{
		if(de[f[qq]]<de[f[ww]]) swap(qq,ww);
		change(1,1,a,id[f[qq]],id[qq],ee);
		qq=fa[f[qq]];
	}
	if(de[qq]>de[ww]) swap(qq,ww);
	change(1,1,a,id[qq],id[ww],ee);
}
int main()
{
//	freopen("1.in","r",stdin);
//	freopen("2.out","w",stdout);
	scanf("%lld",&a);
	for(int i=1;i<=a;i++) scanf("%Lf",&d[i]);
	for(int i=1;i<a;i++)
	{
		scanf("%lld%lld",&q,&w);q++;w++;
		add(q,w);add(w,q);
	}
	dfs(1,0);
	dfs1(1,0);
	dfs2(1,1);
	build(1,1,a);
	scanf("%lld",&b);
	fa[0]=0;
	for(int i=1;i<=b;i++)
	{
		scanf("%lld%Lf",&q,&e);q++;
		long double yy=query(1,1,a,id[q]);change1(1,1,a,id[q]);
		sum[q][0]+=yy;sum[q][1]+=yy;
		dp[q][0]+=yy*(1.00000-d[q]);dp[q][1]+=yy*d[q];
		long double tt=dp[q][0]+dp[q][1];
		dp[q][0]=(1.00000-e)*sum[q][0];
		dp[q][1]=e*sum[q][1];
		tt-=dp[q][0]+dp[q][1];tt=-tt;
		long double tr;
		if(fa[q]!=0)
		{
			yy=query(1,1,a,id[fa[q]]);change1(1,1,a,id[fa[q]]);
			sum[fa[q]][0]+=yy;sum[fa[q]][1]+=yy;
			dp[fa[q]][0]+=yy*(1.00000-d[fa[q]]);dp[fa[q]][1]+=yy*d[fa[q]];
			tr=-dp[fa[q]][0]-dp[fa[q]][1];
			sum[fa[q]][0]+=(e-d[q])+tt;sum[fa[q]][1]+=tt;
			dp[fa[q]][0]+=(1.00000-d[q])*(1.00000-d[fa[q]]);dp[fa[q]][0]-=(1.00000-d[fa[q]])*(1.00000-e);
			dp[fa[q]][0]+=(1.00000-d[fa[q]])*tt;dp[fa[q]][1]+=d[fa[q]]*tt;
			tr+=dp[fa[q]][0]+dp[fa[q]][1];
		}
		if(fa[fa[q]]!=0) upchain(1,fa[fa[q]],tr);
		d[q]=e;
		yy=query(1,1,a,id[1]);
		printf("%.5Lf\n",dp[1][0]+dp[1][1]+yy);
//		if(i==107){
//		for(int j=1;j<=a;j++)
//		{
//			cout<<dp[j][0]+dp[j][1]+query(1,1,a,id[j])<<" ";
//		}
//		cout<<"\n";
//	}
	}
	return 0;
}