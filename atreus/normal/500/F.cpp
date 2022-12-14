#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 8000 + 10;
const int maxq = 20000 + 10;

struct stuff{
	int cost;
	int happiness;
	stuff(int c = 0, int h = 0){
		cost = c, happiness = h;
	}
};

stuff a[maxn];
vector<stuff> seg[4 * maxn];
vector<pair<int,int> > Q[4 * maxn];
int ans[maxq];
int dp[18][4000 + 10];

void dfs(int id, int L, int R, int h = 0){
	if (h > 0)
		for (int i = 0; i <= 4000; i++)
			dp[h][i] = dp[h - 1][i];
	for (auto it : seg[id])
		for (int j = 4000; j >= it.cost; j--)
			dp[h][j] = max(dp[h][j], dp[h][j - it.cost] + it.happiness); 
	if (L + 1 == R){
		for (auto it : Q[id])
			ans[it.second] = dp[h][it.first];
		return;
	}
	int mid = (L + R) >> 1;
	dfs(2 * id + 0, L, mid, h + 1);
	dfs(2 * id + 1, mid, R, h + 1);
}

void addquery(int id, int L, int R, int idx, int x, int qidx){
	if (idx < L or R <= idx)
		return;
	if (L + 1 == R){
		Q[id].push_back({x, qidx});
		return;
	}
	int mid = (L + R) >> 1;
	addquery(2 * id + 0, L, mid, idx, x, qidx);
	addquery(2 * id + 1, mid, R, idx, x, qidx);
}

void add(int id, int L, int R, int l, int r, stuff x){
	if (r <= L or R <= l)
		return;
	if (l <= L and R <= r){
		seg[id].push_back(x);
		return;
	}
	int mid = (L + R) >> 1;
	add(2 * id + 0, L, mid, l, r, x);
	add(2 * id + 1, mid, R, l, r, x);
}

int lt[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n, p;
	cin >> n >> p;
	vector<int> cm;
	for (int i = 1; i <= n; i++){
		int c, h;
		cin >> c >> h >> lt[i];
		a[i] = stuff(c, h);
		cm.push_back(lt[i]);
		cm.push_back(lt[i]+p);
	}
	sort(cm.begin(), cm.end());
	cm.resize(unique(cm.begin(), cm.end()) - cm.begin());
	int T = cm.size() + 1 + 1;
	for (int i = 1; i <= n; i++){
		int l = lower_bound(cm.begin(), cm.end(), lt[i]) - cm.begin() + 1;
		int r = lower_bound(cm.begin(), cm.end(), lt[i]+p) - cm.begin() + 1;
		add(1, 1, T, l, r, a[i]);
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; i++){
		int a, b;
		cin >> a >> b;
		a = upper_bound(cm.begin(), cm.end(), a) - cm.begin() + 1 - 1;
		if (a == 0){
			ans[i] = 0;
			continue;
		}
		addquery(1, 1, T, a, b, i);
	}
	dfs(1, 1, T);
	for (int i = 0; i < q; i++)
		cout << ans[i] << '\n';
}