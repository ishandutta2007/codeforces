#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 105;

int N;
int a[MAXN], d[MAXN];
vector <pii> up, down, curr;
vector <int> perm;

void load() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d%d", a + i, d + i);
}

bool cmp(const pii &lhs, const pii &rhs) {
	if (lhs.first != rhs.first)
		return lhs.first > rhs.first;
	return lhs.second < rhs.second;
}

int get(int x) {
	for (int i = 0; i < N; i++)
		if (curr[i].second == x)
			return i;
	return -1;
}

int solve() {
	for (int i = 0; i < N; i++)
		if (d[i] < 0) 
			down.push_back({a[i], i});
		else 
			up.push_back({a[i], i});
	
	sort(up.begin(), up.end(), cmp);
	reverse(up.begin(), up.end());
	sort(down.begin(), down.end(), cmp);
	
	for (auto it : up)
		curr.push_back(it);
	for (auto it : down)
		curr.push_back(it);
	for (auto it : curr)
		perm.push_back(it.second);
	
	sort(curr.begin(), curr.end(), cmp);
	int sol = 0;
	for (auto it : perm) {
		int idx = get(it);
		curr[idx].first += d[it];
		sort(curr.begin(), curr.end(), cmp);
		sol += abs(get(it) - idx);
	}
		
	return sol;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}