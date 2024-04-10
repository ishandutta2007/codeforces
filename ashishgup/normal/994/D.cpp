#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=20;

int n, m;
pair<int, int> a[N], b[N];
set<int> fincommon;
bool neg=0;

void work(pair<int, int> p)
{
	int shared=0;
	set<int> common;
	for(int i=1;i<=m;i++)
	{
		int curcommon=0;
		if(p.first==b[i].first)
			curcommon++;
		if(p.first==b[i].second)
			curcommon++;
		if(p.second==b[i].first)
			curcommon++;
		if(p.second==b[i].second)
			curcommon++;
		if(curcommon==1)
		{
			if(p.first==b[i].first)
				common.insert(p.first);
			if(p.second==b[i].first)
				common.insert(p.second);
			if(p.first==b[i].second)
				common.insert(p.first);
			if(p.second==b[i].second)
				common.insert(p.second);
		}
	}   
	if(common.size()>1)
		neg=1;
	for(auto it:common)
		fincommon.insert(it);
}

void work2(pair<int, int> p)
{
	int shared=0;
	set<int> common;
	for(int i=1;i<=n;i++)
	{
		int curcommon=0;
		if(p.first==a[i].first)
			curcommon++;
		if(p.first==a[i].second)
			curcommon++;
		if(p.second==a[i].first)
			curcommon++;
		if(p.second==a[i].second)
			curcommon++;
		if(curcommon==1)
		{
			if(p.first==a[i].first)
				common.insert(p.first);
			if(p.second==a[i].first)
				common.insert(p.second);
			if(p.first==a[i].second)
				common.insert(p.first);
			if(p.second==a[i].second)
				common.insert(p.second);
		}
	}   
	if(common.size()>1)
		neg=1;
	for(auto it:common)
		fincommon.insert(it);
}

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i].first>>a[i].second;
	for(int i=1;i<=m;i++)
		cin>>b[i].first>>b[i].second;
	for(int i=1;i<=n;i++)
		work(a[i]);
	for(int i=1;i<=m;i++)
		work2(b[i]);
	if(neg)
		cout<<"-1";
	else
	{
		if(fincommon.size()==1)
			cout<<*(fincommon.begin());
		else
			cout<<"0";
	}
	return 0;
}