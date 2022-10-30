#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
int a[200010];
inline int gcd(int x, int y)
{
	return y ? gcd(y, x % y) : x;
}
signed main()
{
	int t;
	scanf("%lld", &t);
	while(t--)
	{
		int n;
		scanf("%lld", &n);
		for(int i = 1; i <= n; i++)
			scanf("%lld", &a[i]);
		int ans = 0;
		for(int i = 0; i < 30; i++)
		{
			int cnt = 0;
			for(int j = 1; j <= n; j++)
				cnt += (a[j] >> i);
			ans = gcd(ans, cnt);
		}
		if(ans == 0)
		{
			for(int i = 1; i <= n; i++)
				printf("%d ", i);
			putchar('\n');
		}
		else
		{
			stack<int> st;
			int s = sqrt(ans);
			for(int i = 1; i <= s; i++)
				if(ans % i == 0)
				{
					printf("%d ", i);
					if(i * i != ans)
						st.push(ans / i);
				}
			while(!st.empty())
				printf("%d ", st.top()), st.pop();
			putchar('\n');
		}
	}
	return 0;
}