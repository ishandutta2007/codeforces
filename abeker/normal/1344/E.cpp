#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int MAXN = 1e5 + 5;
const ll INF = 1e15;

int N, M;
vector <pii> ch[MAXN];
vector <int> times[MAXN];
vector <pair <ll, ll>> events;
vector <int> lazy;
vector <ll> maks;
vector <ll> all;
int offset;

void load() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i < N; i++) {
		int u, v, d;
		scanf("%d%d%d", &u, &v, &d);
		ch[u].push_back({v, d});
	}
	while (M--) {
		int s, t;
		scanf("%d%d", &s, &t);
		times[s].push_back(t);
	}
}

void add_interval(ll from, ll to) {
	events.push_back({to, ++from});
	all.push_back(from);
}

bool cmp(set <int>* s1, set <int>* s2) {
	return s1 -> size() < s2 -> size();
}

set <int>* dfs(int x, ll dep) {
	vector <set <int>*> v;
	for (auto it : ch[x]) 
		v.push_back(dfs(it.first, dep + it.second));
	if (!v.empty()) {
		pii lst = ch[x].back();
		int heavy = max_element(v.begin(), v.end(), cmp) - v.begin();
		swap(v[0], v[heavy]);
		swap(ch[x][0], ch[x][heavy]);
		unordered_map <int, int> which;
		for (int i = 1; i < v.size(); i++)
			for (auto elem : *v[i]) {
				v[0] -> insert(elem);
				which[elem] = i;
			}
		for (int i = 1; i < v.size(); i++) {
			for (auto elem : *v[i]) {
				auto it = v[0] -> find(elem);
				if (++it != v[0] -> end() && which[*it] != which[elem])
					add_interval(dep + elem, dep + *it);
				it--;
				if (it != v[0] -> begin() && !which[*(--it)])
					add_interval(dep + *it, dep + elem);
			}
			delete v[i];
		}
		if (!(v[0] -> empty())) {
			int earliest = *(v[0] -> begin());
			if (ch[x][which[earliest]] != lst)
				add_interval(0, dep + earliest);
		}
	}
	else
		v.push_back(new set <int> ());
	for (auto it : times[x])
		v[0] -> insert(it);
	return v[0];
}

void prop(int x) {
	maks[x] += lazy[x];
	if (x < offset) {
		lazy[2 * x] += lazy[x];
		lazy[2 * x + 1] += lazy[x];
	}
	lazy[x] = 0;
}

void update(int x, int lo, int hi, int from, int to) {
	prop(x);
	if (lo >= to || hi <= from)
		return;
	if (lo >= from && hi <= to) {
		maks[x]++;
		if (x < offset) {
			lazy[2 * x]++;
			lazy[2 * x + 1]++;
		}
		return;
	}
	int mid = (lo + hi) / 2;
	update(2 * x, lo, mid, from, to);
	update(2 * x + 1, mid, hi, from, to);
	maks[x] = max(maks[2 * x], maks[2 * x + 1]);
}

ll query(int x, int lo, int hi, int from, int to) {
	prop(x);
	if (lo >= to || hi <= from)
		return -INF;
	if (lo >= from && hi <= to)
		return maks[x];
	int mid = (lo + hi) / 2;
	return max(query(2 * x, lo, mid, from, to), query(2 * x + 1, mid, hi, from, to));
}

void solve() {
	dfs(1, 0);
	
	sort(all.begin(), all.end());
	sort(events.begin(), events.end());
	
	offset = 1;
	while (offset < all.size())
		offset *= 2;
	maks.resize(2 * offset);
	lazy.resize(2 * offset);
	
	for (auto &it : events) {
		int tmp = lower_bound(all.begin(), all.end(), it.second) - all.begin();
		maks[tmp + offset] = it.second;
		it.second = tmp;
	}
	
	for (int i = offset - 1; i >= 0; i--)
		maks[i] = max(maks[2 * i], maks[2 * i + 1]);
		
	ll expl = INF, sofar = 0;
	for (auto it : events) {
		sofar = max(sofar, it.second);
		update(1, 0, offset, 0, it.second + 1);
		if (query(1, 0, offset, 0, sofar + 1) > it.first + 1) {
			expl = it.first;
			break;
		}
	}
	
	int changes = 0;
	for (auto it : events)
		changes += it.first < expl;
	
	printf("%lld %d\n", expl == INF ? -1 : expl, changes);
}

int main() {
	load();
	solve();
	return 0;
}