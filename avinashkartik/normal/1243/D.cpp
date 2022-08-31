#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
ll INF = 1e18;
const int N = 1e+5 + 5;

ll p[N],sz[N],p1[N],sz1[N];
ll n,m,k,x,u,v,ct,ct1;
string s;
vector <ll> a[N],ans;
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
    cin>>n>>m;
    make();

    for(int i = 1; i <= m; i++){
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    for(int i = 1; i <= n; i++){
    	sort(a[i].begin(), a[i].end());
    }

    ll h = (n+1)/2 - 1;
	ll ver = -1;
	for(int i = 1; i <= n; i++){
		if(a[i].size() == n-1) continue;
		if(a[i].size() < h){
			if(ver == -1) ver = i;
			if(find(ver) != find(i)) merge(ver,i);
		}
    	else{
    		ll j = 1;
    		for(auto it : a[i]){
    			if(it > j){
    				for(; j < it; j++){
    					if(find(j) != find(i)) merge(j,i);
    				}
    			}
    			j = it+1;
    		}
    		for(; j <= n; j++){
   				if(find(j) != find(i)) merge(j,i);
   			}
    	}
    }
	for(int i = 1; i <= n; i++)
		if(p[i] == i) ct++;

	cout<<ct-1<<endl;
}