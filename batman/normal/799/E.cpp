#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)401*1000)
#define INF ((ll)2e18)

int n,m,k,c[N],mark[N];
vector <int> v[4];
multiset <ll> s,del;
ll sum_s,sz;

void add(int x)
{
	s.insert(x);
	sum_s+=x;
	if(s.size()<=sz)return ;
	auto it=s.end();it--;
	sum_s-=*it;
	del.insert(*it);
	s.erase(it);
}

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)scanf("%d",&c[i]);
	int ex;
	scanf("%d",&ex);
	for(int i=0;i<ex;i++)
	{
		int x;scanf("%d",&x);
		mark[x]|=1;
	}
	if(ex<k)return cout<<-1,0;
	scanf("%d",&ex);
	for(int i=0;i<ex;i++)
	{
		int x;scanf("%d",&x);
		mark[x]|=2;
	}
	if(ex<k)return cout<<-1,0;
	for(int i=1;i<=n;i++)v[mark[i]].push_back(c[i]);
	for(int i=0;i<4;i++)sort(v[i].begin(),v[i].end());
	ll ans=INF,res=0;
	int i=max({0,k-min((int)v[1].size(),(int)v[2].size()),m-(int)v[0].size()-(int)v[1].size()-(int)v[2].size()}),maxi=min((int)v[3].size(),m);
	if(i<=k)sz=m-2*k+i;
	else sz=m-i;
	if(sz<0)i-=sz,sz=0;
	if(i>maxi)return cout<<-1,0;
	for(int j=0;j<k-i;j++)res+=v[1][j],res+=v[2][j];
	for(int j=0;j<i;j++)res+=v[3][j];
	for(auto u:v[0])add(u);
	for(int j=(int)v[1].size()-1;j>=max(0,k-i);j--)add(v[1][j]);
	for(int j=(int)v[2].size()-1;j>=max(0,k-i);j--)add(v[2][j]);
	if(s.size()==sz)ans=res+sum_s;
	i++;
	for(;i<=maxi;i++)
	{
		res+=v[3][i-1];
		if(i<=k)res-=v[1][k-i],res-=v[2][k-i],add(v[2][k-i]),add(v[1][k-i]);;
		if(i<=k)sz++;
		else
		{
			sz--;
			if(sz<0)break;
			if(sz<s.size())
			{
				auto it=s.end();it--;
				sum_s-=*it;
				del.insert(*it);
				s.erase(it);
			}
		}
		if(del.size())
		{
			ll ex=*del.begin();del.erase(del.begin());
			add(ex);
		}
		if(s.size()==sz)ans=min(ans,res+sum_s);
	}
	if(ans>(ll)1e18)return cout<<-1,0;
	cout<<ans;
	return 0;
}