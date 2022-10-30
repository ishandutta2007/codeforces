#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int p[1000010];
int ind[500010][2];
inline int Get(int x)
{
	return ind[p[x]][x == ind[p[x]][0]];
}
bool vis[1000010];
int main()
{
	int n;
	scanf("%d", &n);
	if(!(n & 1))
	{
		printf("First\n");
		fflush(stdout);
		for(int i = 1; i <= n; i++)
			printf("%d ", i);
		for(int i = 1; i <= n; i++)
			printf("%d ", i);
		putchar('\n');
		fflush(stdout);
	}
	else
	{
		printf("Second\n");
		fflush(stdout);
		for(int i = 1; i <= (n << 1); i++)
		{
			scanf("%d", &p[i]);
			ind[p[i]][bool(ind[p[i]][0])] = i;
		}
		vector< vector<int> > ans;
		ll tot = 0;
		for(int i = 1; i <= n; i++)
			if(!vis[i])
			{
				vector<int> res;
				res.push_back(i);
				tot += i;
				vis[i] = true;
				int now = i;
				while(true)
				{
					int x = Get(now), y = (x > n) ? x - n : x + n;
					if(y == i)
						break;
					res.push_back(y);
					tot += y;
					vis[min(x, y)] = true;
					now = y;
				}
				ans.push_back(res);
			}
		if(tot % (n << 1))
			for(auto &vec: ans)
				if(vec.size() & 1)
				{
					for(auto &x: vec)
						x = Get(x);
					break;
				}
		for(auto vec: ans)
			for(auto x: vec)
				printf("%d ", x);
		putchar('\n');
	}
	return 0;
}