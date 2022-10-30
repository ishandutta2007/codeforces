#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		vector<int> ans;
		int p = 1;
		while(n)
		{
			if(n % 10)
				ans.push_back(n % 10 * p);
			n /= 10, p *= 10;
		}
		printf("%d\n", ans.size());
		for(auto x: ans)
			printf("%d ", x);
		putchar('\n');
	}
	return 0;
}