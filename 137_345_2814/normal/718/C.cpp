#include<cstdio>
#include<algorithm>
using namespace std;
int n,v[100001],m;
struct matrix{
	long long m[3][3];
};
matrix fj,E,RE;
matrix mul(matrix a,matrix b)
{
	matrix lsj;
	for(int i=1;i<=2;i++)
	for(int j=1;j<=2;j++)
	lsj.m[i][j]=0;
	for(int i=1;i<=2;i++)
	for(int j=1;j<=2;j++)
	for(int k=1;k<=2;k++)
	lsj.m[i][j]=(lsj.m[i][j]+a.m[i][k]*b.m[k][j]);
	for(int i=1;i<=2;i++)
	for(int j=1;j<=2;j++)
	lsj.m[i][j]%=1000000007;
	return lsj;
}
matrix Pow(matrix a,long long b)
{
	matrix lsj;
	for(int i=1;i<=2;i++)
	for(int j=1;j<=2;j++)
	lsj.m[i][j]=(i==j);
	while(b)
	{
		if(b&1)
		lsj=mul(lsj,a);
		a=mul(a,a);
		b>>=1;
	}
	return lsj;
}
pair<int,int> op(int i,int j,long long k)
{
	matrix p,p1;
	p.m[1][1]=p.m[1][2]=p.m[2][1]=1;
	p.m[2][2]=0;
	p=Pow(p,k);
	p1.m[1][1]=i;
	p1.m[2][1]=j;
	p1.m[1][2]=p1.m[2][2]=0;
	p1=mul(p,p1);
	return make_pair((int)p1.m[1][1],(int)p1.m[2][1]);
}
struct edge{
	int l,r,s1,s2;
	matrix lazy;
}e[400001];
void pushup(int m)
{
	e[m].s1=(e[m<<1].s1+e[m<<1|1].s1)%1000000007;
	e[m].s2=(e[m<<1].s2+e[m<<1|1].s2)%1000000007;
}
void push(int m)
{
	e[m<<1].lazy=mul(e[m<<1].lazy,e[m].lazy);
	e[m<<1|1].lazy=mul(e[m<<1|1].lazy,e[m].lazy);
	matrix p1;
	p1.m[1][1]=e[m<<1].s1;
	p1.m[2][1]=e[m<<1].s2;
	p1.m[1][2]=p1.m[2][2]=0;
	p1=mul(e[m].lazy,p1);
	e[m<<1].s1=p1.m[1][1];
	e[m<<1].s2=p1.m[2][1];
	p1.m[1][1]=e[m<<1|1].s1;
	p1.m[2][1]=e[m<<1|1].s2;
	p1.m[1][2]=p1.m[2][2]=0;
	p1=mul(e[m].lazy,p1);
	e[m<<1|1].s1=p1.m[1][1];
	e[m<<1|1].s2=p1.m[2][1];
	e[m].lazy=RE;
}
void build(int m,int l,int r)
{
	e[m].l=l;
	e[m].r=r;
	e[m].lazy=RE;
	if(l==r)
	{
		pair<int,int> p=op(1,0,v[l]-1);
		e[m].s1=p.first;
		e[m].s2=p.second;
		return;
	}
	int mid=(l+r)>>1;
	build(m<<1,l,mid);
	build(m<<1|1,mid+1,r);
	pushup(m);
}
void add(int m,int l,int r,int d)
{
	if(e[m].l==l&&e[m].r==r)
	{
		matrix p1;
		p1.m[1][1]=e[m].s1;
		p1.m[2][1]=e[m].s2;
		p1.m[1][2]=p1.m[2][2]=0;
		p1=mul(fj,p1);
		e[m].s1=p1.m[1][1];
		e[m].s2=p1.m[2][1];
		e[m].lazy=mul(fj,e[m].lazy);
		return;
	}
	if(e[m].l==e[m].r)
	return;
	push(m);
	int mid=(e[m].l+e[m].r)>>1;
	if(l>mid)
    add(m<<1|1,l,r,d);
    else
    if(r<=mid)
    add(m<<1,l,r,d);
    else
    {
        add(m<<1,l,mid,d);
        add(m<<1|1,mid+1,r,d);
    }
    pushup(m);
}
long long que(int m,int l,int r)
{
	if(e[m].l==l&&e[m].r==r)
	return e[m].s1;
	if(e[m].l==e[m].r)
	return 0;
	push(m);
	int mid=(e[m].l+e[m].r)>>1;
	if(l>mid)
    return que(m<<1|1,l,r);
    else
    if(r<=mid)
    return que(m<<1,l,r);
    else
    return (que(m<<1,l,mid)+que(m<<1|1,mid+1,r));
}
int main()
{
	int a,b,c,d;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	scanf("%d",&v[i]);
	E.m[1][1]=E.m[1][2]=E.m[2][1]=RE.m[1][1]=RE.m[2][2]=1;
	E.m[2][2]=RE.m[1][2]=RE.m[2][1]=0;
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		if(a==1)
		{
			scanf("%d",&d);
			fj=Pow(E,d);
			add(1,b,c,d);
		}
		else
		printf("%lld\n",que(1,b,c)%1000000007);
	}
}