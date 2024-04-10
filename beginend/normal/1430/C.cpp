#include<bits/stdc++.h>
using namespace std;

const int N = 200005;

int n;

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		printf("%d\n", 2);
		int now = n;
		for (int i = n - 1; i >= 1; i--)
			printf("%d %d\n", now, i), now = (now + i + 1) / 2;
	}
	return 0;
}