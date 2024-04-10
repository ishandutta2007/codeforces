#include <bits/stdc++.h>
using namespace std;
int t;
int main()
{
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		int n, k;
		scanf("%d%d", &n, &k);
		vector<int> v;
		for (int i = 0; i < k; i++)
		{
			int a;
			scanf("%d", &a);
			v.push_back(a);
		}
		sort(v.begin(), v.end());
		int ans = 0;
		ans = max(ans, v[0]-1);
		ans = max(ans, n-v[v.size()-1]);
		for (int i = 1; i < v.size(); i++)
		{
			ans = max(ans, (v[i]-v[i-1])/2);
		}
		printf("%d\n", ans+1);
	}
}