#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 105;

int N;
int a[2 * MAXN];

int main() {
	scanf("%d", &N);
	for (int i = 0; i < 2 * N; i++)
		scanf("%d", a + i);
	
	sort(a, a + 2 * N);
	
	puts(a[N - 1] < a[N] ? "YES" : "NO");
	
	return 0;
}