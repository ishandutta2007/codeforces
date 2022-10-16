#include <bits/stdc++.h>
using namespace std;
const int N = 1.5e5 + 5;
vector <int> e[N], rev[N];
int n, m, to[N], have[N];
bool f[N][2];
void solve() {
	cin >> n >> m;
	memset(have, 0, sizeof(have));
	memset(f, 0, sizeof(f));
	for(int i = 0; i <= n + 1; i++) e[i].clear(), rev[i].clear();
	for(int i = 2; i <= n; i++) rev[i].push_back(0);
	for(int i = 1; i < n; i++) e[i].push_back(n + 1);
	for(int i = 1, u, v; i <= m; i++) {
		scanf("%d %d", &u, &v);
		if(u + 1 == v) have[u] = 1;
		else e[u].push_back(v), rev[v].push_back(u);
	}
	to[n + 1] = n + 1, have[0] = have[n] = 1;
	for(int i = n; ~i; i--) to[i] = have[i] ? to[i + 1] : i;
	if(to[0] == n + 1) return cout << 1ll * n * (n - 1) / 2 << endl, void();
	int p = to[0], lst = n + 1;
	f[p][1] = 1;
	while(have[lst - 1]) lst--;
	for(int i = p; i <= n; i++)
		for(int it : e[i])
			if(to[i + 1] >= it - 1)
				for(int t = 0; t < 2; t++)
					f[it - 1][t] |= f[i][t ^ 1];
	for(int i = p + 1; i; i--)
		for(int it : rev[i])
			if(to[it + 1] >= i - 1)
				for(int t = 0; t < 2; t++)
					f[it][t] |= f[i - 1][t ^ 1];
	long long ans = 0, L, R;
	for(int t = 0; t < 2; t++) {
		for(int i = L = R = 0; i <= p; i++) L += f[i][t];
		for(int i = lst - 1; i <= n; i++) R += f[i][t];
		ans += L * R;
	}
	for(int i = L = R = 0; i <= p; i++) L += f[i][0] && f[i][1];
	for(int i = lst - 1; i <= n; i++) R += f[i][0] && f[i][1];
	// for(int i = 0; i <= n; i++) cerr << "check " << i << " " << f[i][0] << " " << f[i][1] << endl;
	// cerr << "last ans L R " << lst << " " << ans << " " << L << " " << R << endl;
	cout << ans - L * R - (to[p + 1] == n + 1) << endl;
}
int main() {
	// freopen("1.in", "r", stdin);
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}

/*
2022/5/2
start thinking at 14:03

.
 x  y.
 queue .
 n * (n - 1) / 2,  0  4 .
, .
 size(queue)  2 -> 1 -> 2 .
 size(queue) = 2 .

u1s1, .

start coding at ??:??
finish debugging at 17:35
*/