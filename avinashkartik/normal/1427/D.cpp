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

const ll   N     =  2e5+5;
const ll   M     =  4e6+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

int n;
vll a;
vector <vll> ans;

void op(vll v){
	vll res;
	int st = -1;
	for(auto it : v){
		st += it;
		for(int j = st; j > st-it; j--) res.pb(a[j]);
	}
	reverse(all(res));
	a = res;
}

void find(int v, int f){
	vll res;
	int sum = v-1;
	if(f == 0){
		for(int i = 1; i < v; i++) res.pb(1);
		for(int i = v-1; i < n; i++){
			if(a[i] == v){
				if(i - v + 2) res.pb(i - v + 2);
				sum += i - v + 2;
				if(n - sum) res.pb(n - sum);
				break;
			}
		}
	} else {
		for(int i = 0; i < n; i++){
			if(a[i] == v){
				if(i) res.pb(i);
				sum += i;
				if(n - sum) res.pb(n - sum);
				break;
			}
		}
		for(int i = 1; i < v; i++) res.pb(1);
	}
	if(res.size() >= 2) ans.pb(res);
	op(res);
}

void solve(){
	cin >> n;
	a.resize(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 1; i < n + (n&1); i++){
		find(i, i&1);
	}
	deb1(ans.size())
	for(auto it : ans){
		cout << it.size() << " ";
		debv(it)
	}
}

int main(){
	GODSPEED;
	int test = 1;
	//cin>>test;
	for(int i = 1; i <= test; i++){
		solve();
	}
}