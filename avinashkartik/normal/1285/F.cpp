#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include<bits/stdc++.h>

using namespace std;
 
#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(15);
#define  f              first                 
#define  s              second
#define  endl           "\n"
#define  pb             push_back  
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" ";cout<<endl;
#define  deb1(a)        cout<<a<<endl;
#define  deb2(a,b)      cout<<a<<" "<<b<<endl;
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<endl;
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;            
          
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;

const ll   N     =  1e5+1;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test = 1, n, a[N], vis[N], inc[N], spf[N], ct[N];
vll fact[N];

ll lcm(ll x, ll y){
	return x*y/__gcd(x,y);
}

int no_of_coprimes(int x){
	int res = 0;
	for(auto it : fact[x]) res += ct[it]*inc[it];
	return res;
}

void solve(){
	for(int i = 1; i < N; i++) {
		for(int j = i; j < N; j += i) fact[j].push_back(i);
		spf[i] = fact[i][1];
		if(i == 1) inc[i] = 1;
		else if((i/spf[i])%spf[i] == 0) inc[i] = 0;
		else inc[i] =- inc[i/spf[i]];
	}
    cin>>n;
    ll ans = 0;
    for(int i = 1; i <= n; i++){
    	cin>>a[i];
    	vis[a[i]]++;
    	if(vis[a[i]] > 1) ans = max(ans,a[i]);
    }
    for(ll i = 1; i < N; i++){
    	stack <ll> s;
    	for(ll j = (N-1)-(N-1)%i; j > 0; j -= i){
    		if(vis[j]){
    			int no = no_of_coprimes(j/i);
    			while(no > 0){
    				if(__gcd(s.top(),j/i) == 1){
    					ans = max(ans,s.top()*j);
    					no--;
    				}
    				for(auto it : fact[s.top()]) ct[it]--;
    				s.pop();
    			}
    			for(auto it : fact[j/i]) ct[it]++;
    			s.push(j/i);
    		}
    	}
    	while(s.size()){
    		for(auto it : fact[s.top()]) ct[it]--;
    		s.pop();
    	}
    }
    deb1(ans)
}

int main(){
    fastio;
    //cin>>test;
    for(int i = 1; i <= test; i++){
        solve();
    }
    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}