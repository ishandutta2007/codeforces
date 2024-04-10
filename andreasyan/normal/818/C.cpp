#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N=100005;
struct ban
{
	int x1,y1,x2,y2,num;
};
struct ban1
{
	int l,r,u,d;
};
bool sorx1(const ban& a,const ban& b)
{
	return a.x1<b.x1;
}
bool sorx2(const ban& a,const ban& b)
{
	return a.x2<b.x2;
}
bool sory1(const ban& a,const ban& b)
{
	return a.y1<b.y1;
}
bool sory2(const ban& a,const ban& b)
{
	return a.y2<b.y2;
}

int n,m,k;
ban a[N];
int l[N],r[N],u[N],d[N];
int al[N],ar[N],au[N],ad[N];
ban1 cd,ans;
int main()
{
	int i,j;
	scanf("%d%d%d",&k,&n,&m);
	for(i=0;i<k;++i)
	{
		a[i].num=i;
		scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
		if(a[i].x1>a[i].x2)
			swap(a[i].x1,a[i].x2);
		if(a[i].y1>a[i].y2)
			swap(a[i].y1,a[i].y2);
		l[a[i].x1]++;
		r[a[i].x2]++;
		u[a[i].y1]++;
		d[a[i].y2]++;
	}
	//luc
	for(i=1;i<=n;++i)
		al[i]=al[i-1]+l[i];
	for(i=n;i>=0;--i)
		ar[i]=ar[i+1]+r[i];
	for(i=1;i<=m;++i)
		au[i]=au[i-1]+u[i];
	for(i=m;i>=1;--i)
		ad[i]=ad[i+1]+d[i];
	//output
	scanf("%d%d%d%d",&cd.l,&cd.r,&cd.u,&cd.d);
	for(i=0;i<k;++i)
	{
		ans.l=al[a[i].x2-1];
		ans.r=ar[a[i].x1+1];
		ans.u=au[a[i].y2-1];
		ans.d=ad[a[i].y1+1];
		if(a[i].x1<a[i].x2)
		{
			ans.l--;
			ans.r--;
		}
		if(a[i].y1<a[i].y2)
		{
			ans.u--;
			ans.d--;
		}
		if(cd.l==ans.l && cd.r==ans.r && cd.u==ans.u && cd.d==ans.d)
		{
			cout<<i+1<<endl;
//			system("pause");
			return 0;
		}
	}
	cout<<"-1"<<endl;
//	system("pause");
	return 0;
}