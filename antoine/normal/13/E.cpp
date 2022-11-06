#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, blockSz;
int dest[(int) 1e5 + 9];
pair<int, int> adj[(int) 1e5 + 9];

void update(const int i) {
	const int bound = min(n, (1 + i / blockSz) * blockSz);
	const int j = dest[i];
	if (j >= bound || adj[j].first >= n) {
		adj[i] = {j, 1};
	} else if(adj[j].first < n) {
		adj[i].first = adj[j].first;
		adj[i].second = 1 + adj[j].second;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int Q;
	cin >> n >> Q;
	for (int i = 0; i < n; ++i) {
		cin >> dest[i];
		dest[i] += i;
	}

	blockSz = (int) sqrt(n + 1);

	for (int i = n - 1; i >= 0; --i)
		update(i);

	while (Q--) {
		int type, a;
		cin >> type >> a;
		--a;
		if (type == 0) {
			cin >> dest[a];
			dest[a] += a;
			const int start = (a / blockSz) * blockSz;
			for (; a >= start; --a)
				update(a);
		} else {
			assert(type == 1);
			int curr = a, last = -2, cnt = 0;
			while (curr < n) {
				last = curr;
				cnt += adj[curr].second;
				curr = adj[curr].first;
			}
			cout << last + 1 << ' ' << cnt << '\n';
		}
	}
	return 0;
}