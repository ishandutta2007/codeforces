#pragma optimization_level 3
#pragma GCC optimize("Ofast")   //Comment optimisations for an lleratcive problem - use endl
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
#define  x                     first                 
#define  y                     second
#define  endl                  "\n"                
 
const ll   N     =  26*26;
const ll   MAXN  =  1e+9;
const ll   mod   =  1e+9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
 
ll n;
string al[N];
string s;

int main(){
    fastio;
    for(int i = 0; i < 26; i++){
    	char ch = (i + 'a');
    	string tmp = "";
    	tmp += ch;
    	for(int j = 0; j < 26; j++){
    		char ch1 = (j + 'a');
    		string tmp1 = tmp;
    		tmp1 += ch1;
    		al[26*i+j] = tmp1;
    	}
    }
    cin>>s;
    n = s.size();
    ll res = 0;
    for(int i = 0; i < N; i++){
    	char k1 = al[i][0], k2 = al[i][1];
    	ll ans = 0,ct = 0;
    	for(int j = n-1; j >= 0; j--){
    		if(s[j] == k1) ans += ct;
    		if(s[j] == k2) ct++;
    	}
    	//if(ans) cout<<ans<<endl;
    	res = max(res,ans);
    }
    for(int i = 0; i < 26; i++){
    	char k1 = i + 'a';
    	ll ct = 0;
    	for(int j = n-1; j >= 0; j--){
    		if(s[j] == k1) ct++;
    	}
    	res = max(res,ct);
    }
    cout<<res<<endl;

}