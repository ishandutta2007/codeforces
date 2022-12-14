#include <iostream>
#include <deque>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <iomanip>
#include <queue>
#include <time.h>
#include <set>
#include <cstring>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <bitset>
#include <unordered_set>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define In insert
using namespace std;
typedef long long ll;
const int inf = 1e9 + 7, maxn = 1e5 + 100;
vector <pair <int, int> > v;
ll t[maxn], rig[maxn], minn[maxn], maxx[maxn], dp[maxn], lef[maxn], a[maxn], par[maxn];
bool visited[maxn];

void dfs (int u){
	if (lef[u] == 0)
		return;
	dp[lef[u]] = dp[u] + minn[rig[u]];
	dp[rig[u]] = dp[u] + maxx[lef[u]];
	t[lef[u]] = t[u] + 1;
	t[rig[u]] = t[u] + 1;
	dfs (lef[u]);
	dfs (rig[u]);
}

void make_tree (int u){
	if (!lef[u]){
		maxx[u] = a[u];
		minn[u] = a[u];
		return;
	}
	make_tree (lef[u]);
	make_tree (rig[u]);
	minn[u] = minn[lef[u]];
	maxx[u] = maxx[rig[u]];
}

int main(){
    ios_base::sync_with_stdio(false);
	int n, k, root;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> par[i] >> a[i];
		v.PB(MP(a[i], i));
		if (par[i] == -1){
			root = i;
			continue;
		}
	}
	for (int i = 1; i <= n; i++){
		if (i == root)
			continue;
		if (a[i] < a[par[i]])
			lef[par[i]] = i;
		else
			rig[par[i]] = i;
	}
	make_tree (root);
	dfs (root);
	sort (v.begin(), v.end());
	cin >> k;
	for (int i = 1; i <= k; i++){
		int p;
		cin >> p;
		int idx = lower_bound(v.begin(), v.end(), MP(p, 0)) - v.begin();
		if (idx != 0 and (idx == v.size() || lef[v[idx].S] != 0))
			idx --;
		cout << fixed << setprecision (9) << 1.0 * dp[v[idx].S] / t[v[idx].S] << endl;
	}
}