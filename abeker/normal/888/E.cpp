#include <bits/stdc++.h>
using namespace std;

const int MAXN = 40;

int N, M;
int a[MAXN];

void gen(int l, int r, vector <int> &dest) {
	int len = r - l;
	for (int i = 0; i < 1 << len; i++) {
		int sum = 0;
		for (int j = 0; j < len; j++)
			if (i >> j & 1)
				sum = (sum + a[l + j]) % M;
		dest.push_back(sum);
	}
	sort(dest.begin(), dest.end());
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%d", a + i);
		
	vector <int> left, right;
	gen(0, N / 2, left);
	gen(N / 2, N, right);	
	
	int sol = 0;
	for (auto it : left) {
		auto it1 = lower_bound(right.begin(), right.end(), M - it);
		if (it1 != right.begin())
			sol = max(sol, it + *(--it1));
	}
	
	printf("%d\n", sol);
		
	return 0;
}