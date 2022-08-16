#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include<bits/stdc++.h>

using namespace std;
 
#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(15);
#define  f              first                 
#define  s              second
#define  endl           "\n"
#define  pb             push_back  
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" ";cout<<endl;
#define  deb1(a)        cout<<a<<endl;
#define  deb2(a,b)      cout<<a<<" "<<b<<endl;
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<endl;
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;            
          
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;

const ll   N     =  505;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test=1, n, a[N], ct[N];

void rotate(int i){
	swap(a[i+1],a[i+2]);
	swap(a[i],a[i+1]);
}

void solve(){
	mset(ct,0);
	cin>>n;
	vll ans;
	int flag = 0;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
		ct[a[i]]++;
		if(ct[a[i]] == 2) flag = -1;
	}
	for(int i = 1; i <= n; i++){
		int mn = a[i], ind = i;
		for(int j = i+1; j <= n; j++){
			if(a[j] < mn){
				mn = a[j];
				ind = j;
			}
		}
		while(ind > i){
			if(ind-i == 1){
				if(i == n-1 and flag == 0){
					deb1(-1)
					return;
				}
				else if(i == n-1){
					if(flag == -1) flag = n-1;
					for(int j = n-2; j >= flag-1; j--){
						rotate(j);
						ans.pb(j);
					}
				}
				else{
					rotate(i);
					ans.pb(i);
					rotate(i);
					ans.pb(i);
				}
				ind -= 1;
			}
			else{
				rotate(ind-2);
				ans.pb(ind-2);
				ind -= 2;
			}
		}
		if(a[i] == a[i-1]) flag = i;
	}
	//for(int j = 1; j <= n; j++) cout<<a[j]<<" "; cout<<endl;
	assert(ans.size() <= n*n);
	deb1(ans.size())
	debv(ans)
}

int main(){
    fastio;
    cin>>test;
    for(int i = 1; i <= test; i++){
        solve();
    }
    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}