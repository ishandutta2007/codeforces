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

int n , m , mark[MAXN];
vector<int> vec , odd;
vector<pii> adj[MAXN];

void Tour(int v){
	while(SZ(adj[v])){
		int u = adj[v].back().X , w = adj[v].back().Y;
		adj[v].pop_back();
		if(mark[w])	continue;
		mark[w] = 1;
		Tour(u);
	}
	vec.push_back(v);
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n >> m;
	for(int i = 0 ; i < m ; i++){
		int v , u;
		cin >> v >> u;
		adj[v].push_back({u , i});
		adj[u].push_back({v , i});
	}
	for(int i = 1 ; i <= n ; i++){
		if(SZ(adj[i]) % 2 == 1){
			odd.push_back(i);
		}
	}
	for(int i = 0 ; i < SZ(odd) ; i += 2){
		adj[odd[i]].push_back({odd[i + 1] , m});
		adj[odd[i + 1]].push_back({odd[i] , m++});
	}
	Tour(1);
	if(m % 2 == 1){
		vec.push_back(1); m++;
	}
	cout << m << endl;
	for(int i = 0 ; i + 2 < SZ(vec) ; i += 2){
		cout << vec[i] << sep << vec[i + 1] << endl;
		cout << vec[i + 2] << sep << vec[i + 1] << endl;
	}

    return 0;
}
/*

*/