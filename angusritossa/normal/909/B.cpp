#include <bits/stdc++.h>
using namespace std;
int n, ans;
int main()
{
	scanf("%d", &n);
	n++;
	for (int i = 0; i < n/2; i++)
	{
		int k = n - i*2;
		ans++;
		ans+=k-2;
		assert(k-2 >= 0);
	}
	printf("%d\n", ans);
}