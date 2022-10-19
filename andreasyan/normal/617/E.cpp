#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct ban
{
	int x,y,number;
};
long long prefix[2000002],a[2000002],c[2000002],n,m,k,u,t,ans,res[2000002];
ban b[2000002];
bool operator<(const ban& a,const ban& b)
{
	if(a.x/t<b.x/t)
		return true;
	if(a.x/t>b.x/t)
		return false;
	return a.y<b.y;
}
void ad(int j)
{
	ans+=c[prefix[j]^k];
	c[prefix[j]]++;
}
void remuv(int j)
{
	c[prefix[j]]--;
	ans-=c[prefix[j]^k];
}
int main()
{
	int i,l,r,yl=1,yr=0;
	cin>>n>>m>>k;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		u^=a[i];
		prefix[i]=u;
	}
	for(i=0;i<m;i++)
	{
		cin>>b[i].x>>b[i].y;
		b[i].number=i;
	}
	t=sqrt(m+0.0);
	sort(b,b+m);
	for(i=0;i<m;i++)
	{
		l=b[i].x-1;
		r=b[i].y;
		while(yr<r)
		{
			yr++;
			ad(yr);
		}
		while(yr>r)
		{
			remuv(yr);
			yr--;
		}
		while(yl<l)
		{
			remuv(yl);
			yl++;
		}
		while(yl>l)
		{
			yl--;
			ad(yl);
		}
		res[b[i].number]=ans;
	}
	for(i=0;i<m;i++)
		cout<<res[i]<<endl;
	return 0;
}