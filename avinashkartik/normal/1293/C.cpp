#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>

using namespace std;

#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;
#define  F                     first                 
#define  S                     second
#define  endl                  "\n"

const ll   N     =  3e+5+5;
const ll   MAX   =  1e6+5;
const ll   mod   =  1e+9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n,q,a[2][N],x,y,ind=0,flag;
vpll ch;

int main(){
	fastio;
 	cin>>n>>q;
 	while(q--){
	 	cin>>x>>y;
		x -= 1;
		y -= 1;
		a[x][y] ^= 1;
		flag = 1;
		if(x == 0){
			if(y != 0)
				if(a[x][y]&a[x+1][y-1] == 1) flag = 0;
			if(y != n-1)
				if(a[x][y]&a[x+1][y+1] == 1) flag = 0;
			if(a[x][y]&a[x+1][y] == 1) flag = 0;
		}
		else{
			if(y != 0)
				if(a[x][y]&a[x-1][y-1] == 1) flag = 0;
			if(y != n-1)
				if(a[x][y]&a[x-1][y+1] == 1) flag = 0;
			if(a[x][y]&a[x-1][y] == 1) flag = 0;
		}
		if(flag == 0){
			ch.push_back({x,y});
			cout<<"NO"<<endl;
		}
		else{
			ll len = ch.size();
			for(int j = ind; j < len; j++){
				x = ch[j].F;
				y = ch[j].S;
				flag = 1;
				if(x == 0){
					if(y != 0)
						if(a[x][y]&a[x+1][y-1] == 1) flag = 0;
					if(y != n-1)
						if(a[x][y]&a[x+1][y+1] == 1) flag = 0;
					if(a[x][y]&a[x+1][y] == 1) flag = 0;
				}
				else{
					if(y != 0)
						if(a[x][y]&a[x-1][y-1] == 1) flag = 0;
					if(y != n-1)
						if(a[x][y]&a[x-1][y+1] == 1) flag = 0;
					if(a[x][y]&a[x-1][y] == 1) flag = 0;
				}
				if(flag == 0) break;
				ind += 1;
			}
			if(ind == len)
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
		}
 	}
 }