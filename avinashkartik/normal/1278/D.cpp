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

const ll   N     =  1e+6+5;
const ll   mod   =  1e+9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll p[N],sz[N];
ll n,l,r,a[N],b[N];
vpll v;
set <pll> s;

void make(){
	for(int i = 1; i < N; i++){
		p[i] = i;
		sz[i] = 1;
	}
}

int find(ll x){
	return (p[x] == x)? x: p[x] = find(p[x]);
}

int merge(ll x, ll y){
	ll a = find(x);
	ll b = find(y);
	if(a != b){
		if(sz[a] >= sz[b]) swap(a,b);
		p[a] = b;
		sz[b] += sz[a];
		return 0;
	}
	return -1;
}

int main(){
	fastio;
    cin>>n;
    make();

    for(int i = 1; i <= n; i++){
    	cin>>l>>r;
    	a[r+1] = l;
    	b[l] = r;
    	v.push_back({l,i});
    	v.push_back({r+1,-i});
    }

    sort(v.begin(), v.end());
	ll ans = 0;
	int ch = 0;
	for(int i = 0; i < 2*n; i++){
		if(v[i].y > 0) s.insert({b[v[i].x],v[i].y});
		else{ s.erase({v[i].x-1,-v[i].y}); continue;}
		if(s.size() == 0) continue;
		auto it = s.begin();
		while(it != s.end() && (*it).x < b[v[i].x]){
			//cout<<(*it).y<<" "<<v[i].y<<endl;
			ch = merge((*it).y,v[i].y);
			if(ch == -1) break;
			ans++;
			it++;
		}
		if(ch == -1 || ans == n) break;
	}

	if(ch == -1 || ans == n) cout<<"NO"<<endl;
	else{
		ans = 0;
		for(int i = 1; i <= n; i++)
			if(find(i) == i) ans++;
		if(ans != 1) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
}