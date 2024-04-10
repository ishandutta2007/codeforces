#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
int a[200010];
set<int> st;
signed main()
{
	int t;
	scanf("%lld", &t);
	while(t--)
	{
		int n, k;
		scanf("%lld %lld", &n, &k);
		st.clear();
		for(int i = 1; i <= n; i++)
			scanf("%lld", &a[i]), st.insert(a[i]);
		for(int i = 1; i <= n; i++)
			if(st.find(a[i] + k) != st.end())
			{
				printf("YES\n");
				goto yes;
			}
		printf("NO\n");
		yes:;
	}
	return 0;
}