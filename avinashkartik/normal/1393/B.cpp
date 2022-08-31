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
typedef  vector<pll>           vpll;

const ll   N     =  3e5+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N)+1;

ll test = 1, n, m, ct[N], no[N];
set <pll,greater<>> s;

void solve(){
	cin >> n;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		s.erase({ct[x],x});
		ct[x]++;
		s.insert({ct[x],x});
	}
	cin >> m;
	for(int i = 0; i < m; i++){
		char c; int x;
		cin >> c >> x;
		s.erase({ct[x],x});
		if(c == '+') ct[x]++;
		else ct[x]--;
		s.insert({ct[x],x});
		auto it = s.begin();
		if((*it).f < 4){
			deb1("NO")
			continue;
		}
		int cnt = 0;
		if((*it).f > 5) cnt += ((*it).f-4)/2;
		it++;
		while(it != s.end()){
			if((*it).f > 1) cnt += (*it).f/2;
			else break;
			if(cnt >= 2) break;
			it++;
		}
		if(cnt >= 2) deb1("YES")
		else deb1("NO")
	}
}

int main(){
	GODSPEED;
	//cin>>test;
	for(int i = 1; i <= test; i++){
		solve();
	}
	#ifndef ONLINE_JUDGE
	cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
}