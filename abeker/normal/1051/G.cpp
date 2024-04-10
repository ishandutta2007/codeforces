#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 5;
 
template <typename T>
struct fenwick {
	unordered_map <int, T> f;
	
	void update(int x, T val) {
		for (; x < MAXN; x += x & -x)
			f[x] += val;
	}
	
	T get(int x) {
		T res = 0;
		for (; x; x -= x & -x)
			if (f.find(x) != f.end())
				res += f[x];
		return res;
	}
};

int N;
int dad[2 * MAXN];
int lft[2 * MAXN], rig[2 * MAXN]; 
fenwick <int> cnt[2 * MAXN];
fenwick <ll> sum[2 * MAXN];
vector <int> vals[2 * MAXN];
ll tot[2 * MAXN];
bool bio[2 * MAXN];
ll ans;

void init() {
	for (int i = 0; i < 2 * MAXN; i++) 
		dad[i] = lft[i] = rig[i] = i;
}

int find(int x) {
	return dad[x] == x ? x : dad[x] = find(dad[x]);
}

void join(int x, int y) {
	x = find(x);
	y = find(y);
	if (rig[x] - lft[x] > rig[y] - lft[y])
		swap(x, y);
		
	ans -= tot[x] + tot[y];
	tot[y] -= (ll)lft[y] * sum[y].get(MAXN - 1);
		
	dad[x] = y;
	lft[y] = min(lft[y], lft[x]);
	rig[y] = max(rig[y], rig[x]);
	
	for (auto it : vals[x]) {
		tot[y] += sum[y].get(it - 1);
		vals[y].push_back(it);
	}
	
	for (auto it : vals[x]) {
		cnt[y].update(MAXN - it, 1);
		sum[y].update(it, it);
	}
	
	ll old = tot[y];
	for (auto it : vals[x])
		tot[y] += (ll)it * cnt[y].get(MAXN - it - 1);
		
	tot[y] += (ll)lft[y] * sum[y].get(MAXN - 1);
	ans += tot[y];
}

void modify(int a, int b) {
	ans -= (ll)a * b;
	if (bio[a])
		a = rig[find(a)] + 1;
	bio[a] = true;
	cnt[a].update(MAXN - b, 1);
	sum[a].update(b, b);
	tot[a] = (ll)a * b;
	ans += tot[a];
	vals[a].push_back(b);
	if (bio[a - 1])
		join(a - 1, a);
	if (bio[a + 1])
		join(a + 1, a);
}

int main() {
	init();
	
	scanf("%d", &N);
	while (N--) {
		int a, b;
		scanf("%d%d", &a, &b);
		modify(a, b);
		printf("%lld\n", ans);
	}
	
	return 0;
}