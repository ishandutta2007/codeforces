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

ll p[N],sz[N];
ll n,m,q,u,v,w;
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

    for(int i = 0; i < n-1; i++){
    	cin>>u>>v>>w;
    	int flag = 1;
    	while(w > 0){
    		if(w % 10 == 4 || w % 10 == 7){
    			w = w/10;
    		}
    		else{
    			flag = 0;
    			break;
    		}
    	}
    	if(flag == 0) merge(u,v); 
    }


	ll ans = 0;
	for(int i = 1; i <= n; i++){
		if(find(i) == i){
			//cout<<i<<sz[i]<<" ";
			ll ct = n - sz[i];
			ans += ct*(ct-1)*sz[i]; 
		}
	}
	cout<<ans<<endl;
}