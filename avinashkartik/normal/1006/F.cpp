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

const ll   N     =  25;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test = 1, n, m, k, a[N][N], ans = 0, mid;
map <ll,ll> val[N][N];

void mem(ll i, ll j, ll msk){
	if(i + j == mid){
		val[i][j][msk^a[i][j]]++;
		return;
	}
	if(i != n-1) mem(i+1,j,msk^a[i][j]);
	if(j != m-1) mem(i,j+1,msk^a[i][j]);
}

void mem2(ll i, ll j, ll msk){
	if(i + j == mid){
		ans += val[i][j][k^msk];
		return;
	}
	if(i) mem2(i-1,j,msk^a[i][j]);
	if(j) mem2(i,j-1,msk^a[i][j]);
}

void solve(){
    cin>>n>>m>>k;
    for(int i = 0; i < n; i++)
    	for(int j = 0; j < m; j++)
    		cin>>a[i][j];
    mid = (n+m-2)/2;
    mem(0,0,0);
    mem2(n-1,m-1,0);
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