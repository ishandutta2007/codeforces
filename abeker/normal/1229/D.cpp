#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int MAXN = 3e5 + 5;
const int MAXFACT = 125;
const int MAXSUB = 160;
const int BASE = 3137;

int N, K;
vector <int> trick[MAXN];
vector <vector <int>> perms;
map <vector <int>, int> idx;
unordered_map <int, int> which;
int trans[MAXSUB][MAXFACT];
queue <int> Q;

struct subgp {
	set <int> S;
	int order() const {
		return S.size();
	}
	bool has(int p) const {
		return S.count(p);
	}
	void add(int p) {
		S.insert(p);
	}
	int hsh() const {
		int res = 0;
		for (auto it : S)
			for (int i = 0; i < K; i++)
				res = BASE * res + perms[it][i] + 1;
		return res;
	}
};

subgp trivial;
vector <subgp> all;

int compose(int p, int q) {
	vector <int> res(K);
	for (int i = 0; i < K; i++)
		res[i] = perms[p][perms[q][i]];
	return idx[res];
}

void load() {
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; i++) {
		trick[i].resize(K);
		for (int j = 0; j < K; j++) {
			scanf("%d", &trick[i][j]);
			trick[i][j]--;
		}
	}
}

subgp gen(int x, int p) {
	unordered_set <int> genset = {p};
	for (auto it : all[x].S) 
		genset.insert(it);
	
	queue <int> todo;
	todo.push(0);
	subgp H;
	while (!todo.empty()) {
		int tmp = todo.front();
		todo.pop();
		if (H.has(tmp))
			continue;
		H.add(tmp);
		for (auto it : genset) 
			todo.push(compose(tmp, it));
	}
	
	return H;
}

void create(const subgp &G) {
	which[G.hsh()] = all.size();
	Q.push(all.size());
	all.push_back(G);
}

void init() {
	vector <int> id(K);
	for (int i = 0; i < K; i++)
		id[i] = i;
	
	vector <int> v = id;
	do {
		idx[v] = perms.size();
		perms.push_back(v);
	} while (next_permutation(v.begin(), v.end()));
	
	trivial = {{0}};
	create(trivial);
	while (!Q.empty()) {
		int x = Q.front();
		Q.pop();
		for (int i = 0; i < perms.size(); i++) {
			subgp nxt = gen(x, i);
			int curr = nxt.hsh();
			if (which.find(curr) == which.end()) 
				create(nxt);
			trans[x][i] = which[curr];
		}
	}
}

ll solve() {
	ll sol = 0;
	vector <pii> blocks;
	for (int i = 0; i < N; i++) {
		blocks.push_back({0, 1});
		int last = -1, cnt = 0;
		vector <pii> nxt;
		int curr = idx[trick[i]];
		for (auto &it : blocks) {
			it.first = trans[it.first][curr];
			if (it.first != last) {
				if (last != -1)
					nxt.push_back({last, cnt});
				last = it.first;
				cnt = 0;
			}
			cnt += it.second;
		}
		nxt.push_back({last, cnt});
		blocks = nxt;
		
		for (auto it : blocks)
			sol += (ll)it.second * all[it.first].order();
	}
	
	return sol;
}

int main() {
	load();
	init();
	printf("%lld\n", solve());
	return 0;
}