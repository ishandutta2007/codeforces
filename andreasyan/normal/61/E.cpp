#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N=1000*1002;

int a[N];
int n;
pair<int,int> b[N];
int t[N*4];
void ubd(int tl,int tr,int l,int r,int pos)
{
	if(tl==l && tr==r)
	{
		++t[pos];
		return;
	}
	int m=(tl+tr)/2;
	if(r<=m)
		ubd(tl,m,l,r,pos*2);
	else if(l>m)
		ubd(m+1,tr,l,r,pos*2+1);
	else
	{
		ubd(tl,m,l,m,pos*2);
		ubd(m+1,tr,m+1,r,pos*2+1);
	}
}
int query(int tl,int tr,int x,int pos)
{
	if(tl==tr)
	{
		return t[pos];
	}
	int m=(tl+tr)/2;
	if(x<=m)
		return t[pos]+query(tl,m,x,pos*2);
	else
		return  t[pos]+query(m+1,tr,x,pos*2+1);
}
int main()
{
	///in itp
	cin>>n;
	for(int i=0;i<n;++i)
	{
		cin>>a[i];
		b[i].first=a[i];
		b[i].second=i;
	}
	sort(b,b+n);
	for(int i=0;i<n;++i)
	{
		a[b[i].second]=i;
	}
	///lux
	long long p[N], m[N];
	for(int i=0;i<n;++i)
	{
		m[i]=query(0,n-1,a[i],1);
		ubd(0,n-1,0,a[i],1);
	}
	/////
	for(int i=0;i<N*4;++i)
		t[i]=0;
	/////
	for(int i=n-1;i>=0;--i)
	{
		p[i]=query(0,n-1,a[i],1);
		ubd(0,n-1,a[i],n-1,1);
	}
	//out
	long long ans=0;
	for(int i=0;i<n;++i)
		ans+=(p[i]*m[i]);
	cout<<ans<<endl;
//	system("pause");
	return 0;
}