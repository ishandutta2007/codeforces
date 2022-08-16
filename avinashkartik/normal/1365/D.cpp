#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include<bits/stdc++.h>

using namespace std;
 
#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
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
 
const ll   N     =  60;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test=1, n, m, a[N][N];
string s[N];

void solve(){
	mset(a,0);
	cin>>n>>m;
	for(int i = 1; i <= n; i++){
		cin>>s[i];
		s[i] = '#'+s[i]+'#';
	}
	s[0] = s[n+1] = string(m+2,'#');
	int b = 0, g = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(s[i][j] == 'B') b++;
			if(s[i][j] == 'G') g++;
		}
	}
	if(g == 0){
		deb1("Yes")
		return;
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(s[i][j] == 'B'){
				if(s[i-1][j] == 'G' or s[i+1][j] == 'G' or s[i][j-1] == 'G' or s[i][j+1] == 'G'){
					deb1("No")
					return;
				}
				else{
					if(s[i-1][j] == '.') s[i-1][j] = '#';
					if(s[i+1][j] == '.') s[i+1][j] = '#';
					if(s[i][j-1] == '.') s[i][j-1] = '#';
					if(s[i][j+1] == '.') s[i][j+1] = '#';
				}
			}
		}
	}
	queue <pll> q;
	if(s[n][m] != '#') q.push({n,m});
	while(q.size()){
		pll p = q.front(); q.pop();
		ll i = p.f, j = p.s;
		if(a[i][j] != 1){
			a[i][j] = 1;
			if(s[i-1][j] != '#'){
				q.push({i-1,j});
			}
			if(s[i+1][j] != '#'){
				q.push({i+1,j});
			}
			if(s[i][j-1] != '#'){
				q.push({i,j-1});
			}
			if(s[i][j+1] != '#'){
				q.push({i,j+1});
			}
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(s[i][j] == 'G' and a[i][j] == 0){
				deb1("No")
				return;
			}
		}
	}
	deb1("Yes")
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