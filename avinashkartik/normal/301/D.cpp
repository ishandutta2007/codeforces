#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include<bits/stdc++.h>

using namespace std;
 
#define  GODSPEED       ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(15);
#define  f              first                 
#define  s              second
#define  newl           cout<<"\n";
#define  pb             push_back  
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" ";newl;
#define  deb1(a)        cout<<a<<"\n";
#define  deb2(a,b)      cout<<a<<" "<<b<<"\n";
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<"\n";
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
#define  uniq(a)        a.resize(unique(a.begin(), a.end()) - a.begin());
#define  all(a)         a.begin(),a.end()           
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  vector<pll>           vpll;

const int  N     =  2e5+5;
const int  mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const int  LEVEL =  log2(N)+1;

int test = 1, n, m, a[N], ind[N], ans[N];
vector <pair<int,int>> qr[N], ql[N];

int tree[N] = {};
 
void update(int idx, int val){ 
    idx++;
    while(idx <= n+1){ 
        tree[idx] += val;
        idx += idx & (-idx); 
    } 
} 
 
int query(int idx){
    idx++;
    int sum = 0;
    while(idx > 0){ 
        sum += tree[idx];
        idx -= idx & (-idx); 
    } 
    return sum; 
}

void solve(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		ind[a[i]] = i;
	}
	for(int i = 1; i <= m; i++){
		int l, r; cin >> l >> r;
		qr[r].pb({l,i});
		ql[l].pb({r,i});
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j*j <= a[i]; j++){
			if(a[i]%j == 0){
				if(ind[j] <= i) update(ind[j],1);
				if(j*j != a[i] and ind[a[i]/j] <= i) update(ind[a[i]/j],1);
			}
		}
		for(auto it : qr[i]){
			ans[it.s] = query(i) - query(it.f-1);
		}
	}
	mset(tree,0);
	for(int i = n; i >= 1; i--){
		for(int j = 1; j*j <= a[i]; j++){
			if(a[i]%j == 0){
				if(ind[j] > i) update(ind[j],1);
				if(j*j != a[i] and ind[a[i]/j] > i) update(ind[a[i]/j],1);
			}
		}
		for(auto it : ql[i]){
			ans[it.s] += query(it.f) - query(i-1);
		}
	}
	for(int i = 1; i <= m; i++) deb1(ans[i])
}

int main(){
	GODSPEED;
	//cin>>test;
	for(int i = 1; i <= test; i++){
		solve();
	}
	#ifndef ONLINE_JUDGE
	cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
}