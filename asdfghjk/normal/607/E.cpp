#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
const int N=200005;
struct node
{
	int id,l,r;
}g[N];
struct mode
{
	int id,ty;
	long double num;
}p[N];
int n,m,cnt,i,j,k,l,id[N];
long double lt,rt,mid,X0,Y0,a[N],b[N],A,B,C,w1[N],w2[N],ans;
long long w,tot,c[N];
vector<int> vct[N*5];
long double dist(int i,int j)
{
	i=id[i],j=id[j];
	if(fabs(a[i]-a[j])<1e-10)
		return mid;
	long double X=(b[j]-b[i])/(a[i]-a[j]),Y=a[i]*X+b[i];
	return sqrt((X-X0)*(X-X0)+(Y-Y0)*(Y-Y0));
}
bool cmp(mode a,mode b)
{
	return a.num<b.num;
}
bool cmq(node a,node b)
{
	if(a.l!=b.l)
		return a.l<b.l;
	return a.r<b.r;
}
void add(int x,int y)
{
	while(x<=l)
	{
		c[x]+=y;
		x+=x&-x;
	}
}
long long sum(int x)
{
	long long rtn=0;
	while(x)
	{
		rtn+=c[x];
		x-=x&-x;
	}
	return rtn;
}
void update(int o,int l,int r,int x,int y)
{
	vct[o].push_back(y);
	if(l==r)
		return;
	int mid=l+r>>1;
	if(x<=mid)
		update(o<<1,l,mid,x,y);
	else
		update(o<<1|1,mid+1,r,x,y);
}
void work(int o,int l,int r,int x,int y,int z)
{
	if(l>=x&&r<=y)
	{
		for(int i=vct[o].size()-1;i>=0;--i)
		{
			ans+=dist(vct[o][i],z);
		}
		tot+=vct[o].size();
		return;
	}
	int mid=l+r>>1;
	if(x<=mid)
		work(o<<1,l,mid,x,y,z);
	if(y>mid)
		work(o<<1|1,mid+1,r,x,y,z);
}
int main()
{
	scanf("%d",&n);
	scanf("%d%d%d",&i,&j,&m);
	X0=(long double)i/1000.0,Y0=(long double)j/1000.0;
	int num=0;
	for(i=1;i<=n;++i)
	{
		scanf("%d%d",&j,&k);
		a[i]=(long double)j/1000.0,b[i]=(long double)k/1000.0;
		if(a[i]*X0+b[i]==Y0)
			++num;
	}
	if(1ll*num*(num-1)/2>=m)
	{
		printf("0.0");
		return 0;
	}
	lt=0,rt=1e10;
	while(rt-lt>1e-8)
	{
		mid=(lt+rt)/2;
		cnt=0;
		for(i=1;i<=n;++i)
		{
			A=a[i]*a[i]+1,B=2*a[i]*(b[i]-Y0)-2*X0,C=X0*X0+(b[i]-Y0)*(b[i]-Y0)-mid*mid;
			if(B*B-4*A*C<0)
				continue;
			++cnt;
			g[cnt].id=cnt;
			id[cnt]=i;
			w1[cnt]=atan2((-B+sqrt(B*B-4*A*C))/(2.0*A)*a[i]+b[i]-Y0,(-B+sqrt(B*B-4*A*C))/(2.0*A)-X0);
			w2[cnt]=atan2((-B-sqrt(B*B-4*A*C))/(2.0*A)*a[i]+b[i]-Y0,(-B-sqrt(B*B-4*A*C))/(2.0*A)-X0);
			if(w1[cnt]>w2[cnt])
				swap(w1[cnt],w2[cnt]);
		}
		for(i=1;i<=cnt;++i)
			p[2*i-1]=(mode){i,0,w1[i]},p[2*i]=(mode){i,1,w2[i]};
		sort(p+1,p+1+2*cnt,cmp);
		l=0;
		for(i=1;i<=2*cnt;i=j)
		{
			++l;
			for(j=i;j<=2*cnt&&p[i].num==p[j].num;++j)
				if(p[j].ty==0)
					g[p[j].id].l=l;
				else
					g[p[j].id].r=l;
		}
		sort(g+1,g+1+cnt,cmq);
		for(i=1;i<=l;++i)
			c[i]=0;
		w=0;
		for(i=1;i<=cnt;++i)
		{
			w+=sum(g[i].r)-sum(g[i].l-1);
			add(g[i].r,1);
		}
		if(w>=m)
			rt=mid;
		else
			lt=mid;
	}
	mid=rt-(1e-8);
	cnt=0;
	for(i=1;i<=n;++i)
	{
		A=a[i]*a[i]+1,B=2*a[i]*(b[i]-Y0)-2*X0,C=X0*X0+(b[i]-Y0)*(b[i]-Y0)-mid*mid;
		if(B*B-4*A*C<0)
			continue;
		++cnt;
		g[cnt].id=cnt;
		id[cnt]=i;
		w1[cnt]=atan2((-B+sqrt(B*B-4*A*C))/(2.0*A)*a[i]+b[i]-Y0,(-B+sqrt(B*B-4*A*C))/(2.0*A)-X0);
		w2[cnt]=atan2((-B-sqrt(B*B-4*A*C))/(2.0*A)*a[i]+b[i]-Y0,(-B-sqrt(B*B-4*A*C))/(2.0*A)-X0);
		if(w1[cnt]>w2[cnt])
			swap(w1[cnt],w2[cnt]);
	}
	for(i=1;i<=cnt;++i)
		p[2*i-1]=(mode){i,0,w1[i]},p[2*i]=(mode){i,1,w2[i]};
	sort(p+1,p+1+2*cnt,cmp);
	l=0;
	for(i=1;i<=2*cnt;i=j)
	{
		++l;
		for(j=i;j<=2*cnt&&p[i].num==p[j].num;++j)
			if(p[j].ty==0)
				g[p[j].id].l=l;
			else
				g[p[j].id].r=l;
	}
	sort(g+1,g+1+cnt,cmq);
	for(i=1;i<=cnt;++i)
	{
		work(1,1,l,g[i].l,g[i].r,g[i].id);
		update(1,1,l,g[i].r,g[i].id);
	}
	if(tot<m)
		ans+=rt*(m-tot);
	printf("%.12lf",(double)ans);
	return 0;
}