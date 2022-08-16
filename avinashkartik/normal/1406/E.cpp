#include<bits/stdc++.h>

using namespace std;

#define  f              first                 
#define  s              second
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
 
const ll   N     =  1e6+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n, p[N], x;
set <int> s;

void solve(){
	cin >> n;
	for(int i = 1; i <= n; i++) s.insert(i);
	int m = sqrt(n);
	for(int i = 2; i*i <= n; i++){
		if(p[i] == 1) continue;
		for(int j = i*i; j <= n; j += i) p[j] = 1;
	}
	for(int i = 2; i <= m; i++){
		if(p[i] == 1) continue;
		deb2('B', i)
		cin >> x;
		for(int j = i; j <= n; j += i) s.erase(j); 
	}
	deb2('A', 1)
	cin >> x;
	ll ans = 1;
	if(x != s.size()){
		for(int i = 2; i <= m; i++){
			if(p[i] == 1) continue;
			for(int j = i; j <= n; j *= i){
				deb2('A', j)
				cin >> x;
				if(x == 0){
					ans *= j/i;
					break;
				}
				if(j*i > n) ans *= j;
			} 
		}
		for(int i = m+1; i <= n; i++){
			if(p[i] == 1) continue;
			deb2('B', i)
			cin >> x;
			if(x > 1) ans *= i;
		}
	} else {
		vll bag[100];
		int ct = 0;
		for(int i = m+1; i <= n; i++){
			if(p[i] == 1) continue;
			bag[ct/100].pb(i);
			ct++;
		}
		for(int i = 0; i <= ct/100; i++){
			for(auto it : bag[i]){
				deb2('B', it)
				cin >> x;
				s.erase(it);
			}
			deb2('A', 1)
			cin >> x;
			if(x != s.size()){
				for(auto it : bag[i]){
					deb2('B', it)
					cin >> x;
					if(x) ans *= it;
				}
				break;
			}
		}
	}
	deb2('C', ans)
}

int main(){
	int test = 1;
    //cin>>test;
    for(int i = 1; i <= test; i++){
        solve();
    }
    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}