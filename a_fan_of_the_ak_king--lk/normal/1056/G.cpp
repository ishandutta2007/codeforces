#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,m,s,vis[100005],cy;
long long t;
int nex(int x,int y)
{
	if(x<m)
		return (x+y)%n;
	else
		return (x-y+n)%n;
}
int main()
{
	scanf("%d %d",&n,&m);
	scanf("%d %lld",&s,&t);
	--s;
	while(t%n!=0)
	{
		s=nex(s,t%n);
		--t;
	}
	t/=n;
	while(t&&(!vis[s]))
	{
		vis[s]=++cy;
		for(int y=n-1;y>0;--y)
			s=nex(s,y);
		--t;
	}
	if(!t)
	{
		cout<<s+1;
		return 0;
	}
	t%=(cy+1-vis[s]);
	while(t)
	{
		for(int y=n-1;y>0;--y)
			s=nex(s,y);
		--t;
	}
	cout<<s+1;
}