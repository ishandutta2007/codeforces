#include <bits/stdc++.h>

using namespace std;

int n;

int X[110];

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &X[i]);
	for(int i = 1; i <= n; i++)
	{
		int v = i;
		for(int j = i; j <= n; j++) if(X[j] < X[v]) v = j;
		if(v == i) continue;
		for(int j = v; j > i; j--) printf("%d %d\n", j - 1, j), swap(X[j - 1], X[j]);
	}
	return 0;
}