#include <bits/stdc++.h>

using namespace std;

const int MX = 100;

vector<int> ids[MX];
int a[MX], b[MX];

int main() {
	int n, k;
	ignore = scanf("%d %d", &n, &k);

	for (int i = 0, x; i < n * k; i++) {
		ignore = scanf("%d", &x);
		ids[x - 1].push_back(i);
	}
	
	fill(a, a + n, -1);
	
	for (int i = 0; i + 1 < k; i++) {
		vector<pair<int, int>> vec;
		for (int j = 0; j < n; j++) {
			if (a[j] != -1) continue;
			
			vec.emplace_back(ids[j][i + 1], j);
		}
		
		sort(vec.begin(), vec.end());
		
		for (size_t j = 0; j < vec.size() && j < (n + k - 2) / (k - 1); j++) {
			int x = vec[j].second;
			a[x] = ids[x][i];
			b[x] = ids[x][i + 1];
		}
	}
	
	for (int i = 0; i < n; i++) printf("%d %d\n", a[i] + 1, b[i] + 1);
	
	return 0;
}