#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 4e5 + 5;
const int offset = 1 << 19;
const int MOD = 1e9 + 7;
const int INF = 1e9;

int N;
bool cmd[MAXN];
int price[MAXN];
vector <int> comp;
pii t[2 * offset];
int st[MAXN], en[MAXN];
int ans[MAXN];

void load() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		char buff[10];
		scanf("%s%d", buff, price + i);
		cmd[i] = buff[1] == 'D';
	}
}

pii merge(pii l, pii r) {
	return {max(l.first, r.first), min(l.second, r.second)};
}

void update(int x, int val) {
	x += offset;
	t[x] = {val, val};
	for (x /= 2; x; x /= 2)
		t[x] = merge(t[2 * x], t[2 * x + 1]);
}

pii query(int x, int lo, int hi, int from, int to) {
	if (lo >= to || hi <= from)
		return {-1, INF};
	if (lo >= from && hi <= to)
		return t[x];
	int mid = (lo + hi) / 2;
	return merge(query(2 * x, lo, mid, from, to), query(2 * x + 1, mid, hi, from, to));
}

int solve() {
	for (int i = 0; i < N; i++)
		if (cmd[i])
			comp.push_back(price[i]);
		
	sort(comp.begin(), comp.end());
		
	for (int i = 0; i < N; i++)
		price[i] = lower_bound(comp.begin(), comp.end(), price[i]) - comp.begin();
	
	for (int i = 0; i < 2 * offset; i++)
		t[i] = {-1, INF};
		
	for (int i = 0; i < N; i++)
		if (!cmd[i])
			update(i, price[i]);
	
	memset(ans, -1, sizeof ans);
	for (int i = 0; i < N; i++)
		en[i] = N;
		
	for (int i = 0; i < N; i++)
		if (cmd[i])
			st[price[i]] = i;
		else 
			en[price[i]] = i; 
	
	int sz = comp.size();
	for (int i = 0; i < sz; i++) {
		pii tmp = query(1, 0, offset, st[i], en[i]);
		if (tmp.first > i) {
			if (tmp.second < i)
				return 0;
			ans[i] = 0;
		}
		if (tmp.second < i)
			ans[i] = 1;
	}
	
	vector <int> rest;
	int cnt = 0;
	for (int i = 0; i < sz; i++)
		if (en[i] == N)
			rest.push_back(i);
		else
			cnt += ans[i] == -1;
			
	int mx = -1, mn = rest.size();
	for (int i = 0; i < rest.size(); i++)
		if (ans[rest[i]] == 0)
			mx = max(mx, i);
		else if (ans[rest[i]] == 1)
			mn = min(mn, i);
	
	if (mx > mn)
		return 0;
	
	int sol = mn - mx;
	while (cnt--) {
		sol += sol;
		if (sol >= MOD)
			sol -= MOD;
	}
	
	return sol;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}