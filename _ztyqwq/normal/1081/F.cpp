#include <bits/stdc++.h>
using namespace std;
int a[310];
inline void Ask(int l, int r)
{
	printf("? %d %d\n", l, r);
	fflush(stdout);
}
inline int Get()
{
	int x;
	scanf("%d", &x);
	return x;
}
inline void Flip(int l, int r, int &cnt, int d)
{
	int c1 = 0, c2 = 0;
	while(c1 - c2 != d)
	{
		Ask(l, r);
		int newcnt = Get();
		if((newcnt ^ cnt ^ r) & 1)
			c2 ^= 1;
		else
			c1 ^= 1;
		cnt = newcnt;
	}
}
int main()
{
	int n, cnt;
	scanf("%d %d", &n, &cnt);
	if(n == 1)
	{
		printf("! %d\n", cnt);
		fflush(stdout);
		return 0;
	}
	int ssum = 0;
	for(int r = n - 1; r >= 2; r--)
	{
		int l = 2 - ((n - r) & 1), ccnt = cnt;
		Flip(l, r, ccnt, 1);
		int suf = (cnt + ccnt - r) >> 1; // pre + suf = cnt, r - pre + suf = ccnt
		a[r + 1] = suf - ssum;
		ssum = suf;
		Flip(l, r, ccnt, 1);
	}
	int l = 2, r = n, ccnt = cnt;
	Flip(l, r, ccnt, -1);
	int pre = (cnt + ccnt + 1 - n) >> 1; // pre + suf = cnt, pre + n - 1 - suf = ccnt
	a[1] = pre;
	a[2] = cnt - ssum - pre;
	Flip(l, r, ccnt, -1);
	printf("! ");
	for(int i = 1; i <= n; i++)
		printf("%d", a[i]);
	putchar('\n');
	fflush(stdout);
	return 0;
}