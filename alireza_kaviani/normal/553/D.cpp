#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)      (x).begin(),(x).end()
#define X           first
#define Y           second
#define sep         ' '
#define endl        '\n'
#define SZ(x)       ll(x.size())

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;
const double eps = 1e-7;

int n , m , k , bad[MAXN] , mark[MAXN] , deg[MAXN] , L[MAXN];
vector<int> cur , adj[MAXN];

int check(double x){
//	cout << "=========" << endl;
//	cout << x << endl;
	for(int i = 1 ; i <= n ; i++){
		mark[i] = 0;
		deg[i] = SZ(adj[i]);
		L[i] = deg[i] * x + 1 - eps;
//		cout << i << sep << L[i] << sep << deg[i] << endl;
	}
	queue<int> Q; int cnt = 0;
	for(int i = 0 ; i < k ; i++){
		mark[bad[i]] = 1;
		Q.push(bad[i]);
	}
	while(!Q.empty()){
		int v = Q.front(); Q.pop();
		cnt++;
//		cout << "DELETE " << v << endl;
		for(int u : adj[v]){
			if(mark[u])	continue;
			deg[u]--;
			if(deg[u] < L[u]){
				mark[u] = 1;
				Q.push(u);
			}
		}
	}
	return (cnt < n);
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n >> m >> k;
	for(int i = 0 ; i < k ; i++){
		cin >> bad[i];
	}
	for(int i = 0 ; i < m ; i++){
		int v , u;
		cin >> v >> u;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	double l = 0 , r = 1;
	for(int i = 0 ; i < 30 ; i++){
		double mid = (l + r) / 2;
		if(check(mid))	l = mid;
		else	r = mid;
	}
	check(l);
	vector<int> ans;
	for(int i = 1 ; i <= n ; i++){
		if(!mark[i]){
			ans.push_back(i);
		}
	}
	cout << SZ(ans) << endl;
	for(int i : ans){
		cout << i << sep;
	}

    return 0;
}
/*

*/