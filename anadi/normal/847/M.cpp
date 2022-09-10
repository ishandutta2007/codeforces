#include <bits/stdc++.h>
using namespace std;

set<int> elo;
int n, t[1005];

int main() 
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i)
	{
		scanf("%d", &t[i]);
		if (i >= 2)
		{
			elo.insert(t[i] - t[i-1]);
		}
	}
	if (elo.size() > 1)
		printf("%d\n", t[n]);
	else
		printf("%d\n", t[n] + *elo.begin());
	return 0;
}