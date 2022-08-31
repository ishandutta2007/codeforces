#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include<bits/stdc++.h>

using namespace std;
 
#define  GODSPEED       ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(15);
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
#define  uniq(a)        a.resize(unique(a.begin(), a.end()) - a.begin());
#define  all(a)         a.begin(),a.end()           
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;

const ll   N     =  5e5+5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test = 1, n, x, y, a[N], b[N];

void solve(){
	map <ll, ll> ct, cntX, cntY;
	set <pll, greater<>> s, Y;
	cin>>n>>x>>y; y -= x;
	for(int i = 0; i < n; i++) cin>>a[i], ct[a[i]]++, b[i] = -1;
	for(int i = 0; i < n; i++) s.insert({ct[a[i]],a[i]});
	for(int i = 0; i < x; i++){
		pll it = *s.begin();
		s.erase(it);
		cntX[it.s]++;
		ct[it.s]--;
		if(it.f > 1) s.insert({it.f-1,it.s});
	}
	int tot = 0;
	while(s.size()){
		if(tot == y) break;
		pll it = *s.begin();
		s.erase(it);
		if(cntY[it.s] == n-x-ct[it.s]) continue;
		cntY[it.s]++;
		if(it.f > 1) s.insert({it.f-1,it.s});
		tot++;
	}
	if(tot != y){ deb1("NO") return; }
	for(int i = 0; i < n; i++) if(cntX[a[i]]) b[i] = a[i], cntX[a[i]]--;
	for(auto it : cntY) Y.insert({it.s,it.f});
	for(int i = 0; i < n; i++){
		if(Y.size() == 0) break;
		if(b[i] != -1) continue;
		auto it = Y.begin();
		if(a[i] == (*it).s) it++;
		if(it == Y.end()) continue;
		b[i] = (*it).s;
		if((*it).f > 1) Y.insert({(*it).f-1,(*it).s});
		Y.erase(it);
	}
	int f = 0;
	for(int i = 1; i <= n+1; i++){
		if(ct.find(i) == ct.end()){
			f = i;
			break;
		}
	}
	deb1("YES")
	while(Y.size()){
		int no = (*Y.begin()).s, val = (*Y.begin()).f, f = n-1;
		for(int i = n-1; i >= 0; i--){
			if(b[i] == -1) { f = i; continue; }
			if(a[i] == b[i]) continue;
			if(a[i] == no or b[i] == no) continue;
			b[f] = b[i];
			b[i] = no;
			break;
		}
		Y.erase(Y.begin());
		if(val > 1) Y.insert({val-1,no});
	}
	for(int i = 0; i < n; i++) cout<< ((b[i] == -1)? f : b[i]) <<" ";
	cout<<endl;
}

int main(){
	GODSPEED;
	cin>>test;
	for(int i = 1; i <= test; i++){
		solve();
	}
	#ifndef ONLINE_JUDGE
	cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
}