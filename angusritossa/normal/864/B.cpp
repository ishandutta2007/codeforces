#include <bits/stdc++.h>
using namespace std;
set<char> s;
int n, ans;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		char a;
		scanf(" %c", &a);
		if ('A' <= a && a <= 'Z')
		{
			s.clear();
		}
		else s.insert(a);
		ans = max(ans, (int)s.size());
	}
	printf("%d\n", ans);
}