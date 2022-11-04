#include <bits/stdc++.h>

using namespace std;

int n, m, x1, x2, Ans = 0;

bool B[7];

void Search(int x, int s = 0)
{
	if(x == x1 + x2 + 1)
	{
		if(s < m) Ans++;
		return;
	}
	if(x == x1 + 1)
	{
		if(s >= n) return;
		s = 0;
	}
	for(int i = 0; i < 7; i++)
		if(!B[i])
		{
			B[i] = 1;
			Search(x + 1, s * 7 + i);
			B[i] = 0;
		}
}

int main()
{
	scanf("%d%d", &n, &m);
	x1 = 0, x2 = 0;
	int tmpn = n - 1, tmpm = m - 1;
	while(tmpn) x1++, tmpn /= 7;
	while(tmpm) x2++, tmpm /= 7;
	x1 = max(1, x1), x2 = max(1, x2);
	if(x1 + x2 > 7)
	{
		puts("0");
		return 0;
	}
	int a = x1, b = x2;
	Search(1);
	printf("%d\n", Ans);
	return 0;
}