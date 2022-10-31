#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
deque<int> v[26][2];
int a[200001], id[200001];
int c[200001];
int n;
inline int lowbit(int x)
{
	return x & -x;
}
inline void add(int p)
{
	for(int i = p; i <= n; i += lowbit(i))
		c[i]++;
}
inline int sum(int p)
{
	int ans = 0;
	for(int i = p; i; i -= lowbit(i))
		ans += c[i];
	return ans;
}
signed main()
{
	scanf("%lld", &n);
	string s;
	cin >> s;
	s = "#" + s;
	for(int i = 1; i <= n; i++)
	{
		v[s[i] - 'a'][0].push_back(i);
		v[s[i] - 'a'][1].push_front(n + 1 - i);
	}
	for(int u = 0; u < 26; u++)
	{
		for(auto i = v[u][0].begin(), j = v[u][1].begin(); i != v[u][0].end(); i++, j++)
			a[*i] = *j, id[*j] = *i;
	}
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		int u = id[i];
		ans += sum(n) - sum(u);
		add(u);
	}
	printf("%lld\n", ans);
	return 0;
}