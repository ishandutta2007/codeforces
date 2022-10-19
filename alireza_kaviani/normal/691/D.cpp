#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)						(x).begin(),(x).end()
#define X							first
#define Y							second
#define sep							' '
#define endl						'\n'
#define SZ(x)						ll(x.size())

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int n , m , P[MAXN] , par[MAXN] , sz[MAXN];
vector<int> v1[MAXN] , v2[MAXN];

int Find(int v){
	return (par[v] == -1 ? v : par[v] = Find(par[v]));
}

void Union(int v , int u){
	v = Find(v); u = Find(u);
	if(v == u)	return;
	if(sz[v] < sz[u])	swap(v , u);
	par[u] = v;
	sz[v] += sz[u];
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	fill(par , par + MAXN , -1);
	fill(sz , sz + MAXN , 1);

	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++)	cin >> P[i];
	for(int i = 0 ; i < m ; i++){
		int v , u;
		cin >> v >> u;
		Union(v , u);
	}
	for(int i = 1 ; i <= n ; i++){
		v1[Find(i)].push_back(i);
		v2[Find(i)].push_back(P[i]);
	}
	for(int i = 1 ; i <= n ; i++){
		if(Find(i) != i)	continue;
		sort(all(v2[i]) , greater<int>());
		for(int j = 0 ; j < SZ(v1[i]) ; j++){
			P[v1[i][j]] = v2[i][j];
		}
	}
	for(int i = 1 ; i <= n ; i++)	cout << P[i] << sep;

    return 0;
}
/*

*/