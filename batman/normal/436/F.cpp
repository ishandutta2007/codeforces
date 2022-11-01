#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)101*1000)
#define SQ ((ll)350)
#define QS ((ll)N/SQ+100)
#define INF ((ll)2e9)

ll n,w,num[N],lazy[QS],maxi[QS],prv[N];
pair <ll,ll> a[N];
set <pair<ll,pair<ll,ll> > > need[QS];
bool mark[N];

ll num2[N];

void reset(ll x)
{
	stack <ll> st;
	for(int i=x*SQ;i<min((x+1)*SQ,N);i++)
	{
		mark[i]=0;
		num[i]+=i*lazy[x];
		while(st.size() && num[st.top()]<=num[i])st.pop();
		st.push(i);
	}
	need[x].clear();
	ll lst=-1;
	while(st.size())
	{
		mark[st.top()]=1;
		if(lst!=-1)need[x].insert({(num[st.top()]-num[lst]+lst-st.top()-1)/(lst-st.top()),{st.top(),lst}});
		if(lst!=-1)prv[lst]=st.top();
		lst=st.top();st.pop();
	}
	prv[lst]=-1;maxi[x]=lst;
	lazy[x]=0;
}

void add(ll x)
{
	for(int i=0;i<x/SQ;i++)
	{
		lazy[i]++;
		while(need[i].size() && need[i].begin()->first<=lazy[i])
		{
			ll x=need[i].begin()->second.first,y=need[i].begin()->second.second;
			need[i].erase(need[i].begin());
			if(!mark[x] || !mark[y])continue;
			prv[y]=prv[x];
			mark[x]=0;
			if(prv[y]==-1)maxi[i]=y;
			else
			{
				ll id=prv[y];
				need[i].insert({(num[id]-num[y]+y-id-1)/(y-id),{id,y}});
			}
		}
	}
	for(int i=x/SQ*SQ;i<=x;i++)num[i]+=i;
	reset(x/SQ);
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>w;
    for(int i=0;i<n;i++)cin>>a[i].second>>a[i].first;
    sort(a,a+n);
    for(int i=0;i<N/SQ;i++)reset(i);
	for(int i=0,j=0;j<n;i++)
	{
		while(j<n && a[j].first<i)add(a[j].second),j++;
		pair <ll,ll> ans;ans.first=-1;
		for(int p=0;p<N/SQ;p++)
		{
			if(!maxi[p])continue;
			ll res=maxi[p]*lazy[p]+num[maxi[p]];
			if(res>ans.first)ans={res,maxi[p]};
		}
		cout<<ans.first+(n-j)*i*w<<" "<<ans.second<<"\n";
	}	
	return 0;
}