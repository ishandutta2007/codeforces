#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 5;

int N;
int x[MAXN], y[MAXN];

void attempt(vector <int> v) {
	if (v.empty() || v.size() == N)
		return;
	printf("%d\n", v.size());
	for (auto it : v)
		printf("%d ", it + 1);
	puts("");
	exit(0);
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d%d", x + i, y + i);
		x[i] += 1e6;
		y[i] += 1e6;
	}
	
	while (1) {
		vector <int> gps[2][2];
		for (int i = 0; i < N; i++)
			gps[x[i] % 2][y[i] % 2].push_back(i);
		
		vector <int> same;
		for (int i = 0; i < 2; i++)
			for (auto it : gps[i][i])
				same.push_back(it);
		
		attempt(same);
		
		vector <int> even;
		for (int i = 0; i < 2; i++)
			for (auto it : gps[0][i])
				even.push_back(it);
		
		attempt(even);
		
		for (int i = 0; i < N; i++) {
			x[i] /= 2;
			y[i] /= 2;
		}
	}
	
	return 0;
}