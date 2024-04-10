#pragma comment(linker, "/STACK:66777216")
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <unordered_map>
using namespace std;
const int N=100002;
const int M=350;

int n,m;
pair<int,pair<int,int> > q[N];
vector<pair<int,int> > v;
unordered_map<int,int> a[N];
unordered_map<int,int> s[M];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		scanf("%d%d%d",&q[i].first,&q[i].second.first,&q[i].second.second);
		v.push_back(make_pair(q[i].second.first,i));
	}
	sort(v.begin(),v.end());
	m=1;
	for(int i=0;i<n;++i)
	{
		if(i==0)
		{
			q[v[i].second].second.first=m;
			continue;
		}
		if(v[i-1].first==v[i].first)
		{
			q[v[i].second].second.first=m;
		}
		else
		{
			++m;
			q[v[i].second].second.first=m;
		}
	}
	m=sqrt(m+0.0);
	for(int j=0;j<n;++j)
	{
		int k=q[j].first,t=q[j].second.first,x=q[j].second.second;
		if(k==1)
		{
//			t=mp[t];
			++a[t][x];
			++s[t/m][x];
		}
		if(k==2)
		{
//			t=mp[t];
			--a[t][x];
			--s[t/m][x];
		}
		if(k==3)
		{
//			t=mp[t];
			int ans=0;
			for(int j=0;j<(t/m);++j)
			{
				if(s[j].find(x)!=s[j].end())
					ans+=s[j][x];
			}
			int j=t;
			while(j>=0 && (j/m)==(t/m))
			{
				if(a[j].find(x)!=a[j].end())
					ans+=a[j][x];
				--j;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}