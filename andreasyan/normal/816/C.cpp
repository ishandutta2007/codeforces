#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cstdio>
#include <queue>
#include <string>
#include <cstring>
using namespace std;
const int N=102,INF=999999999;

int n,m,k;
int a[N][N];
int tg[N],sg[N];
vector<pair<string,int> > ans;
vector<pair<int,bool> > s,t;
bool stg()
{
	int i,j;
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=m;++j)
		{
			if(a[i][j]>0)
				return false;
		}
	}
	return true;
}
int main()
{
	int i,j,l,r;
	std::ios::sync_with_stdio(false);
	cin>>n>>m;
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=m;++j)
		{
			cin>>a[i][j];
		}
	}
	for(i=0;i<=max(n,m);++i)
	{
		sg[i]=INF;
		tg[i]=INF;
	}
	for(i=1;i<=n;++i)
	{
		bool z=true;
		for(j=1;j<=m;++j)
		{
			if(a[i][j]==0)
			{
				z=false;
			}
			tg[i]=min(tg[i],a[i][j]);
		}
		if(z)
		t.push_back(make_pair(i,false));
	}
	for(j=1;j<=m;++j)
	{
		bool z=true;
		for(i=1;i<=n;++i)
		{
			if(a[i][j]==0)
			{
				z=false;
			}
			sg[j]=min(sg[j],a[i][j]);
		}
		if(z)
		s.push_back(make_pair(j,false));
	}
	//
		if(m>n)
		{
		while(1)
		{
			bool f=true;
			for(i=0;i<t.size();++i)
			{
				if(t[i].second)
					continue;
				f=false;
				bool z=true;
				for(j=1;j<=m;++j)
				{
					if(a[t[i].first][j]==0)
					{
						z=false;
						break;
					}
				}
				if(z==false)
					t[i].second=true;
				else
				{
					for(j=1;j<=m;++j)
						a[t[i].first][j]--;
					ans.push_back(make_pair("row",t[i].first));
				}
			}
			if(f)
				break;
		}
		while(1)
		{
			bool f=true;
			for(i=0;i<s.size();++i)
			{
				if(s[i].second)
					continue;
				f=false;
				bool z=true;
				for(j=1;j<=n;++j)
				{
					if(a[j][s[i].first]==0)
					{
						z=false;
						break;
					}
				}
				if(z==false)
					s[i].second=true;
				else
				{
					for(j=1;j<=n;++j)
						a[j][s[i].first]--;
					ans.push_back(make_pair("col",s[i].first));
				}
			}
			if(f)
				break;
		}
		}
		else
		{
			while(1)
		{
			bool f=true;
			for(i=0;i<s.size();++i)
			{
				if(s[i].second)
					continue;
				f=false;
				bool z=true;
				for(j=1;j<=n;++j)
				{
					if(a[j][s[i].first]==0)
					{
						z=false;
						break;
					}
				}
				if(z==false)
					s[i].second=true;
				else
				{
					for(j=1;j<=n;++j)
						a[j][s[i].first]--;
					ans.push_back(make_pair("col",s[i].first));
				}
			}
			if(f)
				break;
		}
			while(1)
		{
			bool f=true;
			for(i=0;i<t.size();++i)
			{
				if(t[i].second)
					continue;
				f=false;
				bool z=true;
				for(j=1;j<=m;++j)
				{
					if(a[t[i].first][j]==0)
					{
						z=false;
						break;
					}
				}
				if(z==false)
					t[i].second=true;
				else
				{
					for(j=1;j<=m;++j)
						a[t[i].first][j]--;
					ans.push_back(make_pair("row",t[i].first));
				}
			}
			if(f)
				break;
		}
		}
	if(!stg())
	{
		cout<<"-1"<<endl;
		return 0;
	}
	//output
	cout<<ans.size()<<endl;
	for(i=0;i<ans.size();++i)
	{
		cout<<ans[i].first<<' '<<ans[i].second<<endl;
	}
//	system("pause");
	return 0;
}