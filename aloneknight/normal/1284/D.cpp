#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int n,o,b[N],tg[N<<2];
vector<int>g1[N],g2[N];
struct st{int l1,r1,l2,r2;}p[N];
inline void dn(int x){if(tg[x])tg[x<<1]=1,tg[x<<1|1]=1;}
void upd(int x,int l,int r,int tl,int tr)
{
	if(tl<=l&&r<=tr){tg[x]=1;return;}
	int mid=l+r>>1;dn(x);
	if(tl<=mid)upd(x<<1,l,mid,tl,tr);
	if(tr>mid)upd(x<<1|1,mid+1,r,tl,tr);
}
int qry(int x,int l,int r,int tl,int tr)
{
	if(tl<=l&&r<=tr)return tg[x];
	int mid=l+r>>1,res=0;dn(x);
	if(tl<=mid)res|=qry(x<<1,l,mid,tl,tr);
	if(tr>mid)res|=qry(x<<1|1,mid+1,r,tl,tr);
	return res;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d%d",&p[i].l1,&p[i].r1,&p[i].l2,&p[i].r2);
		b[++o]=p[i].l1;b[++o]=p[i].r1;b[++o]=p[i].l2;b[++o]=p[i].r2;
		b[++o]=p[i].l1+1;
		b[++o]=p[i].r1-1;
		b[++o]=p[i].l2+1;
		b[++o]=p[i].r2-1;
	}
	sort(b+1,b+o+1);o=unique(b+1,b+o+1)-b-1;
	for(int i=1;i<=n;i++)
	{
		p[i].l1=lower_bound(b+1,b+o+1,p[i].l1)-b;
		p[i].r1=lower_bound(b+1,b+o+1,p[i].r1)-b;
		p[i].l2=lower_bound(b+1,b+o+1,p[i].l2)-b;
		p[i].r2=lower_bound(b+1,b+o+1,p[i].r2)-b;
	}
	for(int i=1;i<=n;i++)
	{
		g2[p[i].r1].push_back(i);
		g1[p[i].l1].push_back(i);
	}
	for(int i=1;i<=o;i++)
	{
		for(int j=0;j<g1[i].size();j++)
		{
			int x=g1[i][j];
			if(qry(1,1,o,p[x].l2,p[x].r2))
			{
				puts("NO");
				return 0;
			}
		}
		for(int j=0;j<g2[i].size();j++)
		{
			int x=g2[i][j];
			upd(1,1,o,p[x].l2,p[x].r2);
		}
	}
	memset(tg,0,sizeof(tg));
	for(int i=1;i<=o;i++)g1[i].clear(),g2[i].clear();
	for(int i=1;i<=n;i++)
	{
		swap(p[i].l1,p[i].l2);
		swap(p[i].r1,p[i].r2);
	}
	for(int i=1;i<=n;i++)
	{
		g2[p[i].r1].push_back(i);
		g1[p[i].l1].push_back(i);
	}
	for(int i=1;i<=o;i++)
	{
		for(int j=0;j<g1[i].size();j++)
		{
			int x=g1[i][j];
			if(qry(1,1,o,p[x].l2,p[x].r2))
			{
				puts("NO");
				return 0;
			}
		}
		for(int j=0;j<g2[i].size();j++)
		{
			int x=g2[i][j];
			upd(1,1,o,p[x].l2,p[x].r2);
		}
	}
	puts("YES");
	return 0;
}