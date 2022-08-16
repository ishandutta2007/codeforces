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

const ll   N     =  1e6+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n, k, a[N], ct[N], spf[N], cnt[N];

bool calc(int x, int f){
	vll fact;
	while(spf[x] != 1){
		cnt[spf[x]]++;
		fact.pb(spf[x]);
		x /= spf[x];
	}
	if(f == 0){
		for(auto it : fact){
			ct[it] = max(ct[it], cnt[it]);
			cnt[it] = 0;
		}
	} else {
		for(auto it : fact){
			if(cnt[it] > ct[it]) return 0;
		}
	}
	return 1;
}

void solve(){
	for(int i = 1; i < N; i++) spf[i] = i;
	for(int i = 2; i*i < N; i++){
		if(spf[i] == i){
			for(int j = i*i; j < N; j += i) if(spf[j] == j) spf[j] = i;
		}
	}
	cin >> n >> k;
	ll k1 = k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		calc(a[i], 0);
	}
	bool ok = calc(k, 1);
	if(ok) deb1("Yes")
	else deb1("No")
}

int main(){
	GODSPEED;
	int test = 1;
	//cin>>test;
	for(int i = 1; i <= test; i++){
		solve();
	}
}