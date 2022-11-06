#include<bits/stdc++.h>
using namespace std;
long long a,b,fa[500001][21],d[500001],q[500001],w[500001],c,o=1,h[500001],dfn[500001],low[500001],cnt,cn,st[500001],e[500001],cnt1,v[500001],de[500001],de1[500001];
long long lg[500001],vv[1200001];
struct p
{
	long long q,w;
}l[2000001];
struct pp
{
	long long q,w,e;
};
vector<long long> qu[500001];
void add(long long qq,long long ww)
{
	o++;
	l[o].q=ww;
	l[o].w=h[qq];
	h[qq]=o;
}
void dfs(long long qq,long long ww)
{
	dfn[qq]=low[qq]=++cn;
	for(int i=h[qq];i;i=l[i].w)
	{
		if(l[i].q==ww) continue;
		if(!dfn[l[i].q])
		{
			st[++cnt]=i;
			dfs(l[i].q,qq);
			low[qq]=min(low[qq],low[l[i].q]);
			if(low[l[i].q]>=dfn[qq])
			{
				long long tt=cnt;
				++cnt1;
				while(st[cnt]!=i)
				{
					e[cnt1]++;
					qu[cnt1].push_back(l[st[cnt]].q);
					cnt--;
				}
				e[cnt1]+=2;
				qu[cnt1].push_back(l[st[cnt]].q);qu[cnt1].push_back(qq);
				cnt--;
			}
		}
		else
		{
			low[qq]=min(low[qq],dfn[l[i].q]);
		}
	}
}
void dfs1(long long qq,long long ww)
{
	if(ww<=a) de[qq]=de[ww]+1;
	else de[qq]=de[ww];
	if(ww==0) de[qq]=0;
	fa[qq][0]=ww;de1[qq]=de1[ww]+1;
	for(int i=1;i<=20;i++) fa[qq][i]=fa[fa[qq][i-1]][i-1];
	for(int i=h[qq];i;i=l[i].w)
	{
		if(l[i].q!=ww)
		{
			dfs1(l[i].q,qq);
		}
	}
}
pp LCA(long long qq,long long ww)
{
	if(de1[qq]<de1[ww]) swap(qq,ww);
	while(de1[qq]>de1[ww])
	{
		qq=fa[qq][lg[de1[qq]-de1[ww]]-1];
	}
	if(qq==ww) return pp{qq,ww,ww};
	for(int i=20;i>=0;i--)
	{
		if(fa[qq][i]!=fa[ww][i])
		{
			qq=fa[qq][i];
			ww=fa[ww][i];
		}
	}
	return pp{qq,ww,fa[qq][0]};
}
void dfs2(long long qq,long long ww)
{
	long long la=0;
	for(int i=h[qq];i;i=l[i].w)
	{
		if(l[i].q!=ww&&!vv[i]&&v[l[i].q])
		{
			vv[i]=vv[i^1]=1;
			if(la) l[la].w=l[i].w;
			else h[qq]=l[i].w;
			dfs2(l[i].q,qq);
			la=i;
		}
	}
}
map<long long,long long> qu1[500001];
int main()
{
	scanf("%lld%lld%lld",&a,&b,&c);
	for(int i=1;i<=b;i++)
	{
		scanf("%lld%lld",&q[i],&w[i]);
		add(q[i],w[i]);add(w[i],q[i]);
		qu1[q[i]][w[i]]=qu1[w[i]][q[i]]=i*2;
	}
	for(int i=1;i<=500000;i++) lg[i]=lg[i-1]+((1<<lg[i-1])==i);
	for(int i=1;i<=a;i++)
	{
		if(!dfn[i]) dfs(i,0);
	}
	for(int i=1;i<=cnt1;i++)
	{
		if(e[i]<=2) continue;
		for(int j=0;j<qu[i].size();j++)
		{
			for(int k=0;k<qu[i].size();k++)
			{
				if(j==k) continue;
				vv[qu1[qu[i][j]][qu[i][k]]]=vv[qu1[qu[i][j]][qu[i][k]]^1]=1;
			}
		}
	}
	o=0;memset(h,0,sizeof(h));
	for(int i=1;i<=b;i++)
	{
		if(!vv[i*2]) add(q[i],w[i]),add(w[i],q[i]);
	}
	long long ty=a;
	for(int i=1;i<=cnt1;i++)
	{
		if(e[i]>2)
		{
			ty++;
			for(int j=0;j<qu[i].size();j++) add(qu[i][j],ty),add(ty,qu[i][j]);
		}
	}
	dfs1(1,0);
	for(int i=1;i<=c;i++)
	{
		scanf("%lld%lld",&q[i],&w[i]);
		if(de1[q[i]]<de1[w[i]]) swap(q[i],w[i]);
		pp gg=LCA(q[i],w[i]);
		if(gg.w==gg.e)
		{
			printf("%lld\n",de[q[i]]-de[gg.e]);
		}
		else
		{
			if(de[gg.q]==de[gg.e]&&de[gg.w]==de[gg.e])
			{
				printf("%lld\n",de[q[i]]+de[w[i]]-de[gg.e]*2+1);
			}
			else printf("%lld\n",de[q[i]]+de[w[i]]-de[gg.e]*2);
		}
	}
	return 0;
}
//5 7 2
//1 2
//1 3
//1 4
//2 3
//2 4
//3 4
//1 5
//1 4
//2 5