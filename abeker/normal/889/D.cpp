#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <ll, ll> pii;

const int MAXN = 2005;

int N;
int x[MAXN], y[MAXN];
map <pii, int> cnt;
vector <pii> a, b;

struct cmp {
	bool operator()(const pii &lhs, const pii &rhs) const {
		return lhs.first * rhs.second < rhs.first * lhs.second;
	}
};

set <pii, cmp> good;

void load() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d%d", x + i, y + i);
}

vector <ll> get(vector <pii> v, ll rx, ll ry) {
	vector <ll> res;
	for (auto it : v)
		res.push_back(it.first * rx + it.second * ry);
	sort(res.begin(), res.end());
	return res;
}

void check(ll rx, ll ry) {
	if (get(a, rx, ry) == get(b, rx, ry)) {
		if (rx < 0) {
			rx = -rx;
			ry = -ry;
		}
		good.insert({rx, ry});
	}
}

int solve() {
	int sx = 0, sy = 0;
	for (int i = 0; i < N; i++) {
		sx += x[i];
		sy += y[i];
		x[i] *= N;
		y[i] *= N;
	}
	
	for (int i = 0; i < N; i++) {
		cnt[{x[i], y[i]}]++;
		cnt[{2ll * sx - x[i], 2ll * sy - y[i]}]--;
	}
	
	for (auto it : cnt)
		for (int i = 0; i < abs(it.second); i++)
			if (it.second > 0)
				a.push_back(it.first);
			else
				b.push_back(it.first);
	
	assert(a.size() == b.size());
	
	if (a.empty())
		return -1;
		
	for (auto it : b)
		check(it.second - a[0].second, a[0].first - it.first);
	
	return good.size();
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}