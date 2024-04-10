#include <bits/stdc++.h>

using namespace std;

const int N = 2010;

int n, x[N], y[N];
vector <pair <int, int> > v;

int main (int argc, char const *argv[]) {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d %d", x + i, y + i);

	for (int i = 1; i <= n; ++i) 
		for (int j = i + 1; j <= n; ++j)
			v.push_back(make_pair(x[i] + x[j], y[i] + y[j]));

	sort(v.begin(), v.end());
	int ans = 0, now = 1;

	for (int i = 1; i < v.size(); ++i) {
		if (v[i] == v[i - 1]) ++now;
		else ans += ((now * (now - 1)) >> 1), now = 1;
	}

	printf("%d\n", ans);
	return 0;
}