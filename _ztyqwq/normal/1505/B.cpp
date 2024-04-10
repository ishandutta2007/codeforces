#include <bits/stdc++.h>
using namespace std;
inline int orz(int x)
{
	int res = 0;
	while(x)
	{
		res += (x % 10);
		x /= 10;
	}
	return res;
}
int main()
{
	int n;
	scanf("%d", &n);
	while(n >= 10)
		n = orz(n);
	printf("%d\n", n);
	return 0;
}