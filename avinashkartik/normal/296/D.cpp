#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include<bits/stdc++.h>

using namespace std;
 
#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
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
typedef  unordered_map<ll,pll>  um;
typedef  vector<pll>           vpll;
 
const ll   N     =  505;
const ll   mod   =  1e9+7;
const ll   INF   =  1e18;
const int  INFi  =  0x7f7f7f7f;

ll test = 1, n, adj[N][N], vis[N];
vll a;

ll fw(){
    vll d(n+1, INF);
    vll ans;
    for(int ind = n-1; ind >= 0; ind--){
    	int i = a[ind];
		for(int j = 1; j<=n; j++){
			for(int k = 1; k<=n; k++){
				if(j == k) continue;
				if(adj[j][k] > adj[j][i] + adj[i][k]){
					adj[j][k] = adj[j][i] + adj[i][k];
				}
			}
		}
		vis[i] = 1;
		ll res = 0;
		for(int j = 1; j<=n; j++){
			for(int k = 1; k<=n; k++){
				if(vis[j] == 1 and vis[k] == 1)
					res += adj[j][k];
			}
		}
		ans.pb(res);
	}
	reverse(ans.begin(), ans.end());
	debv(ans)
}

void solve(){
    cin>>n;
    for(int i = 1; i <= n; i++)
    	for(int j = 1; j <= n; j++)
    		cin>>adj[i][j];
    for(int i = 1; i <= n; i++){
    	int x;
    	cin>>x;
    	a.pb(x);
    }
    fw();
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