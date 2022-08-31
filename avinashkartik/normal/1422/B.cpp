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
typedef  unsigned long long    ull;
typedef  long double           ld;
typedef  pair<ll,ull>           pll;
typedef  vector<ll>            vll;
typedef  vector<pll>           vpll;

const ll   N     =  1e6+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n, m, a[105][105];

ll calc(int i1, int i2, int j1, int j2, int x, int y){
	return abs(a[i1][j1] - a[x][y]) + abs(a[i2][j2] - a[x][y]) + abs(a[i1][j2] - a[x][y]) + abs(a[i2][j1] - a[x][y]);
}

void solve(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1;  j <= m; j++){
			cin >> a[i][j];
		}
	}
	ll ans = 0;
	for(int i1 = 1, i2 = n; i1 <= i2; i1++, i2--){
		for(int j1 = 1, j2 = m; j1 <= j2; j1++, j2--){
			if(i1 != i2 and j1 != j2){
				ll tot = INF;
				tot = min(tot, calc(i1, i2, j1, j2, i1, j1));
				tot = min(tot, calc(i1, i2, j1, j2, i1, j2));
				tot = min(tot, calc(i1, i2, j1, j2, i2, j1));
				tot = min(tot, calc(i1, i2, j1, j2, i2, j2));
				ans += tot;
			}
			else if(i1 != i2 and j1 == j2){
				ans += abs(a[i1][j1] - a[i2][j2]);
			}
			else if(i1 == i2 and j1 != j2){
				ans += abs(a[i1][j1] - a[i2][j2]);
			}
		}
	}
	deb1(ans)
}

int main(){
	//GODSPEED;
	int test = 1;
	cin>>test;
	for(int i = 1; i <= test; i++){
		solve();
	}
}