#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
int currsame;
int curr;
int ans;
char a[1000010], b[1000010];
int main()
{
	scanf(" %s", a);
	scanf(" %s", b);
	int n = strlen(a);
	int m = strlen(b);
	for (int i = 1; i < m; i++)
	{
		currsame += a[i] == a[i-1];
	}
	for (int i = 0; i < m; i++)
	{
		if (a[i] != b[i]) curr = !curr;
	}
	ans += !curr;
	D("%d\n", curr);
	for (int i = 0; i < n-m; i++)
	{
		currsame += a[i+m] == a[i+m-1];
		if ((m-currsame)%2) curr = !curr;
		D("%d: %d %d\n", i, curr, currsame);
		ans += !curr;
		currsame -= a[i] == a[i+1]; 
	}
	printf("%d\n", ans);
}