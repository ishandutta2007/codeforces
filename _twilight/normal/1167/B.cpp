#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

int A[] = {4, 8, 15, 16, 23, 42};

#define pii pair<int, int>
map<int, pii> mp;

pii query(int i, int j) {
	printf("? %d %d\n", i, j);
	fflush(stdout);
	fflush(stdin);
	int prod = 0;
	scanf("%d", &prod);
	return mp[prod];
}

int a[8];
void solve(int i, int j, int k) {
	pii X = query(i, j);
	pii Y = query(j, k);
	if (X.first == Y.first)
		a[j] = X.first, a[i] = X.second, a[k] = Y.second;
	if (X.first == Y.second)
		a[j] = X.first, a[i] = X.second, a[k] = Y.first;
	if (X.second == Y.first)
		a[j] = X.second, a[i] = X.first, a[k] = Y.second;
	if (X.second == Y.second)
		a[j] = X.second, a[i] = X.first, a[k] = Y.first;
}

int main() {
	for (int i = 0; i < 6; i++) {
		for (int j = i + 1; j < 6; j++) {
			int x = A[i] * A[j];
			mp[x] = pii(A[i], A[j]);
		}		
	}
	solve(1, 2, 3);
	solve(4, 5, 6);
	printf("!");
	for (int i = 1; i <= 6; i++)
		printf(" %d", a[i]);
	return 0;
}