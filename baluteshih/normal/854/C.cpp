#include <iostream>
using namespace std;

long long ans;
long long c[300050],v[300050];

long long wmax(long long a,long long b)
{
	return c[a]>c[b] ? a : b;
}

struct node
{
	long long place;
	node *l=nullptr,*r=nullptr;
	void up()
	{
		if(l) 
		{
			if(c[l->place]>=c[r->place]) place=l->place;
			else place=r->place;
		}
	}
};

node *build(long long l,long long r)
{
	node *p=new node;
	if(l==r)
	{
		p->place=l;
		return p;
	}
	long long m=(l+r)/2;
	p->l=build(l,m),p->r=build(m+1,r);
	p->up();
	return p;
}

long long query(long long L,long long R,long long l,long long r,node *p)
{
	if(L<=l && R>=r) return p->place;
	long long m=(l+r)/2,ret=0;
	if(L<=m) ret=query(L,R,l,m,p->l);
	if(R>m) ret=wmax(ret,query(L,R,m+1,r,p->r));
	return ret;
}

void fixs(long long a,long long l,long long r,node *p)
{
	if(l==r) return;
	if(a<=(l+r)/2) fixs(a,l,(l+r)/2,p->l);
	else fixs(a,(l+r)/2+1,r,p->r);
	p->up();
}

int main()
{
	long long n,k,i,j,tmp;
	node *head;
	scanf("%lld%lld",&n,&k);
	for(i=1,c[0]=-1;i<=n;i++) scanf("%lld",&c[i]);
	head=build(1,n);
	for(i=1;i<=n;i++)
	{
		tmp=query(1,min(i+k,n),1,n,head),v[tmp]=i+k;
		ans+=(i+k-tmp)*c[tmp];
		c[tmp]=-1,fixs(tmp,1,n,head);
	}
	printf("%lld\n",ans);
	for(i=2,printf("%lld",v[1]);i<=n;i++)
		printf(" %lld",v[i]);
	puts("");
}