#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int MAXN = 3e5 + 5;
const int offset = 1 << 19;

int Q;
map <pii, int> lst;
vector <pii> todo[2 * offset];
int dad[2 * MAXN], lft[2 * MAXN], rig[2 * MAXN];
vector <pair <int*, int>> ch;
vector <pair <ll*, ll>> ss;
ll ans[offset];
ll sum;

void update(int x, int lo, int hi, int from, int to, pii edge) {
	if (lo >= to || hi <= from)
		return;
	if (lo >= from && hi <= to) {
		todo[x].push_back(edge);
		return;
	}
	int mid = (lo + hi) / 2;
	update(2 * x, lo, mid, from, to, edge);
	update(2 * x + 1, mid, hi, from, to, edge);
}

void update(int from, int to, pii edge) {
	update(1, 0, offset, from, to, edge);
}

void load() {
	scanf("%d", &Q);
	for (int i = 0; i < Q; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		y += MAXN;
		int &ref = lst[{x, y}];
		if (ref) {
			update(ref - 1, i, {x, y});
			ref = 0;
		}
		else
			ref = i + 1;
	}
	for (auto it : lst) 
		if (it.second) 
			update(it.second - 1, Q, it.first); 
}

template <class T>
void modify(vector <pair <T*, T>> &v, T *ptr, T val) {
	v.push_back({ptr, *ptr});
	*ptr = val;
}

void revert(int sz) {
	for (; ch.size() > sz; ch.pop_back()) 
		*ch.back().first = ch.back().second;
	for (sz /= 3; ss.size() > sz; ss.pop_back()) 
		*ss.back().first = ss.back().second; 
}

int find(int x) {
	return dad[x] == x ? x : find(dad[x]);
}

void join(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y)
		return;
	if (lft[x] + rig[x] > lft[y] + rig[y])
		swap(x, y);
	modify(ss, &sum, sum + (ll)lft[x] * rig[y] + (ll)rig[x] * lft[y]);
	modify(ch, dad + x, y);
	modify(ch, lft + y, lft[x] + lft[y]);
	modify(ch, rig + y, rig[x] + rig[y]);
}

void dfs(int x) {
	int len = ch.size();
	assert(len == 3 * ss.size());
	for (auto it : todo[x])
		join(it.first, it.second);
	if (x >= offset) 
		ans[x - offset] = sum;
	else {
		dfs(2 * x);
		dfs(2 * x + 1);
	}
	revert(len);
}

void solve() {
	for (int i = 1; i < 2 * MAXN; i++) {
		dad[i] = i;
		lft[i] = i < MAXN;
		rig[i] = i > MAXN;	
	}
	
	dfs(1);	
	
	for (int i = 0; i < Q; i++)
		printf("%lld ", ans[i]);
	puts("");
}

int main() {
	load();
	solve();
	return 0;
}