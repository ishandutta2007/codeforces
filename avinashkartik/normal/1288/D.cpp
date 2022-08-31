#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>

using namespace std;

#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<string,ll>  um;
typedef  vector<pll>           vpll;
#define  x                     first                 
#define  y                     second
#define  endl                  "\n"

const ll   N     =  3e+5+5;
const ll   mod   =  1e+9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll m,n,ans,a[N][10],flag,ind1,ind2;
string b[N],ch;
um mm;

void check(ll i){
	//cout<<ch<<endl;
	ll x = mm[ch];
	if(x && x != i){
		ind1 = i; ind2 = x;
		flag = 1;
	}
}

void con(ll i,ll j){
	if(flag == 1) return;
	if(j == m){ ch[j] = '\0'; check(i); return; }
	if(b[i][j] == '0'){
		ch[j] = '1';
		con(i,j+1);
	}
	else{
		ch[j] = '0';
		con(i,j+1);
		ch[j] = '1';
		con(i,j+1);
	}
}

ll chh(ll mid){
 	mm.clear();
 	flag = 0;
	for(int i = 0; i < n; i++){
 		for(int j = 0; j < m; j++){
 			if(a[i][j] < mid) b[i][j] = '0';
 			else b[i][j] = '1';
 		}
 		mm[b[i]] = i;
 	}
 	for(int i = 0; i < n; i++) con(i,0);
 	return flag;
}

void bs(){
	ll l = 0,r = 1e9, mid;
	ll ans = 0;
	while(l <= r){
		mid = (l+r)/2;
		//cout<<mid<<" ";
		if(chh(mid)){
			l = mid + 1;
		}
		else{
			r = mid - 1;
		}
	}
	cout<<ind1+1<<" "<<ind2+1<<endl;
}

int main(){
	fastio;
 	cin>>n>>m;
 	for(int j = 0; j < m; j++) ch += '0';
 	for(int i = 0; i < n; i++){
 		for(int j = 0; j < m; j++){
 			cin>>a[i][j];
 			b[i] += '0';
 		}
 	}
 	bs();
 }