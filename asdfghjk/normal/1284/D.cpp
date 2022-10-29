#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct mode
{
	int id,num,ty;
}h[400005];
struct node
{
	int sa,ea,sb,eb;
}p[100005],q[100005];
int n,cnt,l,i,j,k,x,y,c[4][400005];
bool tk(mode a,mode b)
{
	return a.num<b.num;
}
bool cmp(node a,node b)
{
	return a.sa<b.sa;
}
bool cmq(node a,node b)
{
	return a.ea<b.ea;
}
bool Cmp(node a,node b)
{
	return a.sb<b.sb;
}
bool Cmq(node a,node b)
{
	return a.eb<b.eb;
}
void add(int id,int x,int y)
{
	while(x<=l)
	{
		c[id][x]+=y;
		x+=x&-x;
	}
}
int sum(int id,int x)
{
	int rtn=0;
	while(x>=1)
	{
		rtn+=c[id][x];
		x-=x&-x;
	}
	return rtn;
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d%d%d%d",&j,&k,&x,&y);
		h[++cnt]=(mode){i,j,1};
		h[++cnt]=(mode){i,k,2};
		h[++cnt]=(mode){i,x,3};
		h[++cnt]=(mode){i,y,4};
	}
	sort(h+1,h+1+cnt,tk);
	for(i=1;i<=cnt;i=j)
	{
		++l;
		for(j=i;j<=cnt&&h[i].num==h[j].num;++j)
			if(h[j].ty==1)
				p[h[j].id].sa=l;
			else if(h[j].ty==2)
				p[h[j].id].ea=l;
			else if(h[j].ty==3)
				p[h[j].id].sb=l;
			else
				p[h[j].id].eb=l;
	}
	for(i=1;i<=n;++i)
		q[i]=p[i];
	sort(p+1,p+1+n,cmp);
	sort(q+1,q+1+n,cmq);
	for(i=j=1,k=0;i<=n;++i)
	{
		for(;q[j].ea<p[i].sa;++j)
		{
			add(0,q[j].sb,1);
			add(1,q[j].eb,1);
		}
		if(sum(1,p[i].sb-1)-sum(0,p[i].eb)!=0)
		{
			printf("NO");
			return 0;
		}
	}
	sort(p+1,p+1+n,Cmp);
	sort(q+1,q+1+n,Cmq);
	for(i=j=1,k=0;i<=n;++i)
	{
		for(;q[j].eb<p[i].sb;++j)
		{
			add(2,q[j].sa,1);
			add(3,q[j].ea,1);
		}
		if(sum(3,p[i].sa-1)-sum(2,p[i].ea)!=0)
		{
			printf("NO");
			return 0;
		}
	}
	printf("YES");
	return 0;
}