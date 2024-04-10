#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

int n, h;
vector<int> a;

#define ll long long

boolean check(vector<int> V) {
	sort(V.begin(), V.end(), greater<int>());
	ll len = 0;
	for (int i = 0; i < (signed) V.size(); i += 2) {
		len += V[i];
	}
	return len <= h;
}

int main() {
	scanf("%d%d", &n, &h);
	a.resize(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", a.data() + i);
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		vector<int> V;
		for (int j = 0; j <= i; j++) {
			V.push_back(a[j]);
		}
		if (check(V)) {
			ans = i + 1;
		}
	}
	printf("%d\n", ans);
	return 0;
}