#include <bits/stdc++.h>

using namespace std;

const int MX = 200000;

int b[MX], aa[MX];

int main() {
	int T;
	ignore = scanf("%d", &T);
	while (T--) {
		int n;
		ignore = scanf("%d", &n);
		
		fill(b, b + n, -1);
		
		set<int> used;
		for (int i = 0, a; i < n; i++) {
			ignore = scanf("%d", &a);
			
			if (used.count(a) == 0) {
				used.insert(a);
				b[i] = a - 1;
			}
			
			aa[i] = a - 1;
		}
		
		vector<pair<int, int>> segments;
		for (int i = 0; i < n; i++) {
			if (used.count(i + 1) == 1) continue;
			
			int j = i;
			while (b[j] != -1) j = b[j];
			
			segments.emplace_back(i, j);
		}
		
		int k = used.size();
		
		if (segments.size() == 1 && segments[0].first == segments[0].second) {
			int x = segments[0].first;
			
			int i = 0;
			while (b[i] != aa[x]) i++;
			
			b[x] = aa[x];
			b[i] = x;
		}
		else {
			for (size_t i = 0; i < segments.size(); i++) {
				b[segments[i].second] = segments[(i + 1) % segments.size()].first;
			}
		}
		
		printf("%d\n", k);
		
		for (int i = 0; i < n; i++) printf("%d ", b[i] + 1);
		printf("\n");
	}
	
	return 0;
}