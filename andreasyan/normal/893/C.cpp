#pragma comment(linker,"/STACK:2000000")
#define _CRT_SECURE_NO_WARNINGS
#define mp make_pair
#define OLYMP
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <list>
#include <stack>
#include <string>
#include <cstring>
void fp();
void sp();
using namespace std;
const int N=100005,INF=1000*1000*1000+7;

int n,m;
vector<int> a[N];
int b[N];
int c[N];
int minu[N];
void dfs(int x,int g)
{
	c[x]=g;
	for(int i=0;i<a[x].size();++i)
	{
		int h=a[x][i];
		if(!c[h])
			dfs(h,g);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>b[i];
	}
	for(int i=0;i<m;++i)
	{
		int x,y;
		cin>>x>>y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	m=0;
	for(int i=1;i<=n;++i)
	{
		if(!c[i])
		{
			++m;
			dfs(i,m);
		}
	}
	for(int i=1;i<=m;++i)
		minu[i]=INF;
	for(int i=1;i<=n;++i)
	{
		minu[c[i]]=min(minu[c[i]],b[i]);
	}
	long long ans=0;
	for(int i=1;i<=m;++i)
		ans=ans+(minu[i]);
	cout<<ans<<endl;
	return 0;
}

void fp()
{
#ifndef OLYMP
	freopen("","r",stdin);
	freopen("","w",stdout);
#endif
}
void sp()
{
#ifdef OLYMP
	system("pause");
#endif
}