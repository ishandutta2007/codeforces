#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
ll INF = 1e18;
const int N = 5e+5 + 5;

ll p[N],sz[N],visit[N];
ll n,m,k,x,u,v,ct,ct1;
string s;
vector <ll> a[N],ans,vec[N];
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
	if(a != b){
		if(sz[a] > sz[b]) swap(a,b);
		p[a] = b;
		sz[b] += sz[a];
	}
}

int main(){
	fastio;
    cin>>n>>m;
    make();

    for(int i = 1; i <= m; i++){
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    ll h = (n+1)/2 - 1;
	ll ver = -1;
	for(int i = 1; i <= n; i++){
		if(a[i].size() == n-1) continue;
		if(a[i].size() < h){
			if(ver == -1) ver = i;
			merge(ver,i);
		}
    	else{
    		ll j = 1;
			for(auto it: a[i])visit[it]=1;
			for(int j = 1; j <= n; j++)if(!visit[j])merge(i,j);
			for(auto it: a[i])visit[it]=0;
    	}
    }
	for(int i = 1; i <= n; i++){
		ll part = find(i); 
		if(part == i){
			ct++;
			ans.push_back(i);
		}
		vec[part].push_back(i);
	}
	
	cout<<ct<<endl;
	for(auto it : ans){
		cout<<vec[it].size()<<" ";
		for(auto it1 : vec[it]){
			cout<<it1<<" ";	
		}
		cout<<endl;
	}
}