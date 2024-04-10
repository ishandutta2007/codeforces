#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)101*1000)

string s;
ll n,ans;
set <ll> st[2];
ll num;
vector <ll> type_id[2],type[2],vec[N];

int main()
{
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++)st[(s[i]=='R')].insert(i);
	while(1)
	{
		ll now=N;
		bool move=0;
		if(st[0].size())
			now=*st[0].begin();
		if(st[1].size() && now>*st[1].begin())
			now=*st[1].begin(),move=1;
		if(now==N)break;
		ans++;
		vec[num].push_back(now);
		st[move].erase(now);
		move=!move;
		while(1)
		{
			auto it=st[move].lower_bound(now);
			if(it==st[move].end())break;
			now=*it;
			st[move].erase(now);
			vec[num].push_back(now);
			move=!move;
		}
		ll ex=(s[vec[num][0]]=='R')+2*(s[vec[num].back()]=='R');
		if(ex==2)
			for(auto u:vec[num])
				type[0].push_back(u);
		if(ex==1)
			for(auto u:vec[num])
				type[1].push_back(u);
		if(ex==0)type_id[0].push_back(num);
		if(ex==3)type_id[1].push_back(num);
		num++;
	}
	cout<<ans-1<<"\n";
	for(int i=0;i<min(type_id[0].size(),type_id[1].size());i++)
	{
		for(auto u:vec[type_id[0][i]])
			type[0].push_back(u);
		for(auto u:vec[type_id[1][i]])
			type[0].push_back(u);
	}
	if(type_id[0].size()>type_id[1].size())
	{
		for(auto u:type[0])cout<<u+1<<" ";
		for(auto u:vec[type_id[0].back()])cout<<u+1<<" ";
		for(auto u:type[1])cout<<u+1<<" ";
		cout<<"\n";
		return 0;
	}
	if(type_id[0].size()<type_id[1].size())
	{
		for(auto u:type[1])cout<<u+1<<" ";
		for(auto u:vec[type_id[1].back()])cout<<u+1<<" ";
		for(auto u:type[0])cout<<u+1<<" ";
		cout<<"\n";
		return 0;
	}
	if(type[0].size()==0)swap(type[0],type[1]);
	if(type[1].size())
	{
		if(type[0][0]>type[1][0])swap(type[0],type[1]);
		type[0].push_back(type[0][0]);
		type[0].erase(type[0].begin());
		for(auto u:type[1])type[0].push_back(u);
	}
	for(auto u:type[0])cout<<u+1<<" ";cout<<"\n";
	return 0;
}