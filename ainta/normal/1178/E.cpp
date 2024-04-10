#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n;
char p[1010000];
int BE[501000], cnt, c1, c2;
int ED[501000];
void Go(int b, int e) {
	if (b >= e)return;
	int i, j, Mn = 1e9, p1 = -1, p2 = -1;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if (p[b + i] == p[e - j] && b + i < e - j && Mn > i+j) {
				Mn = i + j;
				p1 = b + i, p2 = e - j;
			}
		}
	}
	if (p1 == -1)return;
	BE[cnt] = p1;
	ED[cnt] = p2;
	cnt++;
	Go(p1 + 1, p2 - 1);
}
int main() {
	int i;
	scanf("%s", p);
	for (i = 0; p[i]; i++);
	n = i;
	Go(0, n - 1);
	if (!cnt) {
		printf("%c\n", p[0]);
		return 0;
	}
	c1 = cnt, c2 = cnt;
	if (BE[cnt - 1] + 1 < ED[cnt - 1]) {
		BE[c1++] = BE[cnt - 1] + 1;
	}
	for (i = 0; i < c1; i++)printf("%c", p[BE[i]]);
	for (i = c2 - 1; i >= 0; i--)printf("%c", p[ED[i]]);
	puts("");
}