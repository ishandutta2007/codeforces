#pragma optimization_level 3
#pragma GCC optimize("Ofast")   //Comment optimisations for an interatcive problem - use endl
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
 
using namespace std;
 
#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;
#define	 x                     first                 
#define  y                     second                
 
const ll   N     =  1e+5+3;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
 
ll l[N],n,k,q,t,s;
string f0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
string f1 = "What are you doing while sending \"";
string f2 = "\"? Are you busy? Will you send \"";
string f3 = "\"?";

void solve(ll n,ll k){
	if(n == 0){
		if(k >= l[n])
			cout<<".";
		else
			cout<<f0[k];
		return;
	}
	if(k >= l[n])
		cout<<".";
	else if(k < (f1).size())
		cout<<f1[k];
	else if(k >= (f1).size() && k < (f1).size()+l[n-1])
		solve(n-1,k-(f1).size());
	else if(k >= (f1).size()+l[n-1] && k < (f1).size()+l[n-1]+(f2).size()){
		t = k - ((f1).size()+l[n-1]);
		cout<<f2[t];
	}
	else if(k >= (f1).size()+l[n-1]+(f2).size() && k < (f1).size()+l[n-1]+(f2).size()+l[n-1])
		solve(n-1,k-((f1).size()+l[n-1]+(f2).size()));
	else{
		t = k - ((f1).size()+l[n-1]+(f2).size()+l[n-1]);
		cout<<f3[t];
	}
	return;
}

int main(){
	fastio;

	l[0] = f0.size();

	for(ll i = 1; i < N; i++){
		ll s = (f1).size()+l[i-1]+(f2).size()+l[i-1]+(f3).size();
		l[i] = min(ll(1e18),s);
	}

	cin>>q;
	while(q--){
		cin>>n>>k;
		solve(n,k-1);
	}

	#ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}