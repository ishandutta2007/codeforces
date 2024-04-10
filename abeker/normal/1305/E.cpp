#include <bits/stdc++.h>
using namespace std;

int f(int n) {
	return (n - 1) * (n - 1) / 4;
}

void check(vector <int> v, int n, int m) {
	assert(v.size() == n);
	for (int i = 1; i < n; i++)
		assert(v[i - 1] < v[i] && v[i - 1] > 0 && v[i] <= 1e9);
	
	map <int, bool> occ;
	for (auto it : v)
		occ[it] = true;
	
	int tot = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < i; j++)
			tot += occ[v[i] + v[j]];
	
	assert(tot == m);
}

int main() {
	int N, M;
	scanf("%d%d", &N, &M);
	
	if (M > f(N)) {
		puts("-1");
		return 0;
	}
	
	int n = 0;
	while (n < N && f(n + 1) <= M)
		n++;
	
	vector <int> ans;
	for (int i = 1; i <= n; i++)
		ans.push_back(i);
		
	if (n < N) {
		int tmp = n / 2;
		int need = M - f(n);
		for (int k = n + 1; ; k++) {
			if (tmp == need) {
				ans.push_back(k);
				break;
			}
			if (k % 2)	
				tmp--;
		}
	}
	
	int add = N - (int)ans.size();
	for (int i = add; i; i--)
		ans.push_back(1e9 - 1e5 * i);
		
	for (auto it : ans)
		printf("%d ", it);
	puts("");
	
	return 0;
}