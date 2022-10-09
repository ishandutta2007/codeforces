#include <bits/stdc++.h>
using namespace std;

const int DIM = 2005;

int n, ans;
int a[DIM], b[DIM], aux[DIM];

bool isSorted() {
	for (int i = 1; i <= 2 * n ; ++i)
		if (a[i] != i) return false;
	return true;
}

void Try(vector <int> &x, vector <int> &y) {
	int cnt = 4 * n, nr = 0;
	while (cnt--) {
		++nr;
		for (int i = 1; i <= 2 * n ; ++i) b[x[i]] = a[i];
		for (int i = 1; i <= 2 * n ; ++i) a[i] = b[i];
		
		if (isSorted()) {
			if (ans == -1) ans = nr;
			ans = min(ans, nr);
			return ;
		}

		++nr;
		for (int i = 1; i <= 2 * n ; ++i) b[y[i]] = a[i];
		for (int i = 1; i <= 2 * n ; ++i) a[i] = b[i];
		
		if (isSorted()) {
			if (ans == -1) ans = nr;
			ans = min(ans, nr);
			return ;
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= 2 * n ; ++i)
		scanf("%d", &a[i]), aux[i] = a[i];
	
	if (isSorted()) {
		printf("0");
		return 0;
	}

	vector <int> x(2 * n + 1), y(2 * n + 1);
	for (int i = 1; i <= 2 * n ; i += 2) {
		x[i] = i + 1;
		x[i + 1] = i;
	}
	
	for (int i = 1; i <= n ; ++i) {
		y[i] = i + n;
		y[i + n] = i; 
	}

	ans = -1;
	Try(x, y);
	for (int i = 1; i <= 2 * n ; ++i) a[i] = aux[i];
	Try(y, x);

	printf("%d", ans);
	return 0;
}