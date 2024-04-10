#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }

using namespace std;

const int MAXN = 222;

int n;
int t[MAXN], k[MAXN], c[MAXN];
int a[MAXN][MAXN];

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &t[i]);
	for (int i = 1; i <= n; i++)
	{
		int m;
		scanf("%d", &m);
		for (int j = 0; j < m; j++)
		{
			int x;
			scanf("%d", &x);
			a[x][k[x]++] = i;
		}
	}
	
	
	int ans = 1e+9;
	
	for (int st = 1; st <= 3; st++)
	{
		int curr = st;
		int res = 0, m = 0;
		queue <int> q;
		memset(c, 0, sizeof(c));
		
		for (int i = 1; i <= n; i++)
			for (int j = 0; j < k[i]; j++)
				c[a[i][j]]++;
		for (int i = 1; i <= n; i++)
			if (c[i] == 0)
				q.push(i);
				
		while (m < n)
		{
			queue <int> Q;
//			cout << curr << endl;
			while (q.size())
			{
				int x = q.front();
				q.pop();
				if (t[x] == curr)
				{
//					cout << "\t" << x << endl;
					res += 1;
					m += 1;
					for (int i = 0; i < k[x]; i++)
						if (--c[a[x][i]] == 0)
							q.push(a[x][i]);
				}
				else
				{
					Q.push(x);
				}
			}
			curr = curr == 3? 1 : curr + 1;
			res += 1;
			q = Q;
		}
		ans = min(ans, res - 1);
//		cout << res << endl;
	}
	cout << ans << endl;
	return 0;
}