#include<bits/stdc++.h>
using namespace std;
int ex[300005],ey[300005],num[300005],i,j,k,n,m,s[300005],ans[100005],op,vis[300005],now,l,r;
struct str{
	int x,y,p;
}a[300005];
bool cmp(str a,str b)
{
	if(a.x==b.x)
		return a.y<b.y;
	return a.x<b.x;
}
int gcd(int x,int y)
{
	if(y==0)
		return x;
	return gcd(y,x%y);
}
struct query{
	int l,r,x;
}q[100005];
bool cmp2(query a,query b)
{
	if(a.l/op!=b.l/op)
		return a.l/op<b.l/op;
	return a.r<b.r;
}
void Add(int x)
{
	if(vis[x]==0)
		now++;
	vis[x]++;
}
void Dec(int x)
{
	if(vis[x]==1)
		now--;
	vis[x]--;
}
int main()
{
	scanf("%d",&n);
	op=sqrt(n*1.0);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&m);
		for(j=0;j<m;j++)
			scanf("%d %d",&ex[j],&ey[j]);
		for(j=0;j<m;j++)
		{
			int aa=ex[(j+1)%m]-ex[j],b=ey[(j+1)%m]-ey[j];
			int g=gcd(aa,b);
			if(g<0)
				g=-g;
			aa/=g;
			b/=g;
			k++;
			a[k]=(str){aa,b,k};
		}
		s[i]=s[i-1]+m;
	}
	sort(a+1,a+1+k,cmp);
	for(i=1;i<=k;)
	{
		for(j=i;j<=k&&a[i].x==a[j].x&&a[i].y==a[j].y;j++)
			num[a[j].p]=i;
		i=j;
	}
	scanf("%d",&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d %d",&q[i].l,&q[i].r);
		q[i].x=i;
		q[i].l=s[q[i].l-1]+1;
		q[i].r=s[q[i].r];
	}
	sort(q+1,q+1+m,cmp2);
	l=1;r=0;
	for(i=1;i<=m;i++)
	{
		while(r<q[i].r)
		{
			r++;
			Add(num[r]);
		}
		while(r>q[i].r)
		{
			Dec(num[r]);
			r--;
		}
		while(l<q[i].l)
		{
			Dec(num[l]);
			l++;
		}
		while(l>q[i].l)
		{
			l--;
			Add(num[l]);
		}
		ans[q[i].x]=now;
	}
	for(i=1;i<=m;i++)
		printf("%d\n",ans[i]);
}