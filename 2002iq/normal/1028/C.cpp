#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;
#define f first
#define s second
pair<pair<int,int>,pair<int,int> > arr[150005];
bool cmp1(pair<pair<int,int>,pair<int,int> > a,pair<pair<int,int>,pair<int,int> > b)
{
	return (a.f.f>b.f.f);
}
bool cmp2(pair<pair<int,int>,pair<int,int> > a,pair<pair<int,int>,pair<int,int> > b)
{
	return (a.f.s>b.f.s);
}
bool cmp3(pair<pair<int,int>,pair<int,int> > a,pair<pair<int,int>,pair<int,int> > b)
{
	return (a.s.f<b.s.f);
}
bool cmp4(pair<pair<int,int>,pair<int,int> > a,pair<pair<int,int>,pair<int,int> > b)
{
	return (a.s.s<b.s.s);
}
int n;
void isect()
{
	int lx=-(1<<30),rx=(1<<30),ly=-(1<<30),ry=(1<<30);
	for (int i=1;i<n;i++)
	{
		lx=max(lx,arr[i].f.f);
		ly=max(ly,arr[i].f.s);
		rx=min(rx,arr[i].s.f);
		ry=min(ry,arr[i].s.s);
	}
	if (lx<=rx && ly<=ry)
	{
		printf("%d %d",lx,ly);
		exit(0);
	}
}
int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	scanf("%d%d%d%d",&arr[i].f.f,&arr[i].f.s,&arr[i].s.f,&arr[i].s.s);
	sort(arr,arr+n,cmp1);
	isect();
	sort(arr,arr+n,cmp2);
	isect();
	sort(arr,arr+n,cmp3);
	isect();
	sort(arr,arr+n,cmp4);
	isect();
}