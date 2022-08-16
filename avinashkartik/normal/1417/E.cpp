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
typedef  vector<pll>           vpll;

const ll   N     =  3e5+5;
const ll   M     =  4e6+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n, k, a[N], ct[30][2];
ll trie[40*N][2], cnt[40*N][2];
stack <int> s;

void init(){
	mset(trie, -1);
	mset(cnt, 0);
	for(int i = 40*N-1; i >= 1; i--) s.push(i);
}

void insert(ll x){
	int v = 0;
	for(int i = 29; i >= 0; i--){
		int k = (x >> i) & 1;
		if(trie[v][k] == -1){
			trie[v][k] = s.top();
			s.pop();
		}
		if(k) ct[i][1] += cnt[v][1-k];
		else ct[i][0] += cnt[v][1-k];
		cnt[v][k]++;
		v = trie[v][k];
	}
}

void solve(){
	init();
	cin >> n;
	map <pair<int, int>, int> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		insert(a[i]);
	}
	ll ans = 0, inv = 0;
	for(int i = 29; i >= 0; i--){
		inv += min(ct[i][0], ct[i][1]);
		if(ct[i][0] > ct[i][1]) ans += (1 << i);
	}
	deb2(inv, ans)
}

int main(){
	GODSPEED;
	int test = 1;
	//cin >> test;
	for(int i = 1; i <= test; i++){
		solve();
	}
}