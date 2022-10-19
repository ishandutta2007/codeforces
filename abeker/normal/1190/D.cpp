#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 5;

int N;
int x[MAXN], y[MAXN];
vector <int> hor[MAXN];
int ver[MAXN];
int f[MAXN];

void load() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d%d", x + i, y + i);
}

void compress(int *arr) {
	vector <int> vals;
	for (int i = 0; i < N; i++)
		vals.push_back(arr[i]);
	
	sort(vals.begin(), vals.end());
	
	for (int i = 0; i < N; i++)
		arr[i] = lower_bound(vals.begin(), vals.end(), arr[i]) - vals.begin();
}

void update(int x, int val) {
	for (x++; x < MAXN; x += x & -x)
		f[x] += val;
}

int get(int x) {
	int res = 0;
	for (x++; x; x -= x & -x)
		res += f[x];
	return res;
}

ll comb(int x) {
	return (ll)x * (x + 1) / 2;
}

ll query(int lo, int hi) {
	return comb(get(hi - 1) - get(lo - 1));
}

ll calc(int lvl) {
	if (hor[lvl].empty())
		return 0;
		
	sort(hor[lvl].begin(), hor[lvl].end());
	
	ll res = query(0, MAXN) - query(0, hor[lvl][0]) - query(hor[lvl].back() + 1, MAXN);
	for (int i = 1; i < hor[lvl].size(); i++)
		res -= query(hor[lvl][i - 1] + 1, hor[lvl][i]);
	
	for (auto it : hor[lvl]) {
		ver[it]--;
		if (!ver[it])
			update(it, -1);
	}
	
	return res;
}

ll solve() {
	compress(x);
	compress(y);
	
	for (int i = 0; i < N; i++) {
		hor[y[i]].push_back(x[i]);
		ver[x[i]]++;
	}
	
	for (int i = 0; i < MAXN; i++)
		if (ver[i])
			update(i, 1);
	
	ll sol = 0;
	for (int i = 0; i < MAXN; i++)
		sol += calc(i);
	
	return sol;
}

int main() {
	load();
	printf("%lld\n", solve());
	return 0;
}