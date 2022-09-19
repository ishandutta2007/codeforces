// That's How much we have in common
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
typedef pair<int, int> pii;

const ll Mod = 1000000007LL;
const int N = 1e6 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

int n;
int p[N << 1];

int mk[N];
vector<pii> G[N];
int A[N];
int vis[N];
void DFS(int u){
	for(auto [adj, id] : G[u]){
		if(vis[id]) continue;
		vis[id] = 1;
		A[adj] = id;
		DFS(adj);
	}
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	if(n % 2 == 0){
		cout << "First\n";
		for(int i = 0; i < n + n; i++){
			cout << (i % n) + 1 << ' ';
		}
		cout << endl;
		ll rss;
		cin >> rss;
		assert(rss == 0);
		return 0;
	}
	cout << "Second" << endl;
	for(int i = 1; i <= n + n; i++) cin >> p[i];
	for(int i = 1; i <= n + n; i++){
		if(mk[p[i]] == 0){
			mk[p[i]] = i;
			continue;
		}
		int u = i % n;
		int v = mk[p[i]] % n;
		G[u].pb({v, p[i]});
		G[v].pb({u, p[i]});
	}
	for(int i = 0; i < n; i++) DFS(i);
	vector<int> ans;
	
	ll sum = 0;
	for(int i = 0; i < n; i++){
		
		int fnd = -1;
		for(int j = 0; j < 3; j++){
			if(p[j * n + i] == A[i]){
				fnd = j * n + i;
				break;
			}
		}
		assert(fnd != -1);
		ans.pb(fnd);
		sum += fnd;
	}
	if(sum % (n + n) != 0){
		vector<int> pk(n + n + 1, 0);
		for(auto x : ans) pk[x] = 1;
		ans.clear();
		for(int i = 1; i <= n + n; i++) if(!pk[i]) ans.pb(i);
	}
	sort(all(ans));
	for(auto x : ans) cout << x << ' ';
	cout << endl;

	ll result;
	cin >> result;
	assert(result == 0);
	return 0;
}
/*
3
1 2 2 3 1 3

*/