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

ll test = 1, n;
vpll v;

ll ch(ll b, ll w){
	ll res = 0;
	for(auto it : v){
		if((b-it.f)*(w-it.s) >= 0) res = max(res,max(abs(b-it.f),abs(w-it.s)));
		else res = max(res,abs(b-it.f)+abs(w-it.s));
	}
	return res;
}

ll ts2(ll b){
	ll l = 0, r = 5e5;
    for(int i = 0; i < 35; i++){
        ll m1 = l + (r - l) / 3;
        ll m2 = r - (r - l) / 3;
        ll f1 = ch(b,m1);
        ll f2 = ch(b,m2);
        if (f1 > f2)
            l = m1;
        else
            r = m2;
    }
    ll ans = l;
    for(int i = l+1; i <= r; i++){
    	if(ch(b,i) < ch(b,ans)) ans = i;
    }
    return ans;
}

void ts1() {
	ll l = 0, r = 5e5;
    for(int i = 0; i < 35; i++){
        ll m1 = l + (r - l) / 3;
        ll m2 = r - (r - l) / 3;
        ll f1 = ch(m1,ts2(m1));
        ll f2 = ch(m2,ts2(m2));
        if (f1 > f2)
            l = m1;
        else
            r = m2;
    }
    ll ans = l;
    for(int i = l+1; i <= r; i++){
    	if(ch(i,ts2(i)) <= ch(ans,ts2(ans))) ans = i;
    }
    int b = ans, w = ts2(ans);
    deb1(ch(b,w))
    string res = "";
    for(int i = 0; i < b; i++) res += 'B';
    for(int i = 0; i < w; i++) res += 'N';
    deb1(res)
}

void solve(){
	set <pll> s;
	cin >> n;
	for(int i = 1; i <= n; i++){
		string t; cin >> t;
		int b = 0, w = 0;
		for(auto it : t){
			if(it == 'B') b++;
			else w++;
		}
		s.insert({b,w});
	}
	for(auto it : s) v.pb(it);
	ts1();
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