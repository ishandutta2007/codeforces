#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include<bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;

template<typename has_less>
using ordered_set =
tree<has_less,
    null_type,
    less<has_less>,
    rb_tree_tag,
    tree_order_statistics_node_update>;


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

const int  N     =  4e5+5;
const int  mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const int  LEVEL =  log2(N)+1;

ll n, p[N], q[N], r[N], fr1[N], fr2[N], fr3[N];
ordered_set <int> s;

void solve(){
	ll mn = 0, sum = 0;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> p[i], s.insert(i-1);
	for(int i = 1; i <= n; i++) fr1[i] = s.order_of_key(p[i]), s.erase(p[i]);
	for(int i = 1; i <= n; i++) cin >> q[i], s.insert(i-1);
	for(int i = 1; i <= n; i++) fr2[i] = s.order_of_key(q[i]), s.erase(q[i]);
	for(int i = n, c = 0; i >= 1; i--){
		fr3[i] = (fr1[i] + fr2[i] + c) % (n - i + 1);
		c = (fr1[i] + fr2[i] + c) / (n - i + 1);
		s.insert(i-1);
	}
	for(int i = 1; i <= n; i++){
		int val = *s.find_by_order(fr3[i]);
		cout << val << " ";
		s.erase(val);
	}
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