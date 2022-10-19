#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int N;
int enter[MAXN];
int out[MAXN];

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		int x;
		scanf("%d", &x);
		enter[x] = i;
	}
	
	for (int i = 1; i <= N; i++) 
		scanf("%d", out + i);
	
	int ans = 0, mini = N + 1;
	for (int i = N; i; i--) {
		ans += enter[out[i]] > mini;
		mini = min(mini, enter[out[i]]);
	}
	
	printf("%d\n", ans);
	
	return 0;
}