#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'
 
using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 
const ll Mod = 1e9 + 7;
const ll Inf = 2242545357980376863LL;
const ll Log = 20;
//const ll N = 1ll << Log;
const int Maxn = 1e3 + 10;
const int Base = 101;

set<int> X[Maxn], Y[Maxn];
ll a[Maxn][Maxn];

vector<ll> V, V2;

stack<int> st;

ll f[Maxn], f2[Maxn];

ll solve(ll ind){
	V[0] = -1;
	
	//cerr<<ind << '\n';
	while(!st.empty()) st.pop();
	ll N = V.size();
	V[N-1] = -1;
	//cerr << "N : " << N << '\n';
	st.push(0);
	for(int i = 1; i < N-1; i++){
		//cerr << i << " " << V[i] << '\n';
		while(V[st.top()] > V[i]) st.pop();
		f[i] = st.top();
		st.push(i);
	}
	//cerr << "S" << '\n';
	while(!st.empty()) st.pop();
	st.push(N-1);
	for(int i = N-2; i > 0; i--){
		while(V[st.top()] >= V[i]) st.pop();
		f2[i] = st.top();
		st.push(i);
	}
	ll res = 0;
	
	for(int i = 1; i < N - 1; i++){
		if((f[i] < ind) && (ind < f2[i])) res = max(res, (f2[i] - f[i] - 1) * V[i]);
	}
	return res;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, m, q;
	cin >> n >> m >> q;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++){
			cin >> a[i][j];
			a[i][j] = 1 - a[i][j];
			if(a[i][j]) X[i].insert(j);
			if(a[i][j]) Y[j].insert(i);
		}
	for(int i = 1; i <= n; i++) X[i].insert(0), X[i].insert(m + 1);
	for(int i = 1; i <= m; i++) Y[i].insert(0), Y[i].insert(n + 1);
	
	ll t, x, y;
	for(int i = 0; i < q; i++){
		cin >> t >> x >> y;
		if(t == 1){
			if(a[x][y]) X[x].erase(y);
			if(a[x][y]) Y[y].erase(x);
			a[x][y] = 1 - a[x][y];
			if(a[x][y]) X[x].insert(y);
			if(a[x][y]) Y[y].insert(x);
			continue;
		}
		set<int>::iterator it;
		ll res = 0;
		V.clear();
		V2.clear();
		V.pb(0);
		V2.pb(0);
		for(int i = 1; i <= n; i++){
			it = X[i].lower_bound(y);
			V.pb( (*it) - y);
			if(V.back() == 0) V2.pb(0);
			else V2.pb(y - (*(--it)));
		}
		V.pb(0);
		V2.pb(0);
		res = max(res, solve(x));
		/*
		V.clear();
		V.pb(0);
		for(int i = 1; i <= n; i++){
			V.pb( y - (*(--X[i].upper_bound(y))) );
		}
		V.pb(0);*/
		V2.swap(V);
		res = max(res, solve(x));
		
		V.clear();
		V2.clear();
		V.pb(0);
		V2.pb(0);
		for(int i = 1; i <= m; i++){
			it = Y[i].lower_bound(x);
			V.pb((*it) - x);
			if(V.back() == 0) V2.pb(0);
			else V2.pb(x - (*(--it)));
			//V.pb( (*Y[i].lower_bound(x)) - x);
		}
		V.pb(0);
		V2.pb(0);
		res = max(res, solve(y));
		/*
		V.clear();
		V.pb(0);
		for(int i = 1; i <= m; i++){
			V.pb( x - (*(--Y[i].upper_bound(x))));
		}
		V.pb(0);
		*/
		V2.swap(V);
		res = max(res, solve(y));
		
		cout << res << '\n';
	}
	return 0;
}