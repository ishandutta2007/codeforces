#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

#define M 200200
#define N 700500

int n, m, a[M], f[M], l[M], t = 1;
vector<int> g[M];
bool u[M];
int fe[2][N];


void add(int p, int val, int t){
	for (int i = p; i < N; i |= (i + 1))
		fe[t][i] += val;
}

int sum(int r, int t){
	int ans = 0;
	for (int i = r; i >= 0; i = (i&(i + 1)) - 1)
		ans += fe[t][i];
	return ans;
}


void read(void){
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	for (int i = 1, x, y; i < n; ++i){
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
}

void dfs(int v, int p){
	u[v] = 1;
	add(t, a[p] + a[v], t&1);
	f[v] = t++;
	for (auto &to : g[v])
	if (!u[to]){
		dfs(to,v);
		add(t, a[to] + a[v], t % 2);
		t++;
	}

	l[v] = t;
}


void kill(void){
	for (int i = 0, t, v, val; i < m; ++i){
		cin >> t >> v;
		if (t == 1){
			cin >> val;
			add(f[v], val, f[v] & 1);
			add(l[v], (l[v] - f[v]) & 1 ? val : -val, l[v] & 1);
		}
		else
			cout << sum(f[v], f[v] & 1) - sum(f[v] - 1, (f[v] - 1) & 1) << "\n";

	}
}


int main(){
#ifdef ALG
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#else
	ios_base::sync_with_stdio(0);
#endif

	read();
	dfs(1, 0);
	kill();


	return 0;
}