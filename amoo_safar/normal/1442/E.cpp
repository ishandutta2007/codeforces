// nemibinam invara kasi mesle khodemono !
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

int n, a[N], dp[N][3];
vector<int> G[N];

int mx;

void DFS(int u, int p){
	for(auto adj : G[u]){
		if(adj != p)
			DFS(adj, u);
	}
	dp[u][1] = dp[u][2] = mx + 1;
	int rs;
	for(int i = 1; i <= 2; i++){
		if((i != a[u]) && (a[u] != 0)) continue;
		int m1 = 0, m2 = 0;
		for(auto adj : G[u]){
			if(adj == p) continue;
			rs = min(dp[adj][1] + (i != 1), dp[adj][2] + (i != 2));
			if(rs > m1){
				m2 = m1;
				m1 = rs;
			} else {
				m2 = max(m2, rs);
			}
		}
		if(m1 + m2 > mx) continue;
		dp[u][i] = m1;
	}
}

bool Check(int x){
	mx = x;
	DFS(1, -1);
	return min(dp[1][1], dp[1][2]) <= mx;
}

void Main(){
	cin >> n;
	for(int i = 1; i <= n; i++) G[i].clear();
	int u, v;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i < n; i++){
		cin >> u >> v;
		G[u].pb(v);
		G[v].pb(u);
	}
	int L = -1, R = n + 1;
	while(L + 1 < R){
		int mid = (L + R) >> 1;
		if(Check(mid)) R = mid;
		else L = mid;
	}
	cout << 1 + ((R+1) / 2) << '\n';
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll T;
	cin >> T;
	while(T --) Main();
	return 0;
}