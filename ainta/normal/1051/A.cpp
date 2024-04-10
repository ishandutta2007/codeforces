#include<cstdio>
#include<algorithm>
using namespace std;
char p[110];
int n, w[110], CK[4], chk;
char q[4] = "1aA";
bool Check(int L) {
	int i, ck = 0;
	for (i = 0; i < n; i++) {
		if (p[i] >= '0'&&p[i] <= '9')ck |= 1;
		else if (p[i] >= 'A'&&p[i] <= 'Z')ck |= 2;
		else if (p[i] >= 'a'&&p[i] <= 'z')ck |= 4;
	}
	if (ck == 7) {
		puts(p);
		return true;
	}
	return false;
}
void Go(int pv, int e, int L) {
	if (pv == e) {
		if (!chk && Check(L)) {
			chk = 1;
		}
		return;
	}
	for (int i = 0; i < 3; i++) {
		char ch = p[pv];
		p[pv] = q[i];
		Go(pv + 1, e, L);
		p[pv] = ch;
	}
}
int main() {
	int TC, i, j, k;
	scanf("%d", &TC);
	while (TC--) {
		scanf("%s", p);
		for (i = 0; p[i]; i++) {
			if (p[i] >= '0'&&p[i] <= '9')w[i] = 1;
			else if (p[i] >= 'A'&&p[i] <= 'Z')w[i] = 2;
			else if (p[i] >= 'a'&&p[i] <= 'z')w[i] = 3;
		}
		n = i;
		chk = 0;
		for (i = 0; i <= 3; i++) {
			for (j = 0; j <= n - i && !chk; j++) {
				Go(j, j + i, i);
			}
		}

	}
}