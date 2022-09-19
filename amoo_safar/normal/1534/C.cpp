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
const int N = 4e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;


int a[N], b[N];

int mk[N];
vector<int> G[N];
void DFS(int u){
	mk[u] = 1;
	for(auto adj : G[u])
		if(!mk[adj])
			DFS(adj);
}
int Main(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		mk[i] = 0;
		G[i].clear();
	}
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> b[i];
	for(int i = 0; i < n; i++) G[a[i]].pb(b[i]);
	for(int i = 0; i < n; i++) G[b[i]].pb(a[i]);
		ll ans = 1;
	for(int i = 1; i <= n; i++)
		if(!mk[i])
			DFS(i), ans = (ans + ans) % Mod;
	cout << ans << '\n';
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	cin >> T;
	while(T --) Main();
	return 0;
}