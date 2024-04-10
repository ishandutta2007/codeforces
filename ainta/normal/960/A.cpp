#include<cstdio>
char p[101000];
int C[3], ck;
int main() {
	int i;
	scanf("%s", p);
	for (i = 0; p[i]; i++) {
		C[p[i] - 'a']++;
		if (p[i] == 'c'&&p[i + 1] == 'a')ck = 1;
		if (p[i] == 'c'&&p[i + 1] == 'b')ck = 1;
		if (p[i] == 'b'&&p[i + 1] == 'a')ck = 1;
	}
	if (ck || !C[0] || !C[1] || !C[2] || (C[2] != C[0] && C[2] != C[1]))puts("NO");
	else puts("YES");
}