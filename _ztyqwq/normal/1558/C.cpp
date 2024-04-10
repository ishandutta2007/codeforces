#include <bits/stdc++.h>
using namespace std;
int a[2050], b[2050];
inline void Reverse(int x, vector<int> &v)
{
	if(x == 1)
		return;
	v.push_back(x);
	int hf = x / 2;
	for(int i = 1; i <= hf; i++)
	{
		swap(b[a[i]], b[a[x + 1 - i]]);
		swap(a[i], a[x + 1 - i]);
	}
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
			scanf("%d", &a[i]), b[a[i]] = i;
		bool flag = true;
		for(int i = 1; i <= n; i++)
			if(abs(a[i] - i) & 1)
			{
				flag = false;
				break;
			}
		if(!flag)
			printf("-1\n");
		else
		{
			vector<int> ans;
			for(int i = n; i >= 3; i -= 2)
			{
				Reverse(b[i], ans);
				Reverse(b[i - 1] - 1, ans);
				Reverse(i, ans);
				Reverse(b[i], ans);
				Reverse(i, ans);
			}
			flag = true;
			for(int i = 1; i <= n; i++)
				if(a[i] != i)
				{
					flag = false;
					break;
				}
			if(!flag)
				printf("-1\n");
			else
			{
				printf("%d\n", ans.size());
				for(auto x: ans)
					printf("%d ", x);
				if(ans.size())
					putchar('\n');
			}
		}
	}
	return 0;
}