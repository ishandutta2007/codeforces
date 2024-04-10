#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 5;

typedef pair <int, int> pii;

int N;
pii p[MAXN];

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int sum = 0;
		for (int j = 0; j < 4; j++) {
			int x;
			scanf("%d", &x);
			sum += x;
		}
		p[i] = {sum, -i};
	}
	
	sort(p, p + N);
	
	for (int i = 0; i < N; i++)
		if (!p[i].second) {
			printf("%d\n", N - i);
			break;
		}
		
	return 0;
}