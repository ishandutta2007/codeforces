#include<cstdio>
#include<algorithm>
#include<vector>
#define N_ 101000
using namespace std;
char p[20];
int Num[10];
int Input() {
	int c, i, j;
	scanf("%d", &c);
	for (i = 1; i <= c; i++) {
		scanf("%s", p);
		for (j = 0; p[j]; j++)Num[p[j] - '0'] = i;
	}
	return c;
}
int main() {
	int i;
	for (int i = 1;; i++) {
		if (i % 2 == 0) {
			printf("next 0 1\n");
			fflush(stdout);
			Input();
			if (Num[0] == Num[1]) {
				while (1) {
					printf("next 0 1 2 3 4 5 6 7 8 9\n");
					fflush(stdout);
					if (Input() == 1) {
						puts("done");
						return 0;
					}
				}
			}
		}
		else {
			printf("next 1\n");
			fflush(stdout);
			Input();
		}
	}
}