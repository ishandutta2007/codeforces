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
#define  x                     first                 
#define  y                     second
#define  endl                  "\n"

const ll   N     =  2e+5+5;
const ll   MAX   =  1e17;
const ll   mod   =  1e+7+3;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll a[N][26],q,l,r,b[26];
string s;
vll v; 

int main() {
	cin>>s;
	ll n = s.size();
	for(int i = 1; i <= n; i++){
		ll ind = s[i-1] - 'a';
		for(int j = 0; j < 26; j++) a[i][j] = a[i-1][j];
		a[i][ind]++;
	}

	cin>>q;
	while(q--){
		v.clear();
		cin>>l>>r;
		for(int i = 0; i < 26; i++){ 
			b[i] = a[r][i] - a[l-1][i];
			//cout<<b[i]<<" ";
			if(b[i])v.push_back(i);
		}
		if(l == r) cout<<"Yes";
		else if(v.size()==1) cout<<"No";
		else if(v.size()>2) cout<<"Yes";
		else{
			if(s[l-1] != s[r-1]) cout<<"Yes";
			else cout<<"No";
		}
		cout<<endl;
	}
}