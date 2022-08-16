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
 
const ll   N  =  2e+5+5;
const ll   MOD   =  1e+9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
 
ll n,a[N],ans;
vll v;
multiset <ll> s;

void primeFactors(int n){  
 
    while (n % 2 == 0){  
        v.push_back(2);  
        n = n/2;  
    }  

    for (int i = 3; i <= sqrt(n); i = i + 2){  
        while (n % i == 0){  
            v.push_back(i);  
            n = n/i;  
        }  
    }  

    if (n > 2)  
        v.push_back(n);  
}
 
int main(){
    fastio;
    cin>>n;
    for(int i = 0; i < n; i++){
    	cin>>a[i];
    	primeFactors(a[i]);
    	s.insert(1);
    }

    sort(v.begin(), v.end(), greater <ll>());

    for(auto it : v){
    	auto i = s.begin();
    	ll val = *i;
    	s.erase(i);
    	val *= it;
    	s.insert(val); 
    }

    for(auto it : s) ans += it;
    cout<<ans<<endl;


}