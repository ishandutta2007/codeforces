#include<cstdio>
#include<algorithm>
using namespace std;
int n;
void Solve() {
	scanf("%d", &n);
	if (n == 1) {
		puts("-1");
		return;
	}
	int i;
	printf("8");
	for (i = 1; i < n; i++)printf("9");
	puts("");
}
int main() {
	int TC;
	scanf("%d", &TC);
	while (TC--) {
		Solve();
	}
}