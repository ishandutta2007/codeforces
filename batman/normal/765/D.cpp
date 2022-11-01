#include <bits/stdc++.h>
using namespace std; 
#define ll long long
#define N ((ll)301*1000)

ll n,f[N],g[N],h[N];
map <ll,vector <ll> > mp;
ll mark[N];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>f[i],mp[f[i]].push_back(i);
	ll cnt=1;
	for(auto u:mp)
	{
		for(auto q:u.second)g[q]=cnt;
		if(f[u.first]!=u.first)return cout<<-1,0;
		h[cnt]=u.first;
		cnt++;
	}
	cout<<cnt-1<<"\n";
	for(int i=1;i<=n;i++)cout<<g[i]<<" ";cout<<"\n";
	for(int i=1;i<=cnt-1;i++)cout<<h[i]<<" ";
	return 0;
}