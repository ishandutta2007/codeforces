#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int> > edge[33];
int main() {
	int l, r;
	cin >> l >> r;
	int n = 23;
	for (int i = 22; i >= 2; i--) {
		for (int j = i + 1; j < n; j++)
			edge[i].push_back(make_pair(j, 1<<(n-1-j)));
		edge[i].push_back(make_pair(n, 1));
	}
	if (l == 1) edge[1].push_back(make_pair(n, 1)), ++l;
	r = r - l + 1;
	int p = n - 1, val = 0;
	while (r) {
		if (r & 1) {
			edge[1].push_back(make_pair(p, l-1+val));
			val += 1 << (n-1-p);
		}
		r >>= 1, --p;
	}
	int m = 0;
	for (int i = 1; i <= n; i++) m += edge[i].size();
	puts("YES");
	cout << n << ' ' << m << endl;
	for (int i = 1; i <= n; i++)
		for (auto j : edge[i])
			cout << i << ' ' << j.first << ' ' << j.second << endl;
}