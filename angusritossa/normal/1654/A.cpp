#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
int n, t;
int main() {
	scanf("%d", &t);
	for (int j = 0; j < t; j++) {
		scanf("%d", &n);
		vector<int> v;
		for (int i = 0; i < n; i++) {
			int a;
			scanf("%d", &a);
			v.push_back(a);
		}
		sort(v.begin(), v.end());
		reverse(v.begin(), v.end());
		printf("%d\n", v[0]+v[1]);
	}
}