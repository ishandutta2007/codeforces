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
 
ll n,a[N],ind;
priority_queue <ll, vll, greater<ll>> q;
 
int main(){
    fastio;
    cin>>n;
    for(int i = 1; i <= n; i++){
    	cin>>a[i];
    	if(a[i] == -1) ind = i;
    }
 
 	ll ch = n;
 	ll ans = 0;
    for(int i = n; i > ind; i--){
    	q.push(a[i]);
    	if(i == ch){
    		ans += q.top();
    		q.pop();
    		ch /= 2;
    	}
    }

    cout<<ans<<endl;
}