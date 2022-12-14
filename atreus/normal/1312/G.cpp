#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

const int maxn = 1e6 + 10;

int n, k;
int st[maxn], ft[maxn], pos[maxn], Time = 0;
int dp[maxn];
int seg[4 * maxn], num[4 * maxn];
int ord = 1;
vector<pair<int,char>> t[maxn];

int get(int id, int L, int R, int idx){
	if (L + 1 == R){
		ord = 1;
		return seg[id] + ord;
	}
	int mid = (L + R) >> 1;
	if (idx < mid){
		int ret = get(2 * id + 0, L, mid, idx);
		return min(ret, seg[id] + ord);
	}
	else{
		int ret = get(2 * id + 1, mid, R, idx);
		ord += num[2*id+0];
		return min(ret, seg[id] + ord);
	}
}

int add(int id, int L, int R, int l, int r, int val){
	if (r <= L or R <= l)
		return 0;
	if (l <= L and R <= r){
		seg[id] = min(seg[id], val);
		return num[id];
	}
	int mid = (L + R) >> 1;
	int x = add(2 * id + 0, L, mid, l, r, val);
	int y = add(2 * id + 1, mid, R, l, r, val + x);
	return x + y;
}

int a[maxn];
bool mark[maxn];

void dfs(int v, int p = -1){
	if (mark[v])
		dp[v] = get(1, 0, n, st[v]);
	if (p != -1)
		dp[v] = min(dp[v], dp[p] + 1);
	add(1, 0, n, st[v], ft[v], dp[v]);
	for (auto e : t[v])
		dfs(e.first, v);
}

void build(int id, int L, int R){
	seg[id] = n + 1;
	if (L + 1 == R){
		num[id] = mark[pos[L]];
		return;
	}
	int mid = (L + R) >> 1;
	build(2 * id + 0, L, mid);
	build(2 * id + 1, mid, R);
	num[id] = num[2*id+0] + num[2*id+1];
}

void dfsinit(int v){
	pos[Time] = v;
	st[v] = Time ++;
	sort(t[v].begin(), t[v].end(), [] (pair<int,char> fi, pair<int,char> se){ return fi.second < se.second; });
	for (auto e : t[v])
		dfsinit(e.first);
	ft[v] = Time;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++){
		int p;
		char c;
		cin >> p >> c;
		t[p].push_back({i, c});
	}
	n ++;
	cin >> k;
	for (int i = 0; i < k; i++){
		cin >> a[i];
		mark[a[i]] = 1;
	}
	dfsinit(0);
	build(1, 0, n);
	memset(dp, 63, sizeof dp);
	dp[0] = 0;
	dfs(0);
	for (int i = 0; i < k; i++)
		cout << dp[a[i]] << " \n"[i == k-1];
}