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

const ll   N     =  2e3+5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

int n;
string s[N];

ll calc(ll i1, ll j1, ll i2, ll j2, ll i3, ll j3, ll f){
	if(i1 == i2 && i1 == i3) return 0;
	if(i1 == i2 && i1 == i3) return 0;
	ll b, h;
	if(f == 1){
		if(i1 == i2) b = abs(j1 - j2), h = abs(i3 - i1);
		else if(i2 == i3) b = abs(j2 - j3), h = abs(i3 - i1);
		else b = abs(j1 - j3), h = abs(i2 - i1);
	} else {
		if(j1 == j2) b = abs(i1 - i2), h = abs(j3 - j1);
		else if(j2 == j3) b = abs(i2 - i3), h = abs(j3 - j1);
		else b = abs(i1 - i3), h = abs(j2 - j1);
	}
	return b * h;
}

void solve(){
	cin >> n;
	for(int i = 0; i < n; i++) cin >> s[i];
	for(int d = 0; d < 10; d++){
		ll ans = 0;
		vector <int> c(4, -1);
		for(int i = 0; i < n; i++){
			int f1 = -1, l1 = -1, f2 = -1, l2 = -1;
			for(int j = 0; j < n; j++){
				if(s[i][j] - '0' == d){
					if(c[0] == -1) c[0] = i;
					c[1] = i;
					l1 = j;
					if(f1 == -1) f1 = j;
				}
				if(s[j][i] - '0' == d){
					if(c[2] == -1) c[2] = i;
					c[3] = i;
					l2 = j;
					if(f2 == -1) f2 = j;
				}
			}
			if(f1 != l1){
				ans = max(ans, calc(f1, i, l1, i, 0, 0, 0));
				ans = max(ans, calc(f1, i, l1, i, 0, n - 1, 0));
				ans = max(ans, calc(f1, i, l1, i, n - 1, 0, 0));
				ans = max(ans, calc(f1, i, l1, i, n - 1, n - 1, 0));
			}
			if(f2 != l2){
				ans = max(ans, calc(i, f2, i, l2, 0, 0, 1));
				ans = max(ans, calc(i, f2, i, l2, 0, n - 1, 1));
				ans = max(ans, calc(i, f2, i, l2, n - 1, 0, 1));
				ans = max(ans, calc(i, f2, i, l2, n - 1, n - 1, 1));
			}
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(s[i][j] - '0' == d){
					if(c[0] != -1){
						ll h = max(abs(i - c[0]), abs(i - c[1]));
						ll b = max(j, n - 1 - j);
						ans = max(ans, b * h);
					}
					if(c[2] != -1){
						ll h = max(abs(j - c[2]), abs(j - c[3]));
						ll b = max(i, n - 1 - i);
						ans = max(ans, b * h);
					}
				}
			}
		}
		cout << ans << " ";
	}
	newl;
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