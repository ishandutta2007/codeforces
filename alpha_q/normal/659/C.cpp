#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e9;

set <int> S;
vector <int> R;
int n, m, x, k = 0;

int main() {	
	//freopen("input.txt", "r", stdin);

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		S.insert(x);
	}

	for (int i = 1; i <= MAX; i++) {
		if (m < i) break;
		if (S.count(i)) continue;
		R.push_back(i); 
		m -= i;
		k++;
	}

	printf("%d\n", k);
	for (int i = 0; i < k; i++) printf("%d ", R[i]);
	printf("\n");
    return 0;
}