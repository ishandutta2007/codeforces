#pragma optimization_level 3
#pragma GCC optimize("Ofast")   //Comment optimisations for an interatcive problem - use endl
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
 
using namespace std;
 
#define  fastio                ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
#define  f                     first                 
#define  s                     second
#define  endl                  "\n"
#define  pb                    push_back  
#define  mset(a,x)             memset(a,x,sizeof(a))             
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,pll>  um;
typedef  vector<pll>           vpll;
 
const ll   N     =  2e6+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll t=1,n,a[N],b[N],pre[N],res,sa,sb;
um m;

ll bs(ll s){
	ll l = 1;
	ll r = n;
	ll ans = 0;
	while(l <= r){
		ll mid = (l+r)/2;
		if(pre[mid] <= s){
			ans = mid;
			l = mid + 1;
		}
		else{
			r = mid - 1;
		}
	}
	return ans;
}

void solve(){
	cin>>n;
	int flag = 0;
	sa = sb = 0;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
		sa += a[i];
	}
	for(int i = 1; i <= n; i++){
		cin>>b[i];
		sb += b[i];
	}
	if(sa > sb) swap(a,b), flag = 1;
	for(int i = 1; i <= n; i++)
		pre[i] = pre[i-1] + b[i];
	sa = 0;
	for(int i = 1; i <= n; i++){
		sa += a[i];
		ll ind = bs(sa);
		if(sa-pre[ind] == 0){
			if(flag == 0){
				cout<<i<<endl;
				for(int j = 1; j <= i; j++) cout<<j<<" ";
				cout<<"\n"<<ind<<endl;
				for(int j = 1; j <= ind; j++) cout<<j<<" ";
			}
			else{
				cout<<ind<<endl;
				for(int j = 1; j <= ind; j++) cout<<j<<" ";
				cout<<"\n"<<i<<endl;
				for(int j = 1; j <= i; j++) cout<<j<<" ";
			}
			break;
		}
		else if(m[sa-pre[ind]].f){
			//cout<<sa<<" "<<pre[ind]<<endl;
			//cout<<m[sa-pre[ind]].f<<" "<<m[sa-pre[ind]].s<<endl;
			if(flag == 0){
				ll x = m[sa-pre[ind]].f;
				cout<<i-x<<endl;
				for(int j = x+1; j <= i; j++) cout<<j<<" ";
				ll y =	m[sa-pre[ind]].s;
				cout<<"\n"<<ind-y<<endl;
				for(int j = y+1; j <= ind; j++) cout<<j<<" ";
			}
			else{
				ll y = m[sa-pre[ind]].s;
				cout<<ind-y<<endl;
				for(int j = y+1; j <= ind; j++) cout<<j<<" ";
				ll x = m[sa-pre[ind]].f;
				cout<<"\n"<<i-x<<endl;
				for(int j = x+1; j <= i; j++) cout<<j<<" ";
			}
			break;
		}
		else{
			m[sa-pre[ind]] = {i,ind};
		}
	}
}

int main(){
    fastio;
    //cin>>t;
    for(int i = 0; i < t; i++){
        solve();
    }
    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}