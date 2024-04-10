#include <iostream>
#include <algorithm>
#include <map>
#include <cstdio>
#include <vector>
using namespace std;
const int N=1000006;

long long ans;
int n, x, m;
int a[N], p[N];
int t[N*31][2], g[N*31];
vector<int> xx, pp;	
void er(int y, char ch)
{
	if(ch=='x')
	{
		while(y)
		{
			xx.push_back(y%2);
			y/=2;
		}
		while(xx.size()<30)
			xx.push_back(0);
		reverse(xx.begin(),xx.end());
	}
	else
	{
		pp.clear();
		while(y)
		{
			pp.push_back(y%2);
			y/=2;
		}
		while(pp.size()<30)
			pp.push_back(0);
		reverse(pp.begin(),pp.end());
	}
}
void av(int i,int y)
{
	++g[y];
	if(i==30)
	{
		return;
	}
	if(t[y][pp[i]]==0)
		t[y][pp[i]]=++m;
	av(i+1,t[y][pp[i]]);
}
void ub(int i,int y)
{
	if(i==30)
	{
		return;
	}
	if(xx[i]==0)
	{
		if(pp[i]==1 && t[y][0])
			ans+=g[t[y][0]];
		if(pp[i]==0 && t[y][1])
			ans+=g[t[y][1]];
	}
	if(t[y][pp[i]^xx[i]]==0)
		return;
//		t[y][pp[i]^xx[i]]=++m;
	ub(i+1,t[y][pp[i]^xx[i]]);
}
void funkc()
{
	map<int,int> mp;
	for(int i=0;i<=n;++i)
	{
		ans+=mp[x^p[i]];
		++mp[p[i]];
	}
}
int main()
{
	///in;
	scanf("%d%d",&n,&x);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	/////
	for(int i=1;i<=n;++i)
		p[i]=p[i-1]^a[i];
	/////
	er(x,'x');
	for(int i=0;i<=n;++i)
	{
		er(p[i],'p');
		av(0,0);
		ub(0,0);
	}
	funkc();
	//out
	cout<<ans<<endl;
	return 0;
}