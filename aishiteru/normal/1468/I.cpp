#include<bits/stdc++.h>
using namespace std; 
const int N=500005,M=1000000007;
const long double PI=3.1415926535897932384626;
int n,m,i,ax,ay,bx,by,j;
struct str{
	int x,y;
}a,b,c,d;
vector<str> g;
void Add(int x,int y)
{
	g.push_back((str){x,y});
	//cout<<x<<' '<<y<<endl;
	if(g.size()>n)
	{
		puts("NO");
		exit(0);
	}
}
long double yy;
bool flag;
bool jd(str a,str b,int i)
{
	if(i<min(a.x,b.x)||i>max(a.x,b.x))
		return false;
	//if(i==1)
	//	cout<<i<<' '<<min(a.x,b.x)<<' '<<max(a.x,b.x)<<endl;
	if(a.x==b.x)
		return flag=false;
	//cout<<i<<endl;
	long double k=(b.y-a.y)/(long double)(b.x-a.x);
	long double e=a.y-k*a.x;
	yy=k*i+e;
	return true;
}
void Add2(str a)
{
	int i;
	int d=abs(__gcd(a.x,a.y));
	for(i=1;i<d;++i)
		Add(a.x/d*i,a.y/d*i);
}
int xqz(long double x)
{
	if(x<0)
		return ((int)x)-1;
	else
		return (int)x;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&n);
	scanf("%d %d",&ax,&ay);
	scanf("%d %d",&bx,&by);
	if(1ll*ax*by-1ll*ay*bx==0)
	{
		puts("NO");
		return 0;
	}
	Add(0,0);
	a=(str){0,0};
	b=(str){ax,ay};
	c=(str){bx,by};
	d=(str){ax+bx,ay+by};
	for(i=-1000000;i<=1000000;++i)
	{
		long double mxy=-10000000,mny=10000000;
		flag=true;
		if(jd(a,b,i))
		{
			mxy=max(mxy,yy);
			mny=min(mny,yy);
		}
		if(jd(a,c,i))
		{
			mxy=max(mxy,yy);
			mny=min(mny,yy);
		}
		if(jd(d,b,i))
		{
			mxy=max(mxy,yy);
			mny=min(mny,yy);
		}
		if(jd(d,c,i))
		{
			mxy=max(mxy,yy);
			mny=min(mny,yy);
		}
		if(flag)
			for(j=xqz(mny+1.00000001);j<=xqz(mxy-0.00000001);++j)
				Add(i,j);
	}
	Add2(b);
	Add2(c);
	if(g.size()==n)
	{
		puts("YES");
		for(auto it:g)
			printf("%d %d\n",it.x,it.y);
	}
	else
		puts("NO");
}