#include <bits/stdc++.h>

using namespace std;

const int MX = 10000000;

char s[MX];

map<pair<int, int>, int> memo;

int foo(int i, int n) {
	auto state = make_pair(i, n);
	if (memo.count(state) == 1) return memo[state];
	
	if (n <= 1) return memo[state] = i;
	
	i = foo(i, n / 2);
	
	if (i == -1) return memo[state] = -1;
	
	i = foo(i, (n + 1) / 2);
	
	if (i == -1) return memo[state] = -1;
	
	int a = n / 2;
	int b = (n + 1) / 2;
	while (a > 0 && b > 0) {
		if (s[i] == 0) return memo[state] = -1;
		
		if (s[i] == '0') a--;
		else b--;
		i++;
	}
	
	return memo[state] = i;
}

void solve(int n) {
	int it = 0;
	vector<int> a(n), b(n);
	iota(a.begin(), a.end(), 0);
	
	function<void(int, int)> mergeSort = [&a, &b, &it, &mergeSort](int l, int r) {
		if (r - l <= 1) return;
		
		int m = (l + r) >> 1;
		
		mergeSort(l, m);
		mergeSort(m, r);
		
		int i = l, j = m, k = l;
		while (i < m && j < r) {
			if (s[it++] == '0') {
				b[k] = a[i];
				i += 1;
			}
			else {
				b[k] = a[j];
				j += 1;
			}
			
			k += 1;
		}
		
		while (i < m) {
			b[k] = a[i];
			i += 1;
			k += 1;
		}
		
		while (j < r) {
			b[k] = a[j];
			j += 1;
			k += 1;
		}
		
		for (int p = l; p < r; p++) {
			a[p] = b[p];
		}
	};
	
	mergeSort(0, n);
	
	for (int i = 0; i < n; i++) b[a[i]] = i + 1;
	
	printf("%d\n", n);
	for (int i = 0; i < n; i++) printf("%d ", b[i]);
	printf("\n");
}

int main() {
	ignore = scanf("%s", s);
	
	int len = strlen(s);
	
	for (int n = 1; true; n++) {
		if (foo(0, n) == len) {
			solve(n);
			
			return 0;
		}
	}
}