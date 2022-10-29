#include <bits/stdc++.h>
using namespace std;

#define MAXN 1123456

int a[MAXN];

int main(void)
{
	int n, x;
	scanf("%d %d", &n, &x);
	vector<pair<int,int>> v;
	set<int> s;
	scanf("%d", &a[0]);
	s.insert(a[0]);
	int mx = a[0];
	for (int i = 1; i < n; i++)
	{
		scanf("%d", &a[i]);
		if (mx > a[i])
			v.push_back({a[i], mx});
		auto it = s.upper_bound(a[i]);
		if (it != s.end() && *it > a[i])
			v.push_back({a[i], *it});
		mx = max(mx, a[i]);
		s.insert(a[i]);
	}

	sort(v.begin(), v.end());
	int l = -1;
	mx = 1;
	int mi = x + 1;
	long long ans = 0;
	// for (int i = 0; i < v.size(); i++)
	// 	printf(" %d %d\n", v[i].first, v[i].second);
	// printf("aaa\naaa\n");
	for (int i = 1; i <= x; i++)
	{
		while (l + 1 < v.size() && v[l + 1].first < i)
		{
			l++;
			mx = max(mx, v[l].second);
			mi = min(mi, v[l].second);
		}

		if (mi < i)
			break;
		int menor_fim = max(i, mx);
		if (v.size() > 0)
			menor_fim = max(menor_fim, v[v.size() - 1].first);
		
		// cout << " " << i << " " << max(0, x - menor_fim + 1) << endl;
		ans += max(0, x - menor_fim + 1);
	}

	cout << ans << endl;
}