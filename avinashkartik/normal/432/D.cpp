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

const int  N     =  2e5+5;
const int  mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const int  LEVEL =  log2(N)+1;

ll n, cnt[N], suf[N];

vector <int> LPS(string s) {
    int n = s.length();
    vector <int> lps(n, 0);
    for (int i = 1; i < n; i++) {
        int j = lps[i-1];
        while(j > 0 && s[i] != s[j]) j = lps[j-1];
        if(s[i] == s[j]) j++;
        lps[i] = j;
        cnt[j]++;
    }
    return lps;
}

void solve(){
	string s;
	cin >> s;
	vector <int> lps = LPS(s);
	int j = lps[s.size() - 1];
	vpll ans;
	ans.pb({s.size(), 1});
	for(int i = s.size() - 1; i > 0; i--){
		cnt[lps[i - 1]] += cnt[i];
	}
	while(j){
		ans.pb({j, cnt[j] + 1});
		j = lps[j - 1];
	}
	reverse(all(ans));
	deb1(ans.size())
	for(auto it : ans) deb2(it.f, it.s)
}

int main(){
	GODSPEED;
	int test = 1;
	//cin >> test;
	for(int i = 1; i <= test; i++){
		solve();
	}
	#ifndef ONLINE_JUDGE
	cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
}