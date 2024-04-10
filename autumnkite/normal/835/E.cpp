#include <cstdio>
int n, x, y, bo[15];
int main(){
	scanf("%d%d%d", &n, &x, &y);
	int msk = 0;
	for (register int i = 9; ~i; --i){
		int c = 0, s;
		for (register int j = 1; j <= n; ++j)
			if ((j >> i) & 1) ++c;
		if (c == 0) continue;
		printf("? %d", c);
		for (register int j = 1; j <= n; ++j)
			if ((j >> i) & 1) printf(" %d", j);
		putchar('\n'), fflush(stdout);
		scanf("%d", &s);
		if (s != x && s != 0){
			bo[i] = 1;
			if (!msk) msk |= 1 << i;
		}
	}
	bool flag = 1;
	for (register int i = 9; ~i; --i){
		if (bo[i] && flag){ flag = 0; continue; }
		int c = 0, s;
		msk ^= 1 << i;
		for (register int j = 1; j <= n; ++j)
			if ((j & msk) == msk) ++c;
		if (c == 0){ msk ^= 1 << i; continue; }
		printf("? %d", c);
		for (register int j = 1; j <= n; ++j)
			if ((j & msk) == msk) printf(" %d", j);
		putchar('\n'), fflush(stdout);
		scanf("%d", &s);
		if (s == x || s == 0) msk ^= 1 << i;
	}
	int mskj = msk;
	for (register int i = 0; i < 10; ++i) if (bo[i]) msk ^= 1 << i;
	printf("! %d %d\n", msk, mskj);
}