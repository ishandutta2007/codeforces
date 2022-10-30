#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <cstdlib>

using namespace std;

#define mp make_pair
#define pb push_back

long long a[111111];
long long b[111111];
long long add = 0;

int main()
{
	#if 0
		freopen("a.in", "r", stdin);
		freopen("a.out", "w", stdout);
	#endif
	
	int n, m;
	scanf("%d %d", &n, &m);
	
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		a[i] = x;
	}
	
	for (int i = 0; i < m; i++)
	{
		int type ;
		scanf("%d", &type);
		
		if (type == 1)
		{
			int v, x;
			scanf("%d %d", &v, &x);
			b[v-1] = add;
			a[v-1] = x;
		}
		else if (type == 2)
		{
			int d;
			scanf("%d", &d);
			add += d;
		}
		else
		{
			int v;
			scanf("%d", &v);
			v--;
			printf("%I64d\n", a[v] + add - b[v]);
		}
	}
	
	return 0;
}