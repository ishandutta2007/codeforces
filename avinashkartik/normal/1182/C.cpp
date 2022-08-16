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

const ll   N     =  1e6+3;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

int n;
string s[N];
map <pair<int, int>, int> m;
vector <pair <int, int>> v, f, fw, lw;
int adj[N];

void solve(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> s[i];
		int last = 0, no = 0;
		for(auto it : s[i]){
			if(it == 'a' or it == 'e' or it == 'i' or it == 'o' or it == 'u'){
				no++;
				last = it - 'a';
			}
		}
		if(m[make_pair(no, last)]){
			v.pb({i, m[make_pair(no, last)]});
			m[make_pair(no, last)] = 0;
		} else m[make_pair(no, last)] = i;
	}
	for(auto it : m){
		if(it.s == 0) continue;
		if(adj[it.f.f] == 0) adj[it.f.f] = it.s;
		else{
			f.pb({it.s, adj[it.f.f]});
			adj[it.f.f] = 0;
		}
	}
	if(f.size() > v.size()){
		for(int i = 0; i < v.size(); i++){
			fw.pb(f[i]);
			lw.pb(v[i]);
		}
	} else {
		for(int i = 0; i < f.size(); i++){
			fw.pb(f[i]);
			lw.pb(v[i]);
		}
		for(int i = f.size(); i < v.size(); i += 2){
			if(i == v.size() - 1) break;
			fw.pb(v[i]);
			lw.pb(v[i + 1]);
		}
	}
	deb1(fw.size());
	for(int i = 0; i < fw.size(); i++){
		deb2(s[fw[i].f], s[lw[i].f])
		deb2(s[fw[i].s], s[lw[i].s])
	}
}

int main(){
	GODSPEED;
	int test = 1;
	//cin>>test;
	for(int i = 1; i <= test; i++){
		solve();
	}
	#ifndef ONLINE_JUDGE
	cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
}