#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

typedef long long ll;
typedef pair <ll, ll> pii;
typedef pair <pii, int> event;

const int MAXN = 100005;
const int INF = 0x3f3f3f3f;

int N, M, K;
int x[MAXN], y[MAXN];
vector <ll> imp;
vector <event> diff[4 * MAXN], sum[4 * MAXN];
vector <int> points_d[4 * MAXN], points_s[4 * MAXN];
int sol[MAXN];

void load() {
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 0; i < K; i++)
		scanf("%d%d", x + i, y + i);
}

pii sub(pii l, pii r) {
	return pii(l.first - r.first, l.second - r.second);
}

pii mul(pii p, ll c) {
	if (c < 0) swap(p.first, p.second);
	p.first *= c;
	p.second *= c;
	return p;
}

pii add(pii p, ll c) {
	p.first += c;
	p.second += c;
	return p;
}

void add_diff(ll d, pii range, int t) {
	diff[d + 2 * MAXN].push_back(event(range, t));
}

void add_sum(ll s, pii range, int t) {
	sum[s + 2 * MAXN].push_back(event(range, t)); 
}

void solve_diff(int d) {
	multiset <int> curr;
	vector <event> sweep;
	for (auto it : diff[d]) {
		sweep.push_back(event(pii(it.first.first, -2), it.second));
		sweep.push_back(event(pii(it.first.second, -1), it.second));
	}
	
	for (auto it : points_d[d])
		sweep.push_back(event(pii(x[it], it), 0));
	
	sort(sweep.begin(), sweep.end());
	curr.insert(INF);
	for (auto it : sweep) {
		int t = it.first.second;
		if (t == -2) 
			curr.insert(it.second);
		else if (t == -1)
			curr.erase(curr.find(it.second));
		else 
			sol[t] = min(sol[t], *curr.begin());
	}
}

void solve_sum(int s) {
	multiset <int> curr;
	vector <event> sweep;
	for (auto it : sum[s]) {
		sweep.push_back(event(pii(it.first.first, -2), it.second));
		sweep.push_back(event(pii(it.first.second, -1), it.second));
	}
	
	for (auto it : points_s[s])
		sweep.push_back(event(pii(x[it], it), 0));
	
	sort(sweep.begin(), sweep.end());
	curr.insert(INF);
	for (auto it : sweep) {
		int t = it.first.second;
		if (t == -2) 
			curr.insert(it.second);
		else if (t == -1)
			curr.erase(curr.find(it.second));
		else 
			sol[t] = min(sol[t], *curr.begin());
	}
}

void solve() {
	int g = __gcd(N, M);
	for (int i = 1; i <= N / g; i++)
		imp.push_back((ll)i * M);
	for (int i = 0; i < M / g; i++)
		imp.push_back((ll)i * N);
	
	sort(imp.begin(), imp.end());
	
	for (int i = 0; i < (int)imp.size() - 1; i++) {
		ll a = imp[i] - imp[i] % N;
		ll b = imp[i] - imp[i] % M;
		pii x1(1, -a);
		pii y1(1, -b);
		if (a / N % 2) x1 = sub(pii(0, N), x1);
		if (b / M % 2) y1 = sub(pii(0, M), y1);
		pii tmp = add(mul(pii(imp[i], imp[i + 1]), x1.first), x1.second);
		if (x1.first == y1.first) 
			add_diff(y1.second - x1.second, tmp, i);
		else 
			add_sum(y1.second + x1.second, tmp, i);
	}
	
	for (int i = 0; i < K; i++) {
		points_d[y[i] - x[i] + 2 * MAXN].push_back(i);
		points_s[x[i] + y[i] + 2 * MAXN].push_back(i);
		sol[i] = INF;
	}
	
	for (int i = 0; i < 4 * MAXN; i++) {
		solve_diff(i);
		solve_sum(i);
	}
	
	for (int i = 0; i < K; i++) {
		if (sol[i] == INF) {
			puts("-1");
			continue;
		}
		ll a = imp[sol[i]] - imp[sol[i]] % N;
		pii x1(1, -a);
		if (a / N % 2) x1 = sub(pii(0, N), x1);
		printf("%lld\n", (x[i] - x1.second) * x1.first);  
	}
}

int main() {
	load();
	solve();
	return 0;
}