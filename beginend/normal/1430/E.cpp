#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 200005;

int n, f[N], nx[30], pos[30];
char s[N], t[N];

int find(int x)
{
	return f[x] == x ? x : f[x] = find(f[x]);
}

int main()
{
	scanf("%d", &n);
	scanf("%s", s + 1);
	for (int i = 1; i <= n + 1; i++) f[i] = i, t[i] = s[i];
	for (int i = 0; i < 26; i++)
	{
		nx[i] = 1;
		while (nx[i] <= n && s[nx[i]] - 'a' != i) nx[i]++;
		pos[i] = nx[i];
	}
	reverse(t + 1, t + n + 1);
	LL ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int id = t[i] - 'a', k = nx[id];
		ans += k - i;
		f[pos[id]] = pos[id] + 1;
		for (int j = 0; j < 26; j++) if (nx[j] < k) nx[j]++;
		pos[id] = find(pos[id] + 1); nx[id]++;
		while (pos[id] <= n && s[pos[id]] != t[i])
			pos[id] = find(pos[id] + 1), nx[id]++;
	}
	printf("%lld\n", ans);
	return 0;;
}