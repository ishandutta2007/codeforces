#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)101*1000)
#define K ((ll)20)

ll q,ch[2][N*K*K],cnt=N;
ll mini[N*K*K];
vector <ll> divs[N];
bool mark[N];

void add(ll id,ll x)
{
	mini[id]=min(mini[id],x);
	for(int i=K-1;i>=0;i--)
	{
		bool p=(x&(1<<i));
		if(!ch[p][id])ch[p][id]=cnt++;
		id=ch[p][id];
		mini[id]=min(mini[id],x);
	}
	
}

ll query(ll id,ll x,ll y)
{
	if(mini[id]>y)return -1;
	ll ans=0;
	for(int i=K-1;i>=0;i--)
	{
		bool p=(x&(1<<i));p=!p;
		if(mini[ch[p][id]]<=y)
			id=ch[p][id],
			ans+=p*(1<<i);
		else
			id=ch[!p][id],
			ans+=(!p)*(1<<i);
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>q;
	for(int i=0;i<N*K*K;i++)mini[i]=N;
	for(int i=1;i<N;i++)
		for(int j=i;j<N;j+=i)
			divs[j].push_back(i);
	while(q--)
	{
		ll t,x,k,s;
		cin>>t>>x;
		if(t==1)
		{
			if(mark[x])continue;
			mark[x]=1;
			for(auto u:divs[x])add(u,x);
		}
		if(t==2)
		{
			cin>>k>>s;
			if(x%k){cout<<"-1\n";continue;}
			cout<<query(k,x,s-x)<<"\n";
		}
	}
	return 0;
}