// vaziat meshki-ghermeze !
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
const int N = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

int a[N], mk[N];
vector<int> G[N];
vector<int> ord;
void DFS(int u){
	mk[u] = 1;
	for(auto adj : G[u])
		if(!mk[adj])
			DFS(adj);
	ord.pb(u);
	a[u] = ord.size();
}
int dp[N];
int Main(){
	int n;
	cin >> n;
	fill(dp, dp + n + 1, 0);
	fill(mk, mk + n + 1, 0);
	ord.clear();
	for(int i = 0; i <= n; i++) G[i].clear();

	for(int i = 1; i <= n; i++){
		int sz;
		cin >> sz;
		int u;
		for(int j = 0; j < sz; j++){
			cin >> u;
			G[u].pb(i);
		}
	}
	for(int i = 1; i <= n; i++)
		if(!mk[i]) DFS(i);
	
	reverse(all(ord));
	for(int i = 1; i <= n; i++){
		for(auto x : G[i])
			if(a[x] > a[i]) return cout << "-1\n", 0;
	}
	for(auto u : ord){
		for(auto adj : G[u])
			dp[adj] = max(dp[adj], dp[u] + (adj < u));
	}
	cout << 1 + *max_element(dp + 1, dp + n + 1) << '\n';
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc = 1;
	cin >> tc;
	while(tc --) Main();
	return 0;
}