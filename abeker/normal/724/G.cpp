#include <cstdio>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

typedef long long ll;
typedef pair <int, ll> pii;

const int MAXN = 200005;
const int MOD = 1000000007;

int N, M;
vector <pii> E[MAXN];
bool bio[MAXN];
ll path[MAXN];
vector <ll> depths, cycles;

void load() {
	scanf("%d%d", &N, &M);
	while (M--) {
		int u, v;
		ll t;
		scanf("%d%d%lld", &u, &v, &t);
		E[u].push_back(pii(v, t));
		E[v].push_back(pii(u, t));
	}
}

inline int add(int x, int y) {
	x += y;
	if (x >= MOD)	x -= MOD;
	return x;
}

inline int mul(int x, int y) {
	return (ll)x * y % MOD;
}

void dfs(int x, int p, ll d) {
	path[x] = d;
	depths.push_back(d);
	bio[x] = true;
	for (auto it : E[x])
		if (!bio[it.first]) 
			dfs(it.first, x, d ^ it.second);
		else if (it.first != p) 
			cycles.push_back(path[x] ^ path[it.first] ^ it.second);
}

int solve_componnent(int root) {
	if (bio[root]) return 0;
	
	depths.clear();
	cycles.clear();
	dfs(root, 0, 0);
	
	int ind = 0, sz = cycles.size();
	for (int i = 0; i < 63; i++) 
		for (int j = ind; j < sz; j++)
			 if (cycles[j] >> i & 1) {
			 	swap(cycles[ind], cycles[j]);
			 	for (int k = 0; k < sz; k++)
			 		if (k != ind && cycles[k] >> i & 1) 
			 			cycles[k] ^= cycles[ind];
			 	ind++;
			 	break;
			 }
	
	int cnt[64][2] = {0};
	for (int i = 0; i < 63; i++) 
		for (auto it : depths)
			cnt[i][it >> i & 1]++;
		
	int res = 0, comp = depths.size();
	int choose = mul(mul(comp, comp - 1), (MOD + 1) / 2);
	for (int i = 0; i < 63; i++) {
		bool has = false;
		for (auto it : cycles)
			if (it >> i & 1) 
				has = true;
		int coef = has ? mul(choose, (1ll << ind - 1) % MOD) : mul(mul(cnt[i][0], cnt[i][1]), (1ll << ind) % MOD);
		res = add(res, mul(coef, (1ll << i) % MOD));
	}
	
	return res;
}

int solve() {
	int sol = 0;
	for (int i = 1; i <= N; i++)
		sol = add(sol, solve_componnent(i));
	return sol;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}