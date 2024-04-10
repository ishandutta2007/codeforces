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

const ll MAXN = 2e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int n , timer , par[MAXN] , st[MAXN] , fn[MAXN] , A[MAXN] , L[MAXN] , nxt[MAXN] , prv[MAXN] , cnt[MAXN] , fact[MAXN] , mark[MAXN];
vector<int> adj[MAXN];

void Kill(){
	cout << 0 << endl;
	exit(0);
}

void DFS(int v , int p = -1){
	par[v] = p;
	st[v] = timer++;
	for(int u : adj[v]){
		if(u != p){
			DFS(u , v);
		}
	}
	fn[v] = timer;
}

vector<int> getPath(int v , int u , int rev){
	vector<int> ans;
	while(!(st[v] <= st[u] && fn[u] <= fn[v])){
		ans.push_back(v);
		v = par[v];
	}
	if(rev){
		ans.push_back(v);
		reverse(all(ans));
	}
	return ans;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	fill(nxt , nxt + MAXN , -1);
	fill(prv , prv + MAXN , -1);

	fact[0] = 1;
	for(int i = 1 ; i < MAXN ; i++){
		fact[i] = 1ll * fact[i - 1] * i % MOD;
	}
	
	cin >> n;
	for(int i = 1 ; i < n ; i++){
		int v , u;
		cin >> v >> u;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	DFS(1);
	for(int i = 1 ; i <= n ; i++){
		cnt[i] = SZ(adj[i]);
		adj[i].push_back(-1);
		adj[i].push_back(MAXN);
		sort(all(adj[i]));
		L[i + 1] = L[i] + SZ(adj[i]);
	}
	for(int i = 1 ; i <= n ; i++){
		cin >> A[i];
		if(A[i] == 0)	continue;
		vector<int> path = {-1} , tmp1 = getPath(i , A[i] , 0) , tmp2 = getPath(A[i] , i , 1);
		for(int j : tmp1){
			path.push_back(j);
		}
		for(int j : tmp2){
			path.push_back(j);
		}
		path.push_back(MAXN);
		for(int j = 1 ; j + 1 < SZ(path) ; j++){
			int v = path[j] , x = path[j - 1] , y = path[j + 1];
			x = lower_bound(all(adj[v]) , x) - adj[v].begin() + L[v];
			y = lower_bound(all(adj[v]) , y) - adj[v].begin() + L[v];
			if(nxt[x] != -1 || prv[y] != -1){
				Kill();
			}
			nxt[x] = y;
			prv[y] = x;
			cnt[v]--;
		}
	}
	ll ans = 1;
	for(int i = 1 ; i <= n ; i++){
		for(int j = L[i] ; j < L[i + 1] ; j++){
			int x = j , flag = 0;
			if(mark[x])	continue;
			while(x >= 0 && !mark[x]){
				mark[x] = 1;
				if(x == L[i + 1] - 1)	flag = 1;
				x = nxt[x];
			}
			if(x == j){
				Kill();
			}
			if(j == L[i] && flag == 1){
				if(cnt[i] >= 0){
					Kill();
				}
				else{
					cnt[i] = 0;
				}
			}
		}
		ans = ans * fact[cnt[i]] % MOD;
	}
	cout << ans << endl;

    return 0;
}
/*

*/