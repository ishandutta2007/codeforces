#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100005;

int N;
int h[MAXN];
int sol[MAXN];

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", h + i);
	int maks = 0;
	for (int i = N - 1; i >= 0; i--) {
		sol[i] = max(maks + 1 - h[i], 0);
		maks = max(maks, h[i]);
	}
	for (int i = 0; i < N; i++)
		printf("%d ", sol[i]);
	puts("");
	return 0;
}