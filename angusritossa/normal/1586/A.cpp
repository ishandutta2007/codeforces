#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
int isComposite(int a) {
	for (int i = 2; i*i <= a; i++) {
		if (a%i == 0) return true;
	}
	return false;
}
int n, a[210];
bool isGood(vector<int> v) {
	int sum = 0;
	for (auto b : v) {
		sum += a[b];
	}
	if (isComposite(sum)) {
		printf("%lu\n", v.size());
		for (auto a : v) printf("%d ", a+1);
		printf("\n");
		return true;
	}
	return false;
}
int main() {
	int t;
	scanf("%d", &t);
	for (int CASE = 0; CASE < t; CASE++) {
		scanf("%d", &n);
		vector<int> subset;
		for (int i = 0; i < n; i++) scanf("%d", &a[i]), subset.push_back(i);
		if (isGood(subset)) {
			continue;
		}
		// remove 1 element
		bool done = false;
		for (int i = 0; i < n && !done; i++) {
			vector<int> v2;
			for (int j = 0; j < n; j++) {
				if (i != j) v2.push_back(j);
			}
			if (isGood(v2)) {
				done = true;
			}
		}

		for (int i = 0; i < n && !done; i++) {
			for (int j = 0; j < n && !done; j++) {
				vector<int> v2;
				for (int k = 0; k < n; k++) {
					if (k != i && k != j) v2.push_back(k);
				}
				if (isGood(v2)) {
					done = true;
				}
			}
		}
	}
}