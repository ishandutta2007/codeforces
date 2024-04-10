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

ll n , m , flag , ans , mark[MAXN] , col[MAXN] , cnt[2];
vector<int> adj[MAXN];

void DFS(int v){
	mark[v] = 1;
	cnt[col[v]]++;
	for(int u : adj[v]){
		if(mark[u]){
			flag |= (col[v] == col[u]);
			continue;
		}
		col[u] = 1 - col[v];
		DFS(u);
	}
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n >> m;
	if(m == 0){
		cout << 3 << sep << n * (n - 1) * (n - 2) / 6 << endl;
		return 0;
	}
	for(int i = 0 ; i < m ; i++){
		int v , u;
		cin >> v >> u;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	for(int i = 1 ; i <= n ; i++){
		if(!mark[i]){
			cnt[0] = cnt[1] = 0;
			DFS(i);
			for(int j = 0 ; j < 2 ; j++){
				ans += cnt[j] * (cnt[j] - 1) / 2;
			}
		}
	}
	if(flag){
		cout << 0 << sep << 1 << endl;
		return 0;
	}
	if(ans == 0){
		cout << 2 << sep << m * (n - 2) << endl;
		return 0;
	}
	cout << 1 << sep << ans << endl;

    return 0;
}
/*

*/