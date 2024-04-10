#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

struct triple {
	int x, y, z;
};

struct box {
	int id, diff;
	unordered_set <int> pres;
	void input(int x) {
		int s;
		scanf("%d", &s);
		while (s--) {
			int curr;
			scanf("%d", &curr);
			pres.insert(curr);
		}
		id = x;
	}
	bool operator <(const box &rhs) const {
		return pres.size() > rhs.pres.size();
	}
};

int N, M;
box b[MAXN];
unordered_set <int> all, where[MAXN];
vector <triple> ans;
int tot;

void load() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		b[i].input(i + 1);
		tot += b[i].pres.size();
	}
}

bool cmp(const box &lhs, const box &rhs) {
	return lhs.diff < rhs.diff;
}

void solve() {
	sort(b, b + N);
	
	for (int i = 0; i < N; i++)
		b[i].diff = (int)b[i].pres.size() - (tot / N + (i < tot % N));
	
	sort(b, b + N, cmp);
	
	for (int i = 0; i < N; i++)
		if (b[i].diff > 0) 
			for (auto it : b[i].pres) {
				all.insert(it);
				where[it].insert(i);
			}
	
	for (int i = 0; i < N && b[i].diff < 0; i++) {
		vector <int> todo;
		for (auto it : b[i].pres) {
			all.erase(it);
			todo.push_back(it);
		}
		
		for (int j = 0; j < -b[i].diff; j++) {
			int kind = *all.begin();
			int from = *where[kind].begin();
			ans.push_back({b[from].id, b[i].id, kind});
			where[kind].erase(from);
			b[from].pres.erase(kind);
			b[from].diff--;
			all.erase(kind);
			todo.push_back(kind);
			if (!b[from].diff)
				for (auto it : b[from].pres) {
					where[it].erase(from);
					if (where[it].empty())
						all.erase(it);
				}
		}
		
		for (auto it : todo) 
			if (!where[it].empty())
				all.insert(it);
	}
	
	printf("%d\n", ans.size());
	for (auto it : ans)
		printf("%d %d %d\n", it.x, it.y, it.z);
}

int main() {
	load();
	solve();
	return 0;
}