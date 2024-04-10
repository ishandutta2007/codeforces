#include<bits/stdc++.h>
#define ll long long

using namespace std;

map<ll,ll> mp[100002];

ll query(ll x, ll w){
	ll mx = 0;
	for(;w > 0;w -= w&-w){
		auto it = mp[x].find(w);
		if(it != mp[x].end())
			mx = max(mx,it->second);
	}
	return mx+1;
}

void update(ll x, ll j, ll w){
	for(;w<=100001; w += w&-w)
		mp[x][w] = max(mp[x][w],j);
}

int main(){
	ll n,m,i,j,x,y,w,ans;
	cin>>n>>m;
	ans = 0;
	for(i=0;i<m;i++){
		cin>>x>>y>>w;
		j = query(x,w);
		update(y,j,w+1);
	}
	for(i=1;i<=n;i++)
			ans = max(ans,query(i,100001)-1);
	cout<<ans;
}