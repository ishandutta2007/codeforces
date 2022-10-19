#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const int N=1000006;

int n;
int a[N];
int al[N];
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
int get(int tl,int tr,int x,int pos)
{
	if(tl==tr)
		return t[pos];
	int m=(tl+tr)/2;
	if(x<=m)
		return t[pos]+get(tl,m,x,pos*2);
	else
		return t[pos]+get(m+1,tr,x,pos*2+1);
}
int main()
{
	/////
	map<int,int> mp;
	int k=0;
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		scanf("%d",&a[i]);
		if(mp[a[i]]==0)
			mp[a[i]]=++k;
		a[i]=mp[a[i]];
	}
	mp.clear();
	/////
	for(int i=n-1;i>=0;--i)
	{
		mp[a[i]]++;
		al[i]=mp[a[i]];
	}
	mp.clear();
	/////
	long long ans=0;
	for(int i=0;i<n;++i)
	{
		ans+=(get(0,n,al[i],1));
		mp[a[i]]++;
		ubd(0,n,0,mp[a[i]]-1,1);
	}
	cout<<ans<<endl;
//	system("pause");
	return 0;
}