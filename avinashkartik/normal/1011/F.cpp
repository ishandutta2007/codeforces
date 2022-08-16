#pragma optimization_level 3
#pragma GCC optimize("Ofast")   //Comment optimisations for an interatcive problem - use endl
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
 
using namespace std;
 
#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;
#define	 x                     first                 
#define  y                     second                
 
const ll   N     =  1e+6+5;
const ll   MOD   =  1e+9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n,l[N],r[N],ans[N],ch[N],a[N],u,v;
string s;

void dfs(ll i){
	if(ch[i] == 1){
		dfs(l[i]); dfs(r[i]);
		a[i] = a[l[i]]&a[r[i]];
	}
	if(ch[i] == 2){
		dfs(l[i]); dfs(r[i]);
		a[i] = a[l[i]]|a[r[i]];
	}
	if(ch[i] == 3){
		dfs(l[i]); dfs(r[i]);
		a[i] = a[l[i]]^a[r[i]];
	}
	if(ch[i] == 4){
		dfs(l[i]);
		a[i] = a[l[i]]^1;
	}
}

void dfs1(ll i,int flag){
	//cout<<i<<" "<<flag<<endl;
	if(ch[i] == 1){
		if(a[l[i]] == 1 && a[r[i]] == 1){ dfs1(l[i],flag); dfs1(r[i],flag); }
		else if(a[l[i]] == 1){ dfs1(l[i],0); dfs1(r[i],flag); }
		else if(a[r[i]] == 1){ dfs1(r[i],0); dfs1(l[i],flag); }
		else { dfs1(l[i],0); dfs1(r[i],0);}
	}
	if(ch[i] == 2){
		if(a[l[i]] == 0 && a[r[i]] == 0){ dfs1(l[i],flag); dfs1(r[i],flag); }
		else if(a[l[i]] == 0){ dfs1(l[i],0); dfs1(r[i],flag); }
		else if(a[r[i]] == 0){ dfs1(r[i],0); dfs1(l[i],flag); }
		else { dfs1(l[i],0); dfs1(r[i],0);}
	}
	if(ch[i] == 3){
		dfs1(l[i],flag); dfs1(r[i],flag);
	}
	if(ch[i] == 4){
		dfs1(l[i],flag);
	}
	if(ch[i] == 5){
		ans[i] = flag;
	}
}

int main(){
	fastio;
	cin>>n;
	for(int i = 1; i <= n; i++){
		cin>>s;
		if(s[0] == 'A'){
			ch[i] = 1;
			cin>>u>>v;
			l[i] = u;
			r[i] = v;
		}
		if(s[0] == 'O'){
			ch[i] = 2;
			cin>>u>>v;
			l[i] = u;
			r[i] = v;
		}
		if(s[0] == 'X'){
			ch[i] = 3;
			cin>>u>>v;
			l[i] = u;
			r[i] = v;
		}
		if(s[0] == 'N'){
			ch[i] = 4;
			cin>>u;
			l[i] = u;
		}
		if(s[0] == 'I'){
			ch[i] = 5;
			cin>>u;
			a[i] = u;
		}
	}

	dfs(1);
	dfs1(1,1);
	for(int i = 1; i <= n; i++){
		if(ch[i] == 5) cout<<(ans[i]^a[1]);
	}
}