#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
const int MAXM = 1e6 + 5;
const int MOD = 1e9 + 7;

int N;
vector <int> divs[MAXM];
int dp[MAXN];

inline int add(int x, int y) {
	x += y;
	if (x >= MOD)
		x -= MOD;
	return x;
}

int main() {
	for (int i = MAXN - 1; i; i--)
		for (int j = i; j < MAXM; j += i)
			divs[j].push_back(i);
			
	scanf("%d", &N);
	
	dp[0] = 1;
	for (int i = 0; i < N; i++) {
		int x;
		scanf("%d", &x);
		for (auto it : divs[x])
			if (it <= N)
				dp[it] = add(dp[it], dp[it - 1]);
	}
	
	int ans = 0;
	for (int i = 1; i <= N; i++)
		ans = add(ans, dp[i]);
	
	printf("%d\n", ans);
	
	return 0;
}