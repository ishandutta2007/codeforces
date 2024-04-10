#include<bits/stdc++.h>
#define ls d<<1
#define rs d<<1|1

typedef long long LL;

const int N=100005;
const int MOD=998244353;
const int inf=2e9;
const double eps=1e-10;

int n,x[N],v[N],p[N],tot,q[N];
struct data{int x,y,op,val;double tim;}col[N*2];
struct mat
{
	int a[2][2];
	void clear() {memset(a,0,sizeof(a));}
}unit,t1[N*4],t2[N*4],m1[N],m2[N];

int ksm(int x,int y)
{
	int ans=1;
	while (y)
	{
		if (y&1) ans=(LL)ans*x%MOD;
		x=(LL)x*x%MOD;y>>=1;
	}
	return ans;
}

bool cmp(data a,data b)
{
	return a.tim>b.tim||fabs(a.tim-b.tim)<eps&&a.x<b.x;
}

mat mul(mat a,mat b)
{
	mat c;c.clear();
	for (int k=0;k<2;k++)
		for (int i=0;i<2;i++)
			for (int j=0;j<2;j++)
				(c.a[i][j]+=(LL)a.a[i][k]*b.a[k][j]%MOD)%=MOD;
	return c;
}

void ins1(int d,int l,int r,int x,int y,int z)
{
	if (l==r)
	{
		int pp=z==1?p[x+1]:q[x+1]%MOD;
		t1[d].a[y][z]=pp;
		return;
	}
	int mid=(l+r)/2;
	if (x<=mid) ins1(ls,l,mid,x,y,z);
	else ins1(rs,mid+1,r,x,y,z);
	t1[d]=mul(t1[ls],t1[rs]);
}

void ins2(int d,int l,int r,int x,int y,int z)
{
	if (l==r)
	{
		int pp=y==0?q[x-1]%MOD:p[x-1];
		t2[d].a[y][z]=pp;
		return;
	}
	int mid=(l+r)/2;
	if (x<=mid) ins2(ls,l,mid,x,y,z);
	else ins2(rs,mid+1,r,x,y,z);
	t2[d]=mul(t2[ls],t2[rs]);
}

mat query(int d,int l,int r,int x,int y,int op)
{
	if (x>y) return unit;
	if (x<=l&&r<=y) return op==1?t1[d]:t2[d];
	int mid=(l+r)/2;
	if (y<=mid) return query(ls,l,mid,x,y,op);
	else if (x>mid) return query(rs,mid+1,r,x,y,op);
	else return mul(query(ls,l,mid,x,y,op),query(rs,mid+1,r,x,y,op));
}

void build(int d,int l,int r)
{
	if (l==r) {t1[d]=m1[l];t2[d]=m2[l];return;}
	int mid=(l+r)/2;
	build(ls,l,mid);build(rs,mid+1,r);
	t1[d]=mul(t1[ls],t1[rs]);
	t2[d]=mul(t2[ls],t2[rs]);
}

int main()
{
	unit.a[0][0]=unit.a[1][1]=1;
	scanf("%d",&n);
	int inv=ksm(100,MOD-2)%MOD;
	for (int i=1;i<=n;i++) scanf("%d%d%d",&x[i],&v[i],&p[i]),p[i]=(LL)p[i]*inv%MOD,q[i]=(1+MOD-p[i])%MOD;
	for (int i=2;i<=n;i++)
	{
		if (v[i]>v[i-1])
		{
			tot++;
			col[tot].x=i-1;col[tot].y=i;col[tot].op=0;
			col[tot].tim=(double)1.0*(x[i]-x[i-1])/(v[i]-v[i-1]);
			col[tot].val=(LL)(x[i]-x[i-1])*ksm(v[i]-v[i-1],MOD-2)%MOD;
		}
		else if (v[i]<v[i-1])
		{
			tot++;
			col[tot].x=i-1;col[tot].y=i;col[tot].op=2;
			col[tot].tim=(double)1.0*(x[i]-x[i-1])/(v[i-1]-v[i]);
			col[tot].val=(LL)(x[i]-x[i-1])*ksm(v[i-1]-v[i],MOD-2)%MOD;
		}
		if (v[i]>=v[i-1]) m1[i-1].a[1][1]=p[i],m2[i].a[1][1]=p[i-1];
		if (v[i]<=v[i-1]) m1[i-1].a[0][0]=q[i],m2[i].a[0][0]=q[i-1];
		tot++;
		col[tot].x=i-1;col[tot].y=i;col[tot].op=1;
		col[tot].tim=(double)1.0*(x[i]-x[i-1])/(v[i]+v[i-1]);
		col[tot].val=(LL)(x[i]-x[i-1])*ksm(v[i]+v[i-1],MOD-2)%MOD;
	}
	std::sort(col+1,col+tot+1,cmp);
	for (int i=1;i<n;i++) m1[i].a[0][1]=p[i+1];
	for (int i=2;i<=n;i++) m2[i].a[0][1]=q[i-1];
	build(1,1,n);
	int ans=0;
	for (int i=1;i<=tot;i++)
	{
		mat w1=query(1,1,n,col[i].y,n-1,1),w2=query(1,1,n,2,col[i].x,2);
		int op=col[i].op,d1=op==0?0:1,d2=op==2?1:0;
		int p1=((LL)w1.a[d2][0]+(LL)w1.a[d2][1])%MOD;
		int p2=((LL)w2.a[0][d1]+(LL)w2.a[1][d1])%MOD;
		int val=(LL)p1%MOD*p2%MOD*col[i].val%MOD;
		val=(LL)val*(d1?p[col[i].x]:q[col[i].x])%MOD;
		val=(LL)val*(d2?p[col[i].y]:q[col[i].y])%MOD;
		(ans+=val)%=MOD;
		if (!col[i].op) ins1(1,1,n,col[i].x,0,0),ins2(1,1,n,col[i].y,0,0);
		else if (col[i].op==1) ins1(1,1,n,col[i].x,1,0),ins2(1,1,n,col[i].y,1,0);
		else ins1(1,1,n,col[i].x,1,1),ins2(1,1,n,col[i].y,1,1);
	}
	printf("%d\n",ans);
	return 0;
}