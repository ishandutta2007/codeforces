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

const ll   N     =  6e3+5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test = 1, n, a[N], dp[4005][6005], nxt[N];

bool mem(int ind, int dif){
	if(ind == 2*n) return dif == 4000;
	if(dp[ind][dif] != -1) return dp[ind][dif];
	dp[ind][dif] = mem(nxt[ind],dif+nxt[ind]-ind) | mem(nxt[ind],dif-nxt[ind]+ind);
	return(dp[ind][dif]);
}

void solve(){
	cin>>n;
	for(int i = 0; i < 2*n; i++) for(int j = 0; j < 2*n; j++) dp[i][4000+j] = dp[i][4000-j] = -1;
	for(int i = 0; i < 2*n; i++) cin>>a[i];
	a[2*n] = INF;
	stack <int> s;
	s.push(2*n);
	for(int i = 2*n-1; i >= 0; i--){
		while(a[i] > a[s.top()]) s.pop();
		nxt[i] = s.top();
		s.push(i);
	}
	if(mem(0,4000) == 1) deb1("YES")
	else deb1("NO")
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