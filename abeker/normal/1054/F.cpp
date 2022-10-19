#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e3 + 5;
const int INF = 0x3f3f3f3f;

struct triple {
	int a, b, c;
	bool operator <(const triple &rhs) const {
		if (a != rhs.a)
			return a < rhs.a;
		if (b != rhs.b)
			return b < rhs.b;
		return c < rhs.c;
	}
};

int N;
unordered_map <int, vector <int> > hor, ver;
vector <triple> H, V;
map <triple, int> idHor, idVer;
int match[MAXN], dist[MAXN];
vector <int> adj[MAXN];
vector <triple> ansHor, ansVer;
bool coverHor[MAXN], coverVer[MAXN];
bool bio[MAXN];

void load() {
	scanf("%d", &N);
	while (N--) {
		int x, y;
		scanf("%d%d", &x, &y);
		ver[x].push_back(y);
		hor[y].push_back(x);
	}
}

bool bfs() {
	queue <int> Q;
	for (int i = 1; i <= H.size(); i++) 
		if (!match[i]) {
			dist[i] = 0;
			Q.push(i);
		}
		else 
			dist[i] = INF;
  
	dist[0] = INF;
	while (!Q.empty()) {
		int x = Q.front(); 
		Q.pop();
		if (!x)
			continue;
		for (auto it : adj[x]) 
			if (dist[match[it]] == INF) {
				dist[match[it]] = dist[x] + 1;
				Q.push(match[it]);
			}
	}
  
	return dist[0] != INF;
}

bool dfs(int x) {
	if (!x)
		return true;
	for (auto it : adj[x]) 
		if (dist[match[it]] == dist[x] + 1 && dfs(match[it])) {
			match[it] = x;
			match[x] = it;
			return true;
		}
	dist[x] = INF;
	return false;
}

int hopcroft_karp() {
	int matching = 0;
	while (bfs())
		for (int i = 1; i <= H.size(); i++)
			matching += !match[i] && dfs(i);
	return matching;
}

void work(int lvl, vector <int> c, vector <triple> &where, map <triple, int> &id) {
	sort(c.begin(), c.end());	
	for (int i = 1; i < c.size(); i++) {
		id[{lvl, c[i - 1], c[i]}] = where.size();
		where.push_back({lvl, c[i - 1], c[i]});
	}
}

bool range(int x, int y, int z) {
	return x > y && x < z;
}

bool intersect(triple h, triple v) {
	return range(h.a, v.b, v.c) && range(v.a, h.b, h.c);
}

void go(int x) {
	bio[x] = true;
	coverHor[x - 1] = false;
	for (auto it : adj[x])
		if (it != match[x]) {
			coverVer[it - (int)H.size() - 1] = true;
			assert(match[it]);
			if (!bio[match[it]])
				go(match[it]);	
		}
}

void construct(int lvl, vector <int> c, vector <triple> &ans, bool *cover, map <triple, int> &id) {
	sort(c.begin(), c.end());
	int lst = c[0];
	for (int i = 1; i < c.size(); i++) 
		if (cover[id[{lvl, c[i - 1], c[i]}]]) {
			ans.push_back({lvl, lst, c[i - 1]});
			lst = c[i];
		}
	ans.push_back({lvl, lst, c.back()});
}

void solve() {
	for (auto it : hor)
		work(it.first, it.second, H, idHor);
	
	for (auto it : ver)
		work(it.first, it.second, V, idVer);
	
	for (int i = 0; i < H.size(); i++)
		for (int j = 0; j < V.size(); j++)
			if (intersect(H[i], V[j]))
				adj[i + 1].push_back(H.size() + j + 1);
	
	hopcroft_karp();
	
	memset(coverHor, true, sizeof coverHor); 
	for (int i = 1; i <= H.size(); i++)
		if (!match[i] && !bio[i])
			go(i);
	
	for (auto it : hor)
		construct(it.first, it.second, ansHor, coverHor, idHor);
	
	for (auto it : ver)
		construct(it.first, it.second, ansVer, coverVer, idVer); 
	
	printf("%d\n", ansHor.size());
	for (auto it : ansHor)
		printf("%d %d %d %d\n", it.b, it.a, it.c, it.a);
	
	printf("%d\n", ansVer.size());
	for (auto it : ansVer)
		printf("%d %d %d %d\n", it.a, it.b, it.a, it.c);
}

int main() {
	load();
	solve();
	return 0;
}