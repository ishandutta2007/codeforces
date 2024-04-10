#include<cstdio>
#include<algorithm>
using namespace std;
char p[110];
int TC, C[10];
void Solve() {
	int i, s = 0;
	for (i = 0; i < 10; i++) {
		C[i] = 0;
	}
	scanf("%s", p);
	for (i = 0; p[i]; i++) {
		C[p[i] - '0']++;
		s += p[i] - '0';
	}
	if (C[0] && s % 3 == 0) {
		int z = 0;
		for (i = 0; i < 10; i+=2) {
			z += C[i];
		}
		if (z >= 2) {
			puts("red");
			return;
		}
	}
	puts("cyan");
}
int main() {
	scanf("%d", &TC);
	while (TC--) {
		Solve();
	}
}