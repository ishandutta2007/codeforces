#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;

typedef pair<int, int> pii;

const int N = 2e4 + 10;
const int M = 4e3 + 10;
const int Log = 20;

int n, p;
vector<pii> seg[N << 2];
void Add(int l, int r, pii obj, int id = 1, int L = 0, int R = N){
	if(r <= L || R <= l) return ;
	if(l <= L && R <= r){
		seg[id].pb(obj);
		return ;
	}
	int mid = (L + R) >> 1;
	Add(l, r, obj, id << 1, L, mid);
	Add(l, r, obj, id << 1 | 1, mid, R);
}

int ans[N];
vector<pii> Q[N];
int dp[Log][M];

void Solve(int dep = 1, int id = 1, int L = 0, int R = N){
	for(auto obj : seg[id])
		for(int i = M - 1; i >= obj.F; i--)
			dp[dep][i] = max(dp[dep][i], dp[dep][i - obj.F] + obj.S);
	if(R -  L == 1){
		for(auto X : Q[L])
			ans[X.S] = dp[dep][X.F];
		return ;
	}
	int mid = (L + R) >> 1;
	memcpy(dp[dep + 1], dp[dep], sizeof dp[dep]);
	Solve(dep + 1, id << 1, L, mid);

	memcpy(dp[dep + 1], dp[dep], sizeof dp[dep]);
	Solve(dep + 1, id << 1 | 1, mid, R);
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> p;
	int c, h, t;
	for(int i = 1; i <= n; i++){
		cin >> c >> h >> t;
		Add(t, t + p, {c, h});
	}
	int q, a, b;
	cin >> q;
	for(int i = 1; i <= q; i++){
		cin >> a >> b;
		Q[a].pb({b, i});
	}
	Solve();

	for(int i = 1; i <= q; i++) cout << ans[i] << '\n';
	return 0;
}