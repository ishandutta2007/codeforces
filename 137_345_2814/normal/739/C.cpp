#include<cstdio>
#include<algorithm>
using namespace std;
struct ed{
	int l,r,fl[6];
}e[1200012];
long long v[300001];
void pushup(int m)
{
	for(int i=1;i<=5;i++)
	e[m].fl[i]=0;
	e[m].fl[1]=e[m<<1].fl[1];
	e[m].fl[3]=e[m<<1].fl[3];
	if(e[m<<1].fl[1]>=e[m<<1].r-e[m<<1].l+1)
	e[m].fl[1]=e[m<<1].fl[1]+e[m<<1|1].fl[1];
	e[m].fl[2]=e[m<<1|1].fl[2];
	e[m].fl[4]=e[m<<1|1].fl[4];
	if(e[m<<1|1].fl[2]>=e[m<<1|1].r-e[m<<1|1].l+1)
	e[m].fl[2]=e[m<<1].fl[2]+e[m<<1|1].fl[2];
	if(e[m<<1].fl[2]>=e[m<<1].r-e[m<<1].l+1)
	e[m].fl[3]=e[m<<1].fl[2]+e[m<<1|1].fl[3];
	if(e[m<<1].fl[4]>=e[m<<1].r-e[m<<1].l+1)
	e[m].fl[3]=e[m<<1].fl[4]+e[m<<1|1].fl[1];
	if(e[m<<1|1].fl[1]>=e[m<<1|1].r-e[m<<1|1].l+1)
	e[m].fl[4]=e[m<<1].fl[4]+e[m<<1|1].fl[1];
	if(e[m<<1|1].fl[3]>=e[m<<1|1].r-e[m<<1|1].l+1)
	e[m].fl[4]=e[m<<1].fl[2]+e[m<<1|1].fl[3];
	e[m].fl[5]=max(e[m<<1].fl[2]+e[m<<1|1].fl[3],e[m<<1].fl[4]+e[m<<1|1].fl[1]);
	e[m].fl[5]=max(e[m].fl[5],e[m<<1].fl[2]+e[m<<1|1].fl[1]);
	if(e[m<<1].fl[2]==e[m<<1].r-e[m<<1].l+1) e[m].fl[3]=max(e[m].fl[3],e[m<<1].fl[2]+e[m<<1|1].fl[1]);
	if(e[m<<1|1].fl[1]==e[m<<1|1].r-e[m<<1|1].l+1) e[m].fl[4]=max(e[m].fl[4],e[m<<1].fl[2]+e[m<<1|1].fl[1]);
	e[m].fl[0]=max(max(max(max(e[m].fl[1],e[m].fl[2]),e[m].fl[3]),e[m].fl[4]),e[m].fl[5]);
	e[m].fl[0]=max(e[m].fl[0],max(e[m<<1].fl[0],e[m<<1|1].fl[0]));
}
int n,p;
void build(int m,int l,int r)
{
	e[m].l=l;
	e[m].r=r;
	if(l==r)
	{
		for(int i=0;i<=5;i++)
		e[m].fl[i]=0;
		if(v[e[m].r]>0)
		e[m].fl[2]=e[m].fl[0]=1;
		if(v[e[m].r]<0)
		e[m].fl[1]=e[m].fl[0]=1;
		return;
	}
	int mid=(l+r)>>1;
	build(m<<1,l,mid);
	build(m<<1|1,mid+1,r);
	pushup(m);
}
void add(int m,int s)
{
	if(e[m].l==e[m].r)
	{
		for(int i=0;i<=5;i++)
		e[m].fl[i]=0;
		if(v[e[m].r]>0)
		e[m].fl[2]=e[m].fl[0]=1;
		if(v[e[m].r]<0)
		e[m].fl[1]=e[m].fl[0]=1;
		return;
	}
	int mid=(e[m].l+e[m].r)>>1;
	if(s>mid)
	add(m<<1|1,s);
	else
	add(m<<1,s);
	pushup(m);
}
int main()
{
	int a=0,b,c;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&b);
		v[i-1]=b-a;
		a=b;
	}
	scanf("%d",&p);
	if(n==1)
	{
	for(int i=1;i<=n;i++)
	printf("1\n");
	return 0 ;
	}
	build(1,1,n-1);
	for(int i=1;i<=p;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		v[a-1]+=c;
		v[b]-=c;
		if(a>1)
		add(1,a-1);
		if(b<n)
		add(1,b);
		printf("%d\n",e[1].fl[0]+1);
	}
}//zz