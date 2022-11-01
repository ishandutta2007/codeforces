#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int psb[26], tmp[26];
char c[101010], d[4];

int main() {
	int n, i, j, st = 26, ans = 0;
	scanf("%d", &n);
	for (i = 0; i < 26; i++) psb[i] = 1;
	for (i = 0; i < n - 1; i++) {
		scanf("%s %s", &d, &c);
		if (d[0] == '.') {
			for (j = 0; j < strlen(c); j++) psb[c[j] - 'a'] = 0;
		}
		else if (d[0] == '!') {
			if (st == 1) ans++;
			for (j = 0; j < 26; j++) tmp[j] = 0;
			for (j = 0; j < strlen(c); j++) tmp[c[j] - 'a'] = 1;
			for (j = 0; j < 26; j++) psb[j] = psb[j] & tmp[j];
		}
		else {
			if (st == 1) ans++;
			psb[c[0]-'a'] = 0;
		}
		st = 0;
		for (j = 0; j < 26; j++) st += psb[j];
	}
	scanf("%s %s", &d, &c);
	printf("%d", ans);
}