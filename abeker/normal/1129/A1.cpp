#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e3 + 5;

int N, M;
vector <int> v[MAXN];

int solve(int pos) {
	int res = 0;
	for (int i = 0; i < N; i++) {
		int curr = pos + i;
		if (curr >= N)
			curr -= N;
		int before = 0, after = 0;
		int mn1 = N, mn2 = N;
		if (v[curr].empty())
			continue;
		for (auto it : v[curr]) {
			int tmp = it - pos;
			if (tmp < 0)
				tmp += N;
			if (tmp < i) {
				before++;
				mn1 = min(mn1, tmp);
			}
			else {
				after++;
				mn2 = min(mn2, tmp);
			}
		}
		res = max(res, after ? (before + after - 1) * N + mn2 : (before + after) * N + mn1);
	}
	
	return res;
}

int main() {
	scanf("%d%d", &N, &M);	
	while (M--) {
		int a, b;
		scanf("%d%d", &a, &b);
		v[--a].push_back(--b);
	}
	
	for (int i = 0; i < N; i++)
		printf("%d ", solve(i));
	puts("");
	
	return 0;
}