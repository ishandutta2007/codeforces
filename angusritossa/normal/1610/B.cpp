#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
typedef long long ll;
#define MAXN 200010
int a[MAXN];
bool solveRemoving(int val, int n) {
	vector<int> v;
	for (int i = 0; i < n; i++) {
		if (a[i] != val) v.push_back(a[i]);
	}
	int sz = v.size();
	for (int i = 0; i < sz; i++) {
		if (v[i] != v[sz-i-1]) {
			return false;
		}
	}
	return true;
}	
int main() {
	int t;
	scanf("%d", &t);
	for (int CASE = 0; CASE < t; CASE++) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);
		if (solveRemoving(-1, n)) {
			printf("YES\n");
			continue;
		}
		for (int i = 0; i < n; i++) {
			if (a[i] != a[n-i-1]) {
				if (solveRemoving(a[i], n)) {
					printf("YES\n");
				} else if (solveRemoving(a[n-i-1], n)) {
					printf("YES\n");
				} else {
					printf("NO\n");
				}
				break;
			}
		}
	}
}