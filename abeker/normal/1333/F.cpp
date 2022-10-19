#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 5;
const int INF = 0x3f3f3f3f;

int N;
int smallest[MAXN];
int largest[MAXN];
bool in[MAXN];
int ans[MAXN];

void load() {
	scanf("%d", &N);
}

void solve() {
	memset(ans, INF, sizeof ans);
	
	for (int i = 2; i <= N; i++)
		if (!smallest[i])
			for (int j = i; j <= N; j += i)
				if (!smallest[j])
					smallest[j] = i;
	
	for (int i = 2; i <= N; i++)
		largest[i] = i / smallest[i];
		
	int curr = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = i; j <= N; j += i)
			if (largest[j] <= i && !in[j]) {
				in[j] = true;
				curr++;
			}
		ans[curr] = min(ans[curr], i);	
	}
	
	for (int i = N; i; i--)
		ans[i] = min(ans[i], ans[i + 1]);
	
	for (int i = 2; i <= N; i++)
		printf("%d ", ans[i]);
	puts("");
}

int main() {
	load();
	solve();
	return 0;
}