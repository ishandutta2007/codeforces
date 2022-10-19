#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, M, K;
	scanf("%d%d%d", &N, &M, &K);
	K = N - K;
	
	int ans = N, prv = -1;
	vector <int> gaps;
	while (N--) {
		int x;
		scanf("%d", &x);
		if (prv != -1)
			gaps.push_back(x - prv - 1);
		prv = x;
	}
	
	sort(gaps.begin(), gaps.end());
		
	for (int i = 0; i < K; i++)
		ans += gaps[i];
	
	printf("%d\n", ans);
	
	return 0;
}