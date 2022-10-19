#include <iostream>
#include <algorithm>
using namespace std;
const int N=100005;
struct ban
{
	int x,q;
};

int a[N];
int n;
int t[N*4];
ban tm[N*4];
int gcd(int x,int y)
{
	if(x==0)
		return y;
	if(x>y)
		return gcd(y,x);
	return gcd(y%x,x);
}
void build(int tl,int tr,int pos)
{
	if(tl==tr)
	{
		t[pos] = a[tl];
		return;
	}
	int m=(tl+tr)/2;
	build(tl,m,pos*2);
	build(m+1,tr,pos*2+1);
	t[pos]=gcd(t[pos*2],t[pos*2+1]);
}
int get(int tl,int tr,int l,int r,int pos)
{
	if(tl==l && tr==r)
	{
		return t[pos];
	}
	int m=(tl+tr)/2;
	if(r<=m)
		return get(tl,m,l,r,pos*2);
	else if(l>m)
		return get(m+1,tr,l,r,pos*2+1);
	else
		return gcd(get(tl,m,l,m,pos*2),get(m+1,tr,m+1,r,pos*2+1));
}
/////
ban mer(ban a1,ban a2)
{
	ban res;
	if(a1.x==a2.x)
	{
		res.x = a1.x;
		res.q = a1.q + a2.q;
	}
	else
	{
		if(a1.x<a2.x)
			res=a1;
		else
			res=a2;
	}
	return res;
}
void buildm(int tl,int tr,int pos)
{
	if(tl==tr)
	{
		tm[pos].x=a[tl];
		tm[pos].q=1;
		return;
	}
	int m=(tl+tr)/2;
	buildm(tl,m,pos*2);
	buildm(m+1,tr,pos*2+1);
	tm[pos]=mer(tm[pos*2],tm[pos*2+1]);
}
ban getm(int tl,int tr,int l,int r,int pos)
{
	if(tl==l && tr==r)
	{
		return tm[pos];
	}
	int m=(tl+tr)/2;
	if(r<=m)
		return getm(tl,m,l,r,pos*2);
	else if(l>m)
		return getm(m+1,tr,l,r,pos*2+1);
	else
		return mer(getm(tl,m,l,m,pos*2),getm(m+1,tr,m+1,r,pos*2+1));
}
int main()
{
	///in
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		scanf("%d",&a[i]);
	}
	build(0,n-1,1);
	buildm(0,n-1,1);
	/////
	int m;
	scanf("%d",&m);
	for(int i=0;i<m;++i)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		--l;
		--r;
		int g=get(0,n-1,l,r,1);
		ban minu=getm(0,n-1,l,r,1);
		if(minu.x==g)
			printf("%d\n",(r-l+1)-minu.q);
		else
			printf("%d\n",(r-l+1));
	}
//	system("pause");
	return 0;
}