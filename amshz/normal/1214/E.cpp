# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair <int, int> pii;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9+7;
const int xn = 3e5+10;
const int xm = 2e5+1;
const int SQ = 1000;
const int sq = 1e3+10;
const int inf = 1e9+10;
 
 
int n, d[xn], dx, pnt, mx;
pii a[xn];
vector <int> masir, G[xn];
vector <pii> adj;
 
bool cmp(pii i, pii j){
	return i.F > j.F;
}
 
 
int main(){
	fast_io;
	
	cin >> n;
	for (int i = 0; i < n; i++) cin >> d[i], a[i] = {d[i], i};
	sort(a, a + n, cmp);
	
	mx = a[0].F;
	masir.resize(mx + 1);
	masir[0] = a[0].S * 2, masir[mx] = a[0].S * 2 + 1;
	
	pnt = 1;
	for (int i = 1; i < mx; i++){
		masir[i] = a[pnt].S * 2;
		int next = a[pnt].F - 1 + i;
		if (next == masir.size() - 1) masir.pb(a[pnt].S * 2 + 1);
		else G[next].pb(a[pnt].S * 2 + 1);
		pnt++;
	}
	for (int i = pnt; i < n; i++){
		int v = a[i].S * 2, u = a[i].S * 2 + 1;
		if (a[i].F == 1){
			adj.pb({v, u});
			adj.pb({v, masir[0]});
			continue;
		}
		int next = a[i].F - 2;
		adj.pb({v, masir[0]});
		adj.pb({u, masir[next]});
	}
	for (int i = 0; i < masir.size(); i++){
		if (i > 0) adj.pb({masir[i], masir[i - 1]});
		for (int j = 0; j < G[i].size(); j++) adj.pb({masir[i], G[i][j]});
	}
	
	for (int i = 0; i < adj.size(); i++) cout << adj[i].F + 1 << sep << adj[i].S + 1 << endl;
	
	
	
	return 0;
}