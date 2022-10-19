#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e2 + 5;

int N;
vector < vector <int> > cyc[MAXN];

void add(int n, vector <int> v) {
	cyc[n].push_back(v);
}

int main() {
	scanf("%d", &N);
	
	add(3, {1, 2, 3});
	add(3, {1, 2, 3});
	add(4, {1, 2, 3, 4});
	add(4, {1, 3, 4, 2});
	add(4, {1, 4, 2, 3});
	
	for (int i = 5; i <= N; i++) {
		cyc[i] = cyc[i - 2];
		add(i, {i - 1, i, 1});
		if (i % 2)
			add(i, {i - 1, i, 1});
		else {
			add(i, {i - 1, i, 2});
			add(i, {i - 1, 2, i, 1});
		}
		for (int j = i - 2; j > 2; j -= 2)
			for (int k = 0; k < 2; k++)
				add(i, {i - 1, j, i, j - 1});
	}
	
	printf("%d\n", cyc[N].size());
	for (auto it : cyc[N]) {
		printf("%d", it.size());
		for (auto node : it)
			printf(" %d", node);
		puts("");
	}
	
	return 0;
}