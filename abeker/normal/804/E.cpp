#include <cstdio>
using namespace std;

void out(int a, int b) {
	printf("%d %d\n", a, b);
}

int main() {
	int N;
	scanf("%d", &N);
		
	if (N % 4 > 1) {
		puts("NO");
		return 0;
	}
	
	puts("YES");
	
	for (int i = N % 4; i < N; i += 4) {
		for (int j = 1; j <= i; j++)
			out(j, i + 1);
		out(i + 1, i + 2);
		for (int j = i; j; j--)
			out(j, i + 2);
		for (int j = 1; j <= i; j++)
			out(j, i + 3);
		out(i + 3, i + 4);
		for (int j = i; j; j--)
			out(j, i + 4);
		out(i + 1, i + 4);
		out(i + 2, i + 3);
		out(i + 1, i + 3);
		out(i + 2, i + 4);
	}
	
	return 0;
}