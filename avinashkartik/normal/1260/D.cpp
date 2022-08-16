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
 
const ll   N  =  2e+5+5;
const ll   MOD   =  1e+9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
 
ll n,a[N],m,k,t,l,r,d;
pll L[N];
vector<pair<pll,ll>> v;
 
int solve(int mid){
	ll curu = 0, curs = 0;
	ll time = 0;
	ll min = a[mid];
	for(auto it : v){
		if(it.y <= min) continue;
		else if(it.x.y <= curu) continue;
		else if(it.x.x > curu){
			time += curu - curs;
			time += it.x.x-curs-1;
			curs = it.x.x-1;
			time += it.x.y - curs;
			curu = it.x.y;
		}
		else{
			time += it.x.y-curu;
			curu = it.x.y; 
		}
		//cout<<curu<<" "<<curs<<" "<<time<<endl;
	}
	time += curu - curs;
	time += n+1 - curs;
	//cout<<curu<<" "<<curs<<" "<<time<<endl;
	if(time > t) return 0;
	else return 1;
}
 
int bs(){  
	l = 0;
	r = m-1;
	ll mid;
	ll ans = m;
	while(r >= l){
		mid = (r+l)/2;
		//cout<<r<<" "<<a[mid]<<endl;
		if(solve(mid) == 0) l = mid + 1;
		else{
			ans = mid;
			r = mid - 1;
		}
	}
	return m-ans;
}
 
int main(){
    fastio;
    cin>>m>>n>>k>>t;
    for(int i = 0; i < m; i++){
    	cin>>a[i];
    }
 
    sort(a,a+m);
 
    for(int i = 0; i < k; i++){
    	cin>>l>>r>>d;
    	v.push_back({{l,r},d});
    }
 
    sort(v.begin(), v.end());
    cout<<bs()<<endl;
}