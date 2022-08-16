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

const ll   N     =  4e+5+5;
const ll   MAX   =  1e17;
const ll   mod   =  1e+7+3;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n,m,a[N],q,x;

int main() {
	fill_n(a,0,N);
	cin>>q>>x;
	m = 0;
	while(q--){
		cin>>n;
		a[n%x] += 1;
		while(a[m%x] > (m-(m%x))/x)
			m += 1;
		cout<<m<<endl;
	}
}