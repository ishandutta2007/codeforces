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
 
const ll   N     =  2e3+5;
const ll   mod   =  998244353;
const ll   INF   =  1e18;
const int  INFi  =  0x7f7f7f7f;

ll test = 1, n, m, vis[N][N][2], nxt[N][N][2], prv[N][N][2];
vector <pair<ll,pll>> ans;
string s[N];

int findprv(ll x, ll y, ll f){
	return (prv[x][y][f] == (1-f)*x+f*y)? (1-f)*x+f*y: prv[x][y][f] = (f == 0)? findprv(prv[x][y][f],y,f): findprv(x,prv[x][y][f],f);
}
 
int findnxt(ll x, ll y, ll f){
	return (nxt[x][y][f] == (1-f)*x+f*y)? (1-f)*x+f*y: nxt[x][y][f] = (f == 0)? findnxt(nxt[x][y][f],y,f): findnxt(x,nxt[x][y][f],f);
}

void put(int x, int y){
	int ct = 0, res = INFi;
	ct = x-findprv(x,y,0);
	res = min(res,ct);
	ct = findnxt(x,y,0)-x;
	res = min(res,ct);
	ct = y-findprv(x,y,1);
	res = min(res,ct);
	ct = findnxt(x,y,1)-y;
	res = min(res,ct);
	res--;
	if(res){
		vis[x-res][y][0] += 1;
		vis[x+res+1][y][0] -= 1;
		vis[x][y-res][1] += 1;
		vis[x][y+res+1][1] -= 1;
		ans.pb({x,{y,res}});
	}
}
void solve(){
	cin>>n>>m;
	for(int i = 1; i <= n; i++){
		cin>>s[i];
		s[i] = '.'+s[i]+'.';
	}
	s[0] = s[n+1] = string(m+2,'.');
	for(int i = 0; i <= n+1; i++){
		for(int j = 0; j <= m+1; j++){
			if(s[i][j] == '*'){
				nxt[i][j][0] = i+1;
				nxt[i][j][1] = j+1;
				prv[i][j][0] = i-1;
				prv[i][j][1] = j-1;
			}
			else{
				nxt[i][j][0] = i;
				nxt[i][j][1] = j;
				prv[i][j][0] = i;
				prv[i][j][1] = j;
			}
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(s[i][j] == '*') put(i,j);
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			vis[i][j][0] += vis[i-1][j][0];
			vis[i][j][1] += vis[i][j-1][1];
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(s[i][j] == '*' and vis[i][j][0]+vis[i][j][1] == 0){
				deb1(-1)
				return;
			}
		}
	}
	deb1(ans.size());
	for(auto it : ans) deb3(it.f,it.s.f,it.s.s)
}

int main(){
	fastio;
	//cin>>test;
	for(int i = 1; i <= test; i++){
		solve();
	}
	#ifndef ONLINE_JUDGE
	cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
}