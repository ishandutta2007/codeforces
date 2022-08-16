#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
ll INF = 1e18;
const int N = 5e+5 + 5;

ll p[N],sz[N],c[N],l[N];
ll n,m,k,x,u,v,ct;
string s;
vector <pair<ll,ll>> a,ans;
vector <pair<ll,pair<ll,ll>>> adj;

void make(){
	for(int i = 1; i <= n; i++){
		p[i] = i;
		sz[i] = 1;
	}
}

int find(ll x){
	return (p[x] == x)? x: p[x] = find(p[x]);
}

void merge(ll x, ll y){
	ll a = find(x);
	ll b = find(y);
	if(sz[a] > sz[b]) swap(a,b);
	p[a] = b;
	sz[b] += sz[a];
}

int main(){
    cin>>n;
    make();
    a.push_back({0,0});
    for(int i = 1; i <= n; i++){
        cin>>u>>v;
        a.push_back({u,v});
    }

    for(int i = 1; i <= n; i++){
    	cin>>c[i];
    	adj.push_back({c[i],{0,i}});
    }

	for(int i = 1; i <= n; i++){
    	cin>>l[i];
    }

    for(int i = 1; i <= n; i++){
    	for(int j = 1; j < i; j++){
    		x = abs(a[i].first-a[j].first) + abs(a[i].second-a[j].second);
    		x *= (l[i]+l[j]);
    		adj.push_back({x,{i,j}});
        }
    }

    sort(adj.begin(),adj.end());

    ct = 0;
    for(auto it : adj){
    	u = it.second.first;
    	v = it.second.second;
    	if(find(u) != find(v)){
    		ct += it.first;
    		merge(u,v);
    		ans.push_back({u,v});
    	}
    }

    cout<<ct<<endl;
    x = 0;
    for(auto it : ans){
    	if(it.first == 0 || it.second == 0) x++;
    }
    cout<<x<<endl;
    for(auto it : ans){
    	if(it.first == 0) cout<<it.second<<" ";
    	else if(it.second == 0) cout<<it.first<<" ";
    }

    cout<<endl<<ans.size()-x<<endl;

    for(auto it : ans){
    	if(it.first != 0 && it.second != 0) cout<<it.first<<" "<<it.second<<endl;
    }

}