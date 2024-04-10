#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <vector>
int read(){
	register int x = 0;
	register char ch = getchar(), f = 1;
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = !f;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
typedef std :: vector<int> per;
#define N 200005
int n, k, cnt, id[100005], f[130][130], val[N];
per a[N], p[130], tmp;
long long ans;
int hash(per a){
	int res = 0;
	for (register int i = 0; i < k; ++i) res = res * 10 + a[i];
	return res;
}
per mul(per a, per b){
	per res(k);
	for (register int i = 0; i < k; ++i) res[i] = b[a[i]];
	return res;
}
int h, t, Q[130], vis[130];
void solve(std :: vector<int> S){
	std :: vector<int> gen;
	memset(vis, 0, sizeof vis), vis[0] = 1, t = 1, Q[1] = 0;
	for (register int i = 0; i < S.size() - 1; ++i){
		if (!vis[val[S[i]]]){
			gen.push_back(val[S[i]]);
			h = 0;
			while (h < t){
				int u = Q[++h];
				for (int w : gen){
					int v = f[u][w];
					if (!vis[v]) Q[++t] = v, vis[v] = 1;
				}
			}
		}
		ans += 1ll * t * (S[i + 1] - S[i]);
	}
}
int main(){
	n = read(), k = read();
	for (register int i = 0; i < k; ++i) tmp.push_back(i);
	while (1){
		p[cnt] = tmp, id[hash(tmp)] = cnt, ++cnt;
		if (!std :: next_permutation(tmp.begin(), tmp.end())) break;
	}
	for (register int i = 0; i < cnt; ++i)
		for (register int j = 0; j < cnt; ++j)
			f[i][j] = id[hash(mul(p[i], p[j]))];
	for (register int i = 1; i <= n; ++i)
		for (register int j = 0; j < k; ++j)
			a[i].push_back(read() - 1);
	for (register int i = 1; i <= n; ++i) val[i] = id[hash(a[i])];
	std :: vector<int> lst;
	val[n + 1] = cnt, lst.push_back(n + 1);
	for (register int i = n; i; --i){
		std :: vector<int> cur;
		cur.push_back(i);
		for (int j : lst) if (val[j] != val[i]) cur.push_back(j);
		solve(lst = cur);
	}
	printf("%lld\n", ans);
}