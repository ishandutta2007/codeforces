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

const ll   N     =  5e3+1;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

int n, k, x[N], y[N], x2[N], y2[N], v[N];
vector <int> adj[N];

ll tree[2*N] = {};
 
void update(int idx, int val){ 
    idx++;
    while(idx <= 2*N-1){ 
        tree[idx] += val;
        idx += idx & (-idx); 
    } 
} 
 
ll query(int idx){
    idx++;
    ll sum = 0;
    while(idx > 0){ 
        sum += tree[idx];
        idx -= idx & (-idx); 
    } 
    return sum; 
}

bool inter(int i, int j){
	if(v[i] == v[j]) return 0;
	if(v[i] == 1) swap(i, j);
	int a = y[j] - y[i], b = y[j] - y2[i];
	if(a*b > 0) return 0;
	a = x[i] - x[j], b = x[i] - x2[j];
	if(a*b > 0) return 0;
	return 1;
}

void solve(){
	cin >> n;
	vector <pair<int, int>> X; 
	for(int i = 1; i <= n; i++){
		cin >> x[i] >> y[i] >> x2[i] >> y2[i];
		x[i] += N, y[i] += N, x2[i] += N, y2[i] += N;
		if(x[i] == x2[i]){
			if(y[i] > y2[i]) swap(y[i], y2[i]);
			X.pb({x[i], i});
		} else {
			if(x[i] > x2[i]) swap(x[i], x2[i]);
			v[i] = 1;
		}
	}
	sort(all(X));
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(inter(i, j)){
				adj[i].pb(j);
			}
		}
	}
	ll ans = 0;
	for(int i = 0; i < X.size(); i++){
		int ind = X[i].s;
		multiset <pair<int, int>> s;
		for(auto it : adj[ind]){
			s.insert({x2[it], y[it]});
			update(y[it], 1);
		}
		for(int j = i+1; j < X.size(); j++){
			int ind = X[j].s;
			while(s.size()){
				auto it = *s.begin();
				if(it.f >= x[ind]) break;
				update(it.s, -1);
				s.erase(s.find(it));
			}
			int m = query(y2[ind]) - query(y[ind] - 1);
			ans += m * (m - 1) / 2;
		}
		while(s.size()){
			auto it = *s.begin();
			update(it.s, -1);
			s.erase(s.find(it));
		}
	}
	deb1(ans)
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