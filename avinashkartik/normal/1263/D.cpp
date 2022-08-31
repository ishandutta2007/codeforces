#pragma optimization_level 3
#pragma GCC optimize("Ofast")   //Comment optimisations for an interatcive problem - use endl
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
 
using namespace std;
 
#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;
#define  x                     first                 
#define  y                     second

const ll   N     =  2e+5+5;
const ll   mod   =  1e+9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll p[N],sz[N],a[N][26];
ll n,m,q,u,v,ct;
string s[N];

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
    cin>>n;
    make();

    for(int i = 0; i < n; i++){
        cin>>s[i];
        ll len = s[i].size();
        for(int j = 0; j < len; j++){
        	ll ind = int(s[i][j]) - int('a');
        	//cout<<ind<<" ";
        	a[i][ind] = 1;
        }
        //cout<<endl;
    }
    for(int j = 0; j < 26; j++){
    	ll key = -1;
    	for(int i = 0; i < n; i++){
			if(a[i][j] == 1){
				if(key == -1) key = i;
				else merge(key,i); 
			}
		}
	}

	ll ct = 0;
	for(int i = 0; i < n; i++){
		if(find(i) == i) ct++;
	}
	cout<<ct<<endl;
}