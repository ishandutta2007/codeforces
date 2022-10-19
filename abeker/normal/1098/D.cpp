#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <ll, int> pii;

const int MAXN = 5e5 + 5;

int N, Q;
char op[MAXN];
int x[MAXN];
map <int, vector <int> > st;
vector <pii> all;
int id[MAXN], pos[MAXN];
multiset <pii> act;
ll fen[MAXN];

void load() {
	scanf("%d", &Q);
	for (int i = 0; i < Q; i++)
		scanf(" %c%d", op + i, x + i);
}

void update(int x, int val) {
	for (x++; x < MAXN; x += x & -x)
		fen[x] += val;
}

ll get(int x) {
	ll res = 0;
	for (x++; x; x -= x & -x)
		res += fen[x];
	return res;
}

int query() {
	if (act.empty())
		return 0;
	
	int res = (int)act.size() - 1;
	auto it = act.begin();
	while (1) {
		it = act.lower_bound({2 * get(it -> second) + 1, 0});
		if (it == act.end())
			break;
		auto prv = it;
		assert(prv != act.begin());
		res -= 2 * get((--prv) -> second) < it -> first;
	}
	
	return res;
}

void solve() {
	int curr = 0;
	for (int i = 0; i < Q; i++)
		if (op[i] == '+') {
			id[i] = curr;
			all.push_back({x[i], curr});
			st[x[i]].push_back(curr++);
		}
		else {
			id[i] = st[x[i]].back();
			st[x[i]].pop_back();
		}
	
	sort(all.begin(), all.end());
	
	N = all.size();
	for (int i = 0; i < N; i++)
		pos[all[i].second] = i;
	
	for (int i = 0; i < Q; i++) {
		int where = pos[id[i]];
		if (op[i] == '+') {
			act.insert({x[i], where});
			update(where, x[i]);
		}
		else {
			act.erase(act.find({x[i], where}));
			update(where, -x[i]);
		}
		printf("%d\n", query()); 
	}
}

int main() {
	load();
	solve();
	return 0;
}