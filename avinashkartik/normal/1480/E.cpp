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
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  vector<pll>           vpll;

const ll   N     =  1e6+5;
const ll   mod   =  998244353 ;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

int l, r;
map <int, int> v;
struct edge{
	int u, v, w;
};

void solve(){
	cin >> l >> r;
	vector <edge> ans;
	int j = 31;
	v[32] = l;
	for(int i = 0; i <= floor(log2(r - l + 1)); i++, j--){
		v[j] = (1 << i);
		for(int k = j + 1; k <= 32; k++){
			if(i != floor(log2(r - l + 1))) ans.pb({j, k, v[k]});
			else ans.pb({1, k, v[k]});
		}
	}
	j++;
	ans.pb({1, j, 1});
	int cur = l;
	while(cur <= r){
		int n = r - cur + 1;
		int m = floor(log2(n));
		if(cur != l){
			ans.pb({j, 31 - m, cur - l - 1});
		}
		cur += (1 << int(log2(n)));
	}
	deb1("YES")
	deb2(32, ans.size())
	for(auto it : ans){
		deb3(it.u, it.v, it.w)
	}
}

int main(){
	GODSPEED;
	int test = 1;
	//cin >> test;
	for(int i = 1; i <= test; i++){
		solve();
	}
}