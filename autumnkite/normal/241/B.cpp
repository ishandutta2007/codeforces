#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <vector>
int read(){
    register int x = 0;
    register char f = 1, ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = !f;
    for (; isdigit(ch); ch = getchar()) x = (x << 3) + (x << 1) + (ch ^ '0');
    return f ? x : -x;
}
#define N 50005
int n, a[N];
long long k, ans;
struct trie{
	int cnt, son[N * 30][2], sz[N * 30], Sz[N * 30][30];
	std :: vector< std :: pair<int, int> > p, tmp;
	trie(){ cnt = 1; }
	void insert(int x){
		int u = 1;
		++sz[1];
		for (register int i = 29; ~i; --i){
			Sz[1][i] += x >> i & 1;
			if (!son[u][x >> i & 1]) son[u][x >> i & 1] = ++cnt;
			u = son[u][x >> i & 1], ++sz[u];
			for (register int j = 0; j < 30; ++j) Sz[u][j] += x >> j & 1;
		}
	}
	int find_kth(long long k){
		int res = 0;
		p.clear(), p.push_back(std :: make_pair(1, 1));
		for (register int i = 29; ~i; --i){
			long long Sum = 0;
			for (auto v : p) for (register int j = 0; j < 2; ++j)
				Sum += 1ll * sz[son[v.first][j]] * sz[son[v.second][j ^ 1]];
			tmp.clear();
			int w = k <= Sum;
			if (!w) k -= Sum;
			res = res << 1 | w;
			for (auto v : p) for (register int j = 0; j < 2; ++j)
				if (son[v.first][j] && son[v.second][j ^ w])
					tmp.push_back(std :: make_pair(son[v.first][j], son[v.second][j ^ w]));
			p = tmp;
		}
		return res;
	}
	std :: pair<long long, int> get_sum(int x, int m){
		std :: pair<long long, int> res = std :: make_pair(0, 0);
		int u = 1;
		for (register int i = 29; ~i; --i){
			int l = x >> i & 1, r = l ^ 1;
			if (m >> i & 1) u = son[u][r];
			else{
				res.second += sz[son[u][r]];
				for (register int j = 0; j < 30; ++j)
					if (x >> j & 1) res.first += 1ll * (sz[son[u][r]] - Sz[son[u][r]][j]) << j;
					else res.first += 1ll * Sz[son[u][r]][j] << j;
				u = son[u][l];
			}
		}
		return res;
	}
}T;
int main(){
	n = read(), k = read(), k <<= 1;
	for (register int i = 1; i <= n; ++i) a[i] = read(), T.insert(a[i]);
	int m = T.find_kth(k);
	std :: pair<long long, int> tmp;
	for (register int i = 1; i <= n; ++i)
		tmp = T.get_sum(a[i], m), ans += tmp.first, k -= tmp.second;
	ans += k * m;
	printf("%lld\n", (ans >> 1) % 1000000007);
}