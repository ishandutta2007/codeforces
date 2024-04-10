# include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

# define F first
# define S second
# define endl '\n'

const int xn = 1e5+10;

bool mark[xn];
int start[xn], finish[xn], n, l[xn], r[xn], str, fin, num, mf[xn], ht[xn], mxd, dx[xn];
vector <int> adj[xn], h[xn], root;

void DFS(int v, int d, int door){
	mark[v] = true;
	mf[v] = door;
	mxd = max(mxd, d);
	start[v] = str++;
	h[d].push_back(v);
	dx[v] = h[d].size()-1;
	ht[v] = d;
	int t = 0, mn = 1e6, mx = 0;
	for (int i=0; i<adj[v].size(); i++){
		int u = adj[v][i];
		if (mark[u]) continue;
		DFS(u, d+1, door);
		t++;
		mn = min(mn, l[u]);
		mx = max(mx, r[u]);
	}
	finish[v] = fin++;
	if (t == 0) l[v] = r[v] = num++;
	else l[v] = mn, r[v] = mx;
}

int ans(int v, int p){
	if (ht[v]-p < 0 or mf[v] != mf[h[ht[v]-p][0]]) return 0;
	
	int t = ht[v]-p;
	int lb = 0, rb = h[t].size(), mid;
	while (rb-lb > 1){
		mid = (lb+rb)/2;
		if (l[h[t][mid]] > r[v]) rb = mid;
		else lb = mid;
	}
	int u = h[t][lb];
	int d = ht[v];
	int x, y;
	lb = -1, rb = dx[v];
	while (rb-lb > 1){
		mid = (rb+lb)/2;
		if (l[u] <= l[h[d][mid]] and r[u] >= r[h[d][mid]]) rb = mid;
		else lb = mid;
	}
	x = rb;
	lb = dx[v], rb = h[d].size();
	while (rb-lb > 1){
		mid = (rb+lb)/2;
		if (l[u] <= l[h[d][mid]] and r[u] >= r[h[d][mid]]) lb = mid;
		else rb = mid;
	}
	y = lb;
	return y-x;
}

int main(){
	cin >> n;
	int x;
	for (int i=1; i<=n; i++){
		cin >> x;
		if (x == 0) root.push_back(i);
		else adj[x].push_back(i);
	}
	int d = 0, door = 0;
	for (int i=0; i<root.size(); i++){
		if (!mark[root[i]]){
			DFS(root[i], d, door);
			door++;
			d = mxd+1;
		}
	}
	int q;
	cin >> q;
	for (int i=0; i<q; i++){
		int v, p;
		cin >> v >> p;
		cout << ans(v, p) << ' ';
	}
}