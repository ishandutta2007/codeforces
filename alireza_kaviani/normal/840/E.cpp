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

const ll SQ = 256;
const ll MAXN = 5e4 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int n , q , trieInd , A[MAXN] , H[MAXN] , par[MAXN] , Par[MAXN] , mx[MAXN][SQ] , nxt[SQ * 8][2] , val[SQ * 8];
vector<int> adj[MAXN];

void DFS(int v , int p = 0){
	par[v] = p;
	H[v] = H[p] + 1;
	for(int u : adj[v]){
		if(u != p){
			DFS(u , v);
		}
	}
}

void add(int x , int y){
	int cur = 0;
	for(int i = 7 ; i >= 0 ; i--){
		int c = 0;
		if(x & (1 << i))	c = 1;
		if(nxt[cur][c] == 0)	nxt[cur][c] = ++trieInd;
		cur = nxt[cur][c];
	}
	val[cur] = max(val[cur] , y);
}

int get(int x){
	int cur = 0 , res = 0;
	for(int i = 7 ; i >= 0 ; i--){
		int c = 1;
		if(x & (1 << i))	c = 0;
		if(nxt[cur][c] == 0)	c = 1 - c;
		cur = nxt[cur][c];
		res = res * 2 + c;
	}
	res = (res << 8) + val[cur];
	return (res ^ (x << 8));
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n >> q;
	for(int i = 1 ; i <= n ; i++)	cin >> A[i];
	for(int i = 1 ; i < n ; i++){
		int v , u;
		cin >> v >> u;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	DFS(1);
	for(int i = 1 ; i <= n ; i++){
		if(H[i] < SQ)	continue;
		memset(nxt , 0 , sizeof(nxt));
		memset(val , 0 , sizeof(val));
		trieInd = 0;
		int v = i;
		for(int j = 0 ; j < SQ ; j++){
			int val = A[v] ^ j;
			add((val >> 8) , (val & (SQ - 1)));
			v = par[v];
		}
		Par[i] = v;
		for(int j = 0 ; j < SQ ; j++){
			mx[i][j] = get(j);
		}
	}
	while(q--){
		int v , u , h = 0 , ans = 0;
		cin >> v >> u;
		for(int i = 0 ; H[u] - H[v] >= SQ - 1 ; i++ , u = Par[u]){
			ans = max(ans , mx[u][i]);
			h += SQ;
		}
		while(H[u] >= H[v]){
			ans = max(ans , (A[u] ^ h));
			u = par[u];
			h++;
		}
		cout << ans << endl;
	}

    return 0;
}
/*

*/