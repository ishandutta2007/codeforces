#include <cstdio>
int tri[500], maxtri[100030];
int main() {
	int k, i, j, c = 0;
	scanf("%d", &k);
	tri[0] = 0;
	for (i = 1; i < 500; i++) tri[i] = tri[i - 1] + i;
	for (i = 0; i < 499; i++) {
		for (j = tri[i]; j < tri[i + 1] && j < 100030; j++) maxtri[j] = i;
	}
	if (k == 0) printf("ab");
	while (k > 0) {
		for (i = 0; i <= maxtri[k]; i++) printf("%c", 'a' + c);
		k = k - tri[maxtri[k]];
		c++;
	}
}