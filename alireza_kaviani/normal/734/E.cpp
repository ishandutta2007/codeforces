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

int n , sum , A[MAXN] , H[MAXN];
vector<pii> adj[MAXN];

void DFS(int v , int p = -1){
	for(pii i : adj[v]){
		int u = i.X , w = i.Y;
		if(u == p)	continue;
		H[u] = H[v] + w;
		DFS(u , v);
	}
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n;
	for(int i = 1 ; i <= n ; i++)	cin >> A[i];
	for(int i = 1 ; i < n ; i++){
		int v , u , w;
		cin >> v >> u;
		w = (A[v] != A[u]);
		adj[v].push_back({u , w});
		adj[u].push_back({v , w});
		sum += w;
	}
	if(sum == 0){
		cout << 0 << endl;
		return 0;
	}
	DFS(1);
	int v = max_element(H , H + MAXN) - H;
	H[v] = 0;
	DFS(v);
	int u = max_element(H , H + MAXN) - H;
	cout << (H[u] + 1) / 2 << endl;

    return 0;
}
/*

*/