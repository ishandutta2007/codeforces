#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		int sum = a + b;
		set<int> ans;
		int c = sum / 2, d = sum - c;
		int mn = abs(b + c - sum), mx = min(a, d) + min(b, c);
		for(int i = mn; i <= mx; i += 2)
			ans.insert(i);
		swap(c, d);
		mn = abs(b + c - sum), mx = min(a, d) + min(b, c);
		for(int i = mn; i <= mx; i += 2)
			ans.insert(i);
		printf("%d\n", ans.size());
		for(auto x: ans)
			printf("%d ", x);
		putchar('\n');
	}
	return 0;
}