#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define F first
#define S second
#define N ((ll)5050)
#define MAX ((ll)101*1000)

ll n,q,a[MAX];
set <ll> s;
vector <ll> e[N];
vector <pair<ll,ld> > prob[N];
pair <pair<ll,ld>,pair<ll,ll> > qu[N];

void _merge(vector <pair<ll,ld> > &x,vector <pair<ll,ld> > &y)
{
	ld sumx=1,sumy=1;
	for(int i=0,j=0;i<x.size();i++)
	{
		while(j<y.size() && x[i].F<y[j].F)sumy-=y[j].S,j++;
		sumx-=x[i].S;
		x[i].S=(x[i].S*sumy);
		if(j<y.size() && y[j].F==x[i].F)x[i].S+=y[j].S*sumx;
	}
	while(x.size() && x[(ll)x.size()-1].S==0)x.pop_back();
	vector <pair<ll,ld> > ex;
	for(int i=0;i<y.size();i++)
	{
		if(x.size() && x[0].F>=y[i].F)break;
		ex.push_back(y[i]);
	}
	for(auto u:x)ex.push_back(u);
	x=ex;
}

void dfs(ll x)
{
	for(auto u:e[x])
	{
		dfs(u);
		if(!prob[x].size())prob[x]=prob[u];
		else _merge(prob[x],prob[u]);
	}
	while(1)
	{
		auto it=s.lower_bound(qu[x].S.F);
		if(it==s.end() || *it>qu[x].S.S)break;
		ll ex=a[*it];s.erase(it);
		ld ex2=0;
		while(prob[x].size() && prob[x][(ll)prob[x].size()-1].F<ex)ex2+=prob[x][(ll)prob[x].size()-1].S,prob[x].pop_back();
		if(prob[x].size())prob[x][(ll)prob[x].size()-1].S+=ex2;
		else prob[x].push_back({ex,1});
	}
	if(!prob[x].size())return ;
	vector <pair<ll,ld> > ex;
	ex.push_back({prob[x][0].F+1,qu[x].F.S*prob[x][0].S});
	for(int i=0;i<(ll)prob[x].size()-1;i++)
		ex.push_back({prob[x][i].F,prob[x][i+1].S*qu[x].F.S+prob[x][i].S*(1-qu[x].F.S)});
	ex.push_back({prob[x][(ll)prob[x].size()-1].F,prob[x][(ll)prob[x].size()-1].S*(1-qu[x].F.S)});
	prob[x]=ex;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
   	cin>>n>>q;
   	for(int i=1;i<=n;i++)cin>>a[i],s.insert(i);
   	for(int i=1;i<=q;i++)
   		cin>>qu[i].S.F>>qu[i].S.S>>qu[i].F.S,qu[i].F.F=qu[i].S.S-qu[i].S.F;
   	qu[q+1].S.F=1;qu[q+1].S.S=n;qu[q+1].F.S=0;qu[q+1].F.F=n-1;
   	sort(qu+1,qu+q+1);
   	for(int i=1;i<=q;i++)
   		for(int j=i+1;j<=q+1;j++)
   			if(qu[j].S.F<=qu[i].S.F && qu[i].S.S<=qu[j].S.S)
   			{
   				e[j].push_back(i);
   				break;
			}
   	dfs(q+1);
   	ld ans=0;
   	for(auto u:prob[q+1])ans+=u.first*u.second;
   	cout<<fixed<<setprecision(14)<<ans<<"\n";
	return 0;
}