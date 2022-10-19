#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 1e5 + 5;

int N, M;
vector <int> adj[MAXN];
int bio[MAXN];
pii dp[MAXN][3];
int pos[MAXN];
int sum[MAXN];
int len, cookie;
vector <int> v, res, path;
bool memo[MAXN][3];

void load() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
	}
}

bool dfs(int x) {
	if (bio[x] == 2)
		return false;
	if (bio[x] == 1) {
		for (; path.back() != x; path.pop_back())
			res.push_back(path.back());
		res.push_back(x);
		reverse(res.begin(), res.end());
		return true;
	}
	bio[x] = 1;
	path.push_back(x);
	for (auto it : adj[x])
		if (dfs(it))
			return true;
	bio[x] = 2;
	path.pop_back();
	return false;
}

vector <int> find_cycle(vector <int> out) {
	memset(bio, 0, sizeof bio);
	for (auto it : out)
		bio[it] = 2;
		
	res.clear();
	path.clear();
	for (int i = 1; i <= N; i++)
		if (dfs(i))
			return res;
			
	return res;
}

inline void update(pii &p, pii c, int curr) {
	if (c.first < curr)
		p.first = max(p.first, c.first);
	if (c.second >= curr || curr == len)
		p.second = min(p.second, c.second);
}

void calc(int x, int y) {
	dp[x][y] = {-1, MAXN};
	
	memo[x][y] = true;
	for (auto it : adj[x]) {
		pii cand = {-2, -2};
		if (pos[it] == -1) {
			if (!memo[it][y])
				calc(it, y);
			cand = dp[it][y];
		}
		else if (pos[x] == -1 || pos[it] != (pos[x] + 1) % len)
			cand = {pos[it], pos[it]};
		
		if (cand.first != -2)
			update(dp[x][y], cand, v[y]);
	}
}

void add(int l, int r) {
	if (l < 0 || l >= len)
		return;
	sum[l]++;
	sum[r + 1]--;
	if (l > r)
		sum[0]++;
	cookie++;
}

int solve() {	
	vector <int> cyc = find_cycle({});
	assert(!cyc.empty());
	
	if (!find_cycle(cyc).empty())
		return -1;
		
	memset(pos, -1, sizeof pos);
	len = cyc.size();
	for (int i = 0; i < len; i++)
		pos[cyc[i]] = i;
	
	int lo = 0, hi = len, iter = 0;
	while (hi - lo > 1) {
		int mid = (lo + hi) / 2;
		v = {lo, mid, hi};
		for (int i = 1; i <= N; i++)
			for (int j = 0; j < 3; j++)
				memo[i][j] = false;
			
		for (auto it : cyc) {
			if (!memo[it][1]) 
				calc(it, 1);
			if (iter)
				continue;
			if (!memo[it][0])
				calc(it, 0);
			if (!memo[it][2])
				calc(it, 2);
		}
		
		iter++;
		
		bool ok = false;
		for (int i = lo; i < mid; i++)
			if (dp[cyc[i]][0].second <= i) {
				hi = mid;
				for (int j = 1; j <= N; j++)
					dp[j][2] = dp[j][1];
				ok = true;
				break;
			}
		
		if (ok)
			continue;
		
		for (int i = mid; i < hi; i++)
			if (dp[cyc[i]][1].second <= i) {
				lo = mid;
				for (int j = 1; j <= N; j++)
					dp[j][0] = dp[j][1];
				ok = true;
				break;
			}
		
		if (ok)
			continue;
		
		for (int i = 0; i < len; i++) {
			add(dp[cyc[i]][2].first, i);
			add(dp[cyc[i]][2].second, i);
			if (i >= lo && i < mid)
				add(dp[cyc[i]][0].first, i);
			if (i >= mid && i < hi)
				add(dp[cyc[i]][1].first, i);
		}
		
		for (int i = 1; i < len; i++)
			sum[i] += sum[i - 1];
		
		for (int i = lo; i < hi; i++)
			if (sum[i] == cookie)
				return cyc[i];
		
		return -1;
	}
	
	for (int i = 0; i < 2; i++)
		if (lo + i < len && find_cycle({cyc[lo + i]}).empty())
			return cyc[lo + i];
	
	return -1;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}