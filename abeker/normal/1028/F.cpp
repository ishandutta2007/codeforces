#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int MAXN = 2e5 + 5;

int Q;
int t[MAXN], x[MAXN], y[MAXN];
ll dist[MAXN];
vector <ll> comp;
set <pii> pts[MAXN];
unordered_map <ll, int> cnt;
int curr;

void load() {
	scanf("%d", &Q);
	for (int i = 0; i < Q; i++)
		scanf("%d%d%d", t + i, x + i, y + i);
}

inline ll sqr(int val) {
	return (ll)val * val;
}

inline ll get(int x, int y) {
	return ((ll)MAXN * x + y) / __gcd(x, y);
}

void add(pii p, pii q, int v) {
	int dx = abs(p.first - q.first);
	int dy = abs(p.second - q.second);
	if (!dx && !dy) {
		dx = p.second;
		dy = p.first;
	}
	else
		v *= 2;
	cnt[get(dx, dy)] += v;
}

void in(int x, int y, int d) {
	pts[d].insert({x, y});
	for (auto it : pts[d])
		add({x, y}, it, 1);
	curr++;
}

void out(int x, int y, int d) {
	for (auto it : pts[d])
		add({x, y}, it, -1);
	pts[d].erase({x, y});
	curr--;
}

int query(int x, int y) {
	return curr - cnt[get(y, x)];
}

void solve() {
	for (int i = 0; i < Q; i++) {
		dist[i] = sqr(x[i]) + sqr(y[i]);
		comp.push_back(dist[i]);
	}
	
	sort(comp.begin(), comp.end());
	
	for (int i = 0; i < Q; i++) 
		dist[i] = lower_bound(comp.begin(), comp.end(), dist[i]) - comp.begin();
		
	for (int i = 0; i < Q; i++)
		if (t[i] == 1)
			in(x[i], y[i], dist[i]);
		else if (t[i] == 2)
			out(x[i], y[i], dist[i]);
		else
			printf("%d\n", query(x[i], y[i]));
}

int main() {
	load();
	solve();
	return 0;
}