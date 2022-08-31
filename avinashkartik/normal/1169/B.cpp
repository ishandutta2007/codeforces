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
 
const ll   N  =  3e+5+5;
const ll   MOD   =  1e+9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
 
ll n,a[N][2],m,ct1 = 0,ct2 = 0;
um m1,m2;

int main(){
    fastio;
    cin>>n>>m;
    for(int i = 1; i <= m; i++){
    	cin>>a[i][0]>>a[i][1];
    }

    ll x = a[1][0];
    for(int i = 1; i <= m; i++){
    	if(a[i][1] == x || a[i][0] == x) continue;
    	else{
    		ct1++;
    		m1[a[i][0]]++;
    		m1[a[i][1]]++;
    	}
    }

    x = a[1][1];
    for(int i = 1; i <= m; i++){
    	if(a[i][1] == x || a[i][0] == x) continue;
    	else{
    		ct2++;
    		m2[a[i][0]]++;
    		m2[a[i][1]]++;
    	}
    }

    int flag = 0;
    for(int i = 1; i <= n; i++){
    	if(m1[i] == ct1 || m2[i] == ct2) flag = 1;
    }
	
	if(flag == 1) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}