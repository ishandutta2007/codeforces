#include <bits/stdc++.h>

using namespace std;

bool B[1010];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		int s;
		scanf("%d", &s);
		B[s] = 1;
	}
	for(int i = 1; i <= 1000; i++) if(B[i] && B[i + 1] && B[i + 2])
	{
		puts("YES");
		return 0;
	}
	puts("NO");
	return 0;
}