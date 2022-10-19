#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int MAXN = 5e5 + 5;
const int offset = 1 << 19;

int N, M, Q;
int cnt[MAXN];
vector <int> gps[MAXN];
vector <pii> queries[MAXN];
vector <int> vals, cum;
vector <ll> pref;
int t[2 * offset];
int ans[MAXN];

void load() {
	scanf("%d%d%d", &N, &M, &Q);
	for (int i = 0; i < N; i++) {
		int x;
		scanf("%d", &x);
		cnt[x]++;
	}
}

void update(int x) {
	x += offset;
	t[x]++;
	for (x /= 2; x; x /= 2)
		t[x] = t[2 * x] + t[2 * x + 1];
}

int get(int x, int lo, int hi, int k) {
	if (hi - lo == 1)
		return lo;
	int mid = (lo + hi) / 2;
	if (t[2 * x] >= k)
		return get(2 * x, lo, mid, k);
	return get(2 * x + 1, mid, hi, k - t[2 * x]);
}

void process(int x) {
	for (auto it : gps[vals[x - 1]])
		update(it);
	for (auto it : queries[x])
		ans[it.first] = get(1, 0, offset, it.second + 1);
}

void solve() {
	for (int i = 1; i <= M; i++)
		gps[cnt[i]].push_back(i);

	for (int i = 0; i <= N; i++)
		if (!gps[i].empty())
			vals.push_back(i);
	
	int sofar = 0;
	ll sum = 0;
	for (auto it : vals) {
		cum.push_back(sofar);
		pref.push_back((ll)sofar * it - sum);
		sofar += gps[it].size();
		sum += (ll)gps[it].size() * it;
	}
	assert(sofar == M);
	cum.push_back(sofar);
	
	for (int i = 0; i < Q; i++) {
		ll k;
		scanf("%lld", &k);
		k -= N;
		int pos = lower_bound(pref.begin(), pref.end(), k) - pref.begin();
		queries[pos].push_back({i, (k - pref[pos - 1] - 1) % cum[pos]});
	}
	
	for (int i = 1; i < cum.size(); i++) 
		process(i);
	
	for (int i = 0; i < Q; i++)
		printf("%d\n", ans[i]);
}

int main() {
	load();
	solve();
	return 0;
}