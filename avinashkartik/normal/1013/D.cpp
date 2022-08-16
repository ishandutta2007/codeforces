#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
ll INF = 1e18;
const int N = 5e+5 + 5;

ll p[N],sz[N];
ll n,m,q,u,v,ct;

void make(){
	for(int i = 1; i <= n+m; i++){
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
		if(sz[a] >= sz[b]) swap(a,b);
		p[a] = b;
		sz[b] += sz[a];
	}
}

int main(){
	fastio;
    cin>>n>>m>>q;
    make();

    for(int i = 1; i <= q; i++){
        cin>>u>>v;
    	merge(u,v+n);
    }

    for(int i = 1; i <= n+m; i++){
		if(find(i) == i) ct += 1;
	}

	cout<<ct-1<<endl;
}