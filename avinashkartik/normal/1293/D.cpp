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

const ll   N     =  1e+3+5;
const ll   MAX   =  1e17;
const ll   mod   =  1e+7+3;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll prime[mod];
ll n,x0,yy0,ax,bx,ay,by,xs,ys,t,x,y;
vpll v;

int main() {
	cin>>x0>>yy0>>ax>>ay>>bx>>by>>xs>>ys>>t;
	x = x0;
	y = yy0;
	while(x < MAX && y < MAX && x >= 0 && y >= 0){
		v.push_back({x,y});
		x = ax*x+bx;
		y = ay*y+by;
	}
	n = v.size();
	int ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = i; j < n; j++){
			ll d = 0;
			for(int k = i+1; k <= j; k++){
				d += abs(v[k].x - v[k-1].x) + abs(v[k].y - v[k-1].y);
			}
			if(d + abs(v[i].x - xs) + abs(v[i].y - ys) <= t || d + abs(v[j].x - xs) + abs(v[j].y - ys) <= t) ans = max(ans,j-i+1);
		}
	}
	//for(auto it : v)cout<<it.x<<" "<<it.y<<endl;
	cout<<ans<<endl;
}