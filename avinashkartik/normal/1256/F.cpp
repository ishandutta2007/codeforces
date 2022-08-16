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
 
const ll   N     =  2e+5+3;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
 
int n,a[26],b[26];
string s,t;

int main(){
	fastio;
	ll te;
	cin>>te;
	while(te--){
		fill_n(a,26,0);
		fill_n(b,26,0);
		cin>>n;
		cin>>s>>t;
		for(int i = 0; i<n; i++){
			int ind = int(s[i]) - int('a');
			a[ind]++;
			ind = int(t[i]) - int('a');
			b[ind]++;
		}
		if(n > 26){
			int key = 1;
			for(int i = 0; i<26; i++){ if(a[i] != b[i]) key = 0; }
			if(key == 0) cout<<"NO"<<endl;
			else cout<<"YES"<<endl;
		}
		else{
			int key = 2;
			for(int i = 0; i<26; i++){ 
				if(a[i] != b[i]) key = 0;
				else if(key != 0 && a[i] > 1) key = 1;
			}
			if(key == 0) cout<<"NO"<<endl;
			else if(key == 1) cout<<"YES"<<endl;
			else{
				ll ct = 0, ct1 = 0;
				for(int i = 0; i < n; i++){
					for(int j = 0; j < i; j++){
						if(s[j] > s[i]) ct++;
						if(t[j] > t[i]) ct1++;
					}
				}
				if(ct%2 != ct1%2) cout<<"NO"<<endl;
				else cout<<"YES"<<endl;
			}
		}
	}

	#ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}