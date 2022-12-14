#include <cstring>
#include <algorithm>
#include <map>
#include <stack>
#include <cassert>
#include <cmath>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <vector>
#include <iostream>
#include <set>
#define MP make_pair
#define F first
#define PB push_back
#define S second
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 50;
const int mod = 1e9 + 7;
const int inf = (1 << 30);
int mytime = 1, seg[4 * maxn][5], stdf[maxn], stb[maxn], fi[maxn], dp[maxn], a[maxn], b[maxn], h[maxn];
bool visited[maxn];
vector <int> v[maxn];

void dfs (int u, int height = 0, int par = -1){
	stdf[u] = mytime ++;
	h[u] = height;
	for (auto w : v[u]){
		if (w != par){
			dfs (w, height + 1, u);
			dp[u] += dp[w] + 1;
		}
	}
	fi[u] = mytime;
}

void bfs (int u){
	mytime = 1;
	queue <int> q;
	visited[u] = 1;
	q.push (u);
	while (!q.empty()){
		u = q.front();
		stb[u] = mytime ++;
		q.pop();
		for (auto w : v[u]){
			if (!visited[w]){
				visited[w] = 1;
				q.push (w);
			}
		}
	}
}

ll get (int id, int L, int R, int idx, int type){
	if (L + 1 == R){
		return seg[id][type];
	}
	int mid = (L + R) / 2;
	ll ret = seg[id][type];
	if (mid > idx)
		ret += get (2 * id + 0, L, mid, idx, type);
	else
		ret += get (2 * id + 1, mid, R, idx, type);
	return ret;
}

void change (int id, int L, int R, int l, int r, int val, int type){
	if (l >= r)
		return;
	if (L == l and R == r){
		seg[id][type] += val;
		return;
	}
	int mid = (L + R) / 2;
	if (mid > l)
		change (2 * id + 0, L, mid, l, min (mid, r), val, type);
	if (mid < r)
		change (2 * id + 1, mid, R, max (l, mid), r, val, type);
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n - 1; i++){
		int u, w;
		cin >> u >> w;
		v[u].PB (w);
		v[w].PB (u);
	}
	
	dfs (1, 0);
	bfs (1);
	for (int i = 1; i <= n; i++){
		a[stdf[i]] = i;
		b[stb[i]] = h[i];
	}
	for (int i = 1; i <= q; i++){
		int type;
		cin >> type;
		if (type == 0){
			int u, x, d;
			cin >> u >> x >> d;
			int ind = upper_bound (b + 1, b + n + 1, d - h[u]) - b;
			if (d < h[u]) {
				int l = stdf[u] - d;
				int r = min (stdf[u] + d, stdf[u] + dp[u]) + 1;
				change (1, 1, n + 1, l, r, x, 1);
			}	
			else {
				int r = stdf[u] + d + 1;
				if (stdf[u] != 1)
					r = min (r, stdf[u] + dp[u] + 1);
				int l = stdf[u] - (h[u] - (d - h[u] + 1));
				change (1, 1, n + 1, l, r, x, 1);
				change (1, 1, n + 1, 1, ind, x, 2);
			}
		}
		else {
			int u;
			cin >> u;
			int tmp = get (1, 1, n + 1, stdf[u], 1);
			tmp += get (1, 1, n + 1, stb[u], 2);
			cout << tmp << endl;
		}
	}
}