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

const ll   N     =  3e5+5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N)+1;

ll n, a[N];

void solve(){
	cin >> n;
	set <int> s;
	vector <int> ct(n + 1, 0);
	for(int i = 1; i <= n; i++) cin >> a[i], s.insert(a[i]), ct[a[i]]++;
	string ans(n, '0');
	if(s.size() == n) ans[0] = '1';
	a[0] = a[n + 1] = 0;
	for(int i = 0, j = n + 1, c = 1; i <= n; c++){
		if(a[i + 1] != c && a[j - 1] != c){
			int f = 0;
			while(i < j){
				if(a[i] == c) f = 1;
				i++;
			}
			if(f) ans[n - c] = '1';
			break;
		} else if(ct[c] > 1) {
			ans[n - c] = '1';
			break;
		} else if(a[j - 1] == c) {
			ans[n - c] = '1';
			j--;
		} else {
			ans[n - c] = '1';
			i++;
		}
	}
	deb1(ans)
}

int main(){
	GODSPEED;
	int test = 1;
	cin >> test;
	for(int i = 1; i <= test; i++){
		solve();
	}
	#ifndef ONLINE_JUDGE
	cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
}