#include<bits/stdc++.h>
using namespace std;

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		puts(n % 4 == 0 ? "YES" : "NO");
	}
	return 0;
}