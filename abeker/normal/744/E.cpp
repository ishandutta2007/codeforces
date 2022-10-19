// sjest ce vam ono
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 35;
const int MAXL = 1e5 + 5;
const int BASE = 3137;
const int MOD = 1e9 + 7;

struct node {
	int id, pos, type;
	bool operator !=(const node &rhs) const {
		return id != rhs.id || pos != rhs.pos || type != rhs.type;
	}
};

int N;
int len[MAXN];
char s[MAXN][MAXL];
int pref[MAXN][MAXL];
int who[MAXN][MAXL];
int pot[MAXL];
vector <node> E[MAXN][MAXL][2];
int disc[MAXN][MAXL][2], low[MAXN][MAXL][2];
bool on[MAXN][MAXL][2];
stack <node> S;
int timer;

void load() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%s", s[i] + 1);
}

inline int add(int x, int y) {
	x += y;
	if (x >= MOD)
		x -= MOD;
	else if (x < 0)
		x += MOD;
	return x;
}

inline int mul(int x, int y) {
	return (long long)x * y % MOD;
}

int get(int x, int lo, int hi) {
	return add(pref[x][hi], -mul(pref[x][lo - 1], pot[hi - lo + 1]));
}

bool tarjan(node x) {
	int &ref = low[x.id][x.pos][x.type];
	ref = disc[x.id][x.pos][x.type] = timer++;
	on[x.id][x.pos][x.type] = true;
	S.push(x);
	for (auto it : E[x.id][x.pos][x.type])
		if (!disc[it.id][it.pos][it.type]) {
			if (!tarjan(it))
				return false;
			ref = min(ref, low[it.id][it.pos][it.type]);
		}
		else if (on[it.id][it.pos][it.type])
			ref = min(ref, disc[it.id][it.pos][it.type]);
	if (ref != disc[x.id][x.pos][x.type])
		return true;
	vector <node> tmp;
	for (node curr = {-1, -1, -1}; !S.empty() && curr != x; S.pop()) {
		curr = S.top();
		tmp.push_back(curr);
		on[curr.id][curr.pos][curr.type] = false;
	}
	if (tmp.size() == 1)
		return true;
	for (auto it : tmp)
		if (it.pos > 1 && !it.type)
			return false;
	return true;
}

void add_edges(int x, int y, int lo, int hi) {
	for (int i = 0; i < 2; i++) {
		E[x][y][i].clear();
		disc[x][y][i] = 0;
		on[x][y][i] = false;
	}
	
	int l = len[x] - y + 1;
	for (int i = lo; i <= hi; i++)
		if (len[i] <= l) {
			if (pref[i][len[i]] == get(x, y, y + len[i] - 1))
				for (int j = 0; j < 2; j++)
					if (len[i] == l)
						E[x][y][j].push_back({0, 0, 0});
					else
						E[x][y][j].push_back({x, y + len[i], j});
		}
		else {
			if (get(x, y, len[x]) == pref[i][l])
				for (int j = 0; j < 2; j++)
					E[x][y][j].push_back({i, l + 1, j ^ 1});
		}
}

bool check(int lo, int hi) {
	E[0][0][0].clear();
	for (int i = lo; i <= hi; i++)
		E[0][0][0].push_back({i, 1, 0});
		
	for (int i = lo; i <= hi; i++)
		for (int j = 1; j <= len[i]; j++)
			add_edges(i, j, lo, hi);
			
	timer = 1;
	S = stack <node> ();
	for (int i = lo; i <= hi; i++)
		for (int j = 1; j <= len[i]; j++)
			for (int k = 0; k < 2; k++)
				if (!disc[i][j][k] && !tarjan({i, j, k}))
					return false;
	
	return true;	
}

int solve() {
	pot[0] = 1;
	for (int i = 1; i < MAXL; i++)
		pot[i] = mul(pot[i - 1], BASE);
			
	for (int i = 0; i < N; i++) {
		len[i] = strlen(s[i] + 1);
		for (int j = 1; j <= len[i]; j++)
			pref[i][j] = add(mul(pref[i][j - 1], BASE), s[i][j]);
	}
	
	int sol = 0;
	for (int i = 0; i < N; i++) {
		int lo = i, hi = N;
		while (lo < hi) {
			int mid = (lo + hi) / 2;
			if (check(i, mid))
				lo = mid + 1;
			else
				hi = mid;
		}
		sol += lo - i;
	}
	
	return sol;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}