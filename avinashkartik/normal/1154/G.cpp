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

const ll   N     =  1e7+1;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test = 1, n, m, k, a[N], ct[N];
vll pos[N];

ll lcm(ll x, ll y){
	return x*y/__gcd(x,y);
}

void solve(){
    cin>>n;
    for(int i = 1; i <= n; i++){
    	cin>>a[i];
    	pos[a[i]].pb(i);
    	ct[a[i]]++;
    }
    ll ans = INF, ind1, ind2;
    for(int i = 1; i < N; i++){
    	int m1 = -1, m2 = -1;
    	for(int j = i; j < N; j += i){
    		if(ct[j]){
    			if(m1 == -1) m1 = pos[j][0];
    			else m2 = pos[j][0];
    			if(ct[j] > 1 and m2 == -1) m2 = pos[j][1];
    		}
    		if(m2 != -1) break;
    	}
    	if(m2 != -1){
    		if(ans > lcm(a[m1],a[m2])){
    			ans = lcm(a[m1],a[m2]);
    			ind1 = m1;
    			ind2 = m2;
    		}
    	}
    }
    deb2(min(ind1,ind2),max(ind1,ind2))
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