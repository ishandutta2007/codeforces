#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i = (m); i < (n); ++i)
#define FOP(i,m,n) for (int i = (m) - 1; i >= (n); --i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<lli,int>
#define X first
#define Y second

set <int> on_diameter;
vector <int> nums[200010];
int parent[200010];

pii dfs (int v, int pa, int dist) {
	parent[v] = pa;
	pii h = mp(dist, v);
	for (int i : nums[v]) {
		if (i == pa) continue;
		h = max(h, dfs(i, v, dist + 1));
	}
	return h;
}

int main () {
	int n, a, b, now = 0;
	cin >> n;
	fop (i,0,n-1) {
		cin >> a >> b;
		nums[a-1].pb(b-1);
		nums[b-1].pb(a-1);
	}
	int p = dfs(0, -1, 0).Y;
	pii k = dfs(p, -1, 0);
	int x = k.Y;
	while (x != -1) {
		on_diameter.insert(x);
		x = parent[x];
	}
	bool vi[n];
	queue <pii> q;
	fop (i,0,n) {
		if (on_diameter.count(i)) vi[i] = true, q.push({i, 0});
		else vi[i] = false;
	}
	while (q.size()) {
		tie(a, b) = q.front(); q.pop();
		for (int i : nums[a]) {
			if (vi[i]) continue;
			vi[i] = true;
			q.push({i, b + 1});
		}
	}
	cout << k.X + b << endl;
	while (p == a or k.Y == a) {
		a++;
		if (a == n) a = 0;
	}
	cout << p + 1 << ' ' << k.Y + 1 << ' ' << a + 1 << endl;
}