#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)1010)

vector <pair<ll,ll> > ans;
ll num[N];

void solve(vector <pair<ll,ll> > now,vector <pair<ll,ll> > fin,vector <ll> index)
{
//	cout<<"|||||| \n";
//	for(auto u:now)cout<<u.first<<" "<<u.second<<"\n";
//	for(auto u:fin)cout<<u.first<<" "<<u.second<<"\n";
//	for(auto u:index)cout<<u<<" ";cout<<"\n";
	if(!now.size())return ;
	ll n=index.size();
	ll x,y,val=N;
	for(int i=0;i<n;i++)num[index[i]]=i;
	for(auto u:fin)
	{
		ll ex=abs(num[u.second]-num[u.first]-n/2);
		if(ex<val)val=ex,x=u.first,y=u.second;
	}
	bool flg=0;
	for(auto u:now)
		if(u.first==x && u.second==y)
		{
			flg=1;
			break;	
		}
	if(!flg)
	{
		vector <pair<ll,ll> > now_ex;
		vector <pair<ll,pair<ll,ll> > > ex;
		for(auto u:now)
		{
			if(((u.first>=x && u.first<=y) && (u.second>=x && u.second<=y)) || ((u.first>=y || u.first<=x) && (u.second>=y || u.second<=x)))
				now_ex.push_back(u);
			else
			{
				ll p=u.first,q=u.second;
				if(q>=x && q<=y)swap(p,q);
				ll val=p-x;
				if(q>=y)q-=N;
				val+=x-q;
				ex.push_back({val,u});
			}
		}
		sort(ex.begin(),ex.end());
		for(int i=0;i<(ll)ex.size()-1;i++)
		{
			pair <ll,ll> u=ex[i].second;
			ans.push_back(u);
			ll v=ex[i+1].second.first;
			if(v==u.first || v==u.second)
				v=ex[i+1].second.second;
			now_ex.push_back({min(x,v),max(x,v)});
		}
		ans.push_back(ex.back().second);
		now_ex.push_back({x,y});
		now=now_ex;
	}
	//for(auto u:now)cout<<u.first<<" "<<u.second<<"\n";
	vector <pair<ll,ll> > now1,now2,fin1,fin2;
	vector <ll> index1,index2;
	for(auto u:now)
	{
		if(u.first>=x && u.second<=y)
		{
			if(u.first!=x || u.second!=y)
				now1.push_back(u);
		}
		else
			now2.push_back(u);
	}
	for(auto u:fin)
	{
		if(u.first>=x && u.second<=y)
		{
			if(u.first!=x || u.second!=y)
				fin1.push_back(u);
		}
		else
			fin2.push_back(u);
	}
	for(auto u:index)
	{
		if(u>=x && u<=y)index1.push_back(u);
		if(u<=x || u>=y)index2.push_back(u);
	}
	solve(now1,fin1,index1);
	solve(now2,fin2,index2);
}

int main()
{
	//ios_base::sync_with_stdio(0);cin.tie(0);
	ll n;
	cin>>n;
	vector <pair<ll,ll> > now,fin;
	vector <ll> index;
	for(int i=0;i<n;i++)index.push_back(i);
	for(int i=0;i<n-3;i++)
	{
		ll x,y;
		cin>>x>>y;
		now.push_back({min(x-1,y-1),max(x-1,y-1)});
	}
	for(int i=0;i<n-3;i++)
	{
		ll x,y;
		cin>>x>>y;
		fin.push_back({min(x-1,y-1),max(x-1,y-1)});
	}
	solve(now,fin,index);
	cout<<ans.size()<<"\n";
	for(auto u:ans)cout<<u.first+1<<" "<<u.second+1<<"\n";
	return 0;
}