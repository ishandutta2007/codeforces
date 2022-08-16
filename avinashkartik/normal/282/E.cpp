#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include<bits/stdc++.h>

using namespace std;
 
#define  GODSPEED       ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(15);
#define  f              first                 
#define  s              second
#define  newl           cout<<"\n";
#define  pb             push_back  
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" ";newl;
#define  deb1(a)        cout<<a<<"\n";
#define  deb2(a,b)      cout<<a<<" "<<b<<"\n";
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<"\n";
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
#define  uniq(a)        a.resize(unique(a.begin(), a.end()) - a.begin());
#define  all(a)         a.begin(),a.end()            
		  
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;

const ll   N     =  1e5+8;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const int  LEVEL =  log2(N)+1;
const int  max_sz = 2;

ll n, a[N], trie[40*N][max_sz], cnt[40*N][max_sz];
stack <int> s;

void init(){
	for(int i = 40*N-1; i >= 1; i--) s.push(i);
}

void insert(ll x){
	int v = 0;
	for(int i = 40;i >= 0;i--){
		int k = (x >> i) & 1;
		if(trie[v][k] == -1){
			trie[v][k] = s.top();
			s.pop();
		}
		cnt[v][k]++;
		v = trie[v][k];
	}
}
 
void remove(ll x) {
	int v = 0;
	for(int i = 40;i >= 0;i--){
		int k = (x >> i) & 1;
		cnt[v][k]--;
		int tmp = trie[v][k];
		if(cnt[v][k] == 0){
			s.push(tmp);
			trie[v][k] = -1;
		}
		v = tmp;
	}
}

ll dfs(ll x, ll res = 0){
	int v = 0;
	for(int i = 40;i >= 0;i--){
		int k = (x >> i) & 1;
		if(trie[v][1^k] != -1){
			v = trie[v][1^k];
			res += (1ll << i);
		} else v = trie[v][k];
	}
	return res;
}

void solve(){
	init();
	mset(trie, -1);
	mset(cnt, 0);
	cin >> n;
	ll exor = 0;
	for(int i = 1; i <= n; i++) cin >> a[i], exor ^= a[i];
	ll pre = 0, ans = 0;
	insert(0);
	for(int i = 1; i <= n; i++){
		pre ^= a[i];
		insert(pre);
		ans = max(ans, dfs(exor^pre));
	}
	deb1(ans)
} 

int main(){
	GODSPEED;
	int test = 1;
	//cin>>test;
	for(int i = 1; i <= test; i++){
		solve();
	}
	#ifndef ONLINE_JUDGE
	cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
}