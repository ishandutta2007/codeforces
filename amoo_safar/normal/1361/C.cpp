#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ll Mod = 1000000007LL;
const int N = 1048576 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

int n;
int a[N], b[N], mk[N];
int fr[N], to[N];
vector<int> G[N];

void DFS(int u){
	mk[u] = 1;
	int adj;
	for(auto e : G[u]){
		adj = u ^ to[e] ^ fr[e];
		if(!mk[adj]) DFS(adj);
	}
}
vector<int> TE;
void Euler(int u){
	//debug(u);
	int id = -1, adj;
	while(G[u].size()){
		id = G[u].back();
		G[u].pop_back();
		if(mk[id]) continue;
		mk[id] = 1;
		adj = u ^ to[id] ^ fr[id];
		Euler(adj);
		if(u == fr[id]){
			TE.pb(id * 2 + 2);
			TE.pb(id * 2 + 1);	
		} else {
			TE.pb(id * 2 + 1);
			TE.pb(id * 2 + 2);
		}
	}
}
int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d%d", a + i, b + i);
	}
	int p2;
	for(int k = 20; k >= 0; k--){
		p2 = (1 << k);
		for(int i = 0; i < (1 << k); i++) mk[i] = 0, G[i].clear();
		for(int i = 0; i < n; i++){
			fr[i] = a[i] % p2;
			to[i] = b[i] % p2;
			G[a[i] % p2].pb(i);
			G[b[i] % p2].pb(i);
		}
		int st = -1, cnt = 0;
		int fl = 0;
		for(int i = 0; i < p2; i++){
			if(G[i].size() % 2 == 1){
				fl = 1;
				break;
			}
			if(!mk[i] && G[i].size() > 0){
				DFS(i);
				cnt ++;
				st = i;
				if(cnt > 1) break;
			}
		}
		if(fl == 1) continue;
		if(cnt > 1) continue;
		cout << k << '\n';
		memset(mk, 0, sizeof mk);
		Euler(st);
		for(auto x : TE) printf("%d ", x);
		printf("\n");
		break;
	}
	return 0;
}