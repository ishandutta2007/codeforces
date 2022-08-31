#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
void Do2(int n) {
	int i, p = 1;
	while (p * 2 <= n)p *= 2;
	if (p == n) {
		printf("NO\n");
		return;
	}
	if (n <= 5) {
		printf("NO\n");
		return;
	}
	if (n == 6) {
		printf("YES\n");
		printf("3 6 2 5 1 4\n");
	}
	else {
		printf("YES\n");
		printf("3 6 2 5 1 7 4 ");
		p = 8;
		while (p <= n) {
			int i;
			vector<int>TP;
			for (i = p; i <= min(2 * p - 1, n); i++) {
				TP.push_back(i);
			}
			for (i = 0; i < TP.size(); i++)printf("%d ", TP[(i + 1) % TP.size()]);
			p *= 2;
		}
	}
}
void Do(int n) {
	if (!n)return;
	if (n == 2) {
		printf("2 1 ");
		return;
	}
	int po = 1;
	while (po*2 <= n) {
		po *= 2;
	}
	int i;
	Do(2 * po - 2 - n);
	for (i = 2*po-1-n; i <= n; i++) {
		printf("%d ", po * 2 - 1 - i);
	}
}
void Do1(int n) {
	if (n % 2 == 1) {
		printf("NO");
		return;
	}
	printf("YES\n");
	Do(n);
}
int main() {
	int n;
	scanf("%d", &n);
	Do1(n);
	puts("");
	Do2(n);
}