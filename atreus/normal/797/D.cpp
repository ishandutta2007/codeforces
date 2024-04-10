#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
const int maxn = 1e5 + 10;
const ll inf = 1e18;

int a[maxn], l[maxn], r[maxn], lo[maxn], hi[maxn];
bool root[maxn];
map<int, bool> ok;

void dfs(int v){
	if (l[v] != -1){
		lo[l[v]] = lo[v];
		hi[l[v]] = min(hi[v], a[v]);
		dfs(l[v]);
	}
	if (r[v] != -1){
		lo[r[v]] = max(lo[v], a[v] + 1);
		hi[r[v]] = hi[v];
		dfs(r[v]);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		root[i] = 1;
	for (int i = 1; i <= n; i++){
		cin >> a[i] >> l[i] >> r[i];
		if (l[i] != -1)
			root[l[i]] = false;
		if (r[i] != -1)
			root[r[i]] = false;
	}
	int r;
	for (int i = 1; i <= n; i++)
		if (root[i] == true)
			r = i;
	lo[r] = 0, hi[r] = 1000 * 1000 * 1000 + 1;
	dfs(r);
	int answer = 0;
	for (int i = 1; i <= n; i++)
		if (lo[i] <= a[i] and a[i] < hi[i])
			ok[a[i]] = 1;
	for (int i = 1; i <= n; i++)
		if (!ok.count(a[i]))
			answer ++;
	cout << answer << endl;
}