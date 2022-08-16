#pragma optimization_level 3
#pragma GCC optimize("Ofast")   //Comment optimisations for an interatcive problem - use endl
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
 
using namespace std;
 
#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
#define  f              first                 
#define  s              second
#define  endl           "\n"
#define  pb             push_back  
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" "<<endl;
#define  deb1(a)        cout<<a<<" "<<endl;
#define  deb2(a,b)      cout<<a<<" "<<b<<" "<<endl;
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<" "<<endl;
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;             
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,pll>  um;
typedef  vector<pll>           vpll;
 
const ll   N     =  1e3+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test=1,n,x[N][N],y[N][N];
char a[N][N];

ll bfs(ll sti, ll stj){
	queue <pll> q;
	q.push({sti,stj});
	if(x[sti][stj] == -1) sti=-1,stj=-1;
	while(q.size()){
		ll i = q.front().f;
		ll j = q.front().s;
		q.pop();
		if(a[i+1][j] == '.' && x[i+1][j] == sti && y[i+1][j] == stj){
			a[i+1][j] = 'U';
			q.push({i+1,j});
		}
		if(a[i-1][j] == '.' && x[i-1][j] == sti && y[i-1][j] == stj){
			a[i-1][j] = 'D';
			q.push({i-1,j});
		}
		if(a[i][j+1] == '.' && x[i][j+1] == sti && y[i][j+1] == stj){
			a[i][j+1] = 'L';
			q.push({i,j+1});
		}
		if(a[i][j-1] == '.' && x[i][j-1] == sti && y[i][j-1] == stj){
			a[i][j-1] = 'R';
			q.push({i,j-1});
		}
	}
}

void solve(){
	cin>>n;
	for(int i = 0; i <= n+1; i++){
		for(int j = 0; j <= n+1; j++){
			a[i][j] = '.';
			if(i == 0 || j == 0 || i == n+1 || j == n+1) a[i][j] = 'X';
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin>>x[i][j]>>y[i][j];
			if(x[i][j] == i && y[i][j] == j) a[x[i][j]][y[i][j]] = 'X';
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(a[i][j] == 'X')
				bfs(i,j);
			if(a[i][j] == '.' && x[i][j] == -1){
				if(x[i+1][j] == -1) a[i][j] = 'D';
				else if(x[i-1][j] == -1) a[i][j] = 'U';
				else if(x[i][j+1] == -1) a[i][j] = 'R';
				else if(x[i][j-1] == -1) a[i][j] = 'L';
				bfs(i,j);
			}
		}
	}
	bool valid = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(a[i][j] == '.') valid = 0;
		}
	}
	if(valid == 0) cout<<"INVALID"<<endl;
	else{
		cout<<"VALID"<<endl;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				cout<<a[i][j];
			}
			cout<<endl;
		}
	}
}

int main(){
    fastio;
    //cin>>test;
    for(int i = 1; i <= test; i++){
        solve();
    }
}