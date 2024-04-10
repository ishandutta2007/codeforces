#include<bits/stdc++.h>
using namespace std; 
const int N=1000005,M=1000000007;
const long double PI=3.1415926535897932384626;
int n,m,i,t,x,y;
char c[5005];
map<pair<int,int>,int> mp;
bool check(int a,int b)
{
	int x=0,y=0,i;
	for(i=1;i<=n;++i)
	{
		if(c[i]=='L')
			if(x-1!=a||y!=b)
				--x;
		if(c[i]=='R')
			if(x+1!=a||y!=b)
				++x;
		if(c[i]=='D')
			if(x!=a||y-1!=b)
				--y;
		if(c[i]=='U')
			if(x!=a||y+1!=b)
				++y;
	}
	return (x==0&&y==0);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",c+1);
		n=strlen(c+1);
		x=0,y=0;
		for(i=1;i<=n;++i)
		{
			if(c[i]=='L')
				--x;
			if(c[i]=='R')
				++x;
			if(c[i]=='D')
				--y;
			if(c[i]=='U')
				++y;
			mp[make_pair(x,y)]=1;
		}
		int ansx=0,ansy=0;
		for(auto it:mp)
			if(it.first.first!=0||it.first.second!=0)
				if(check(it.first.first,it.first.second))
				{
					ansx=it.first.first;
					ansy=it.first.second;
				}
		cout<<ansx<<' '<<ansy<<endl;
	}
}