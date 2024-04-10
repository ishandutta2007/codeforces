//http://codeforces.com/problemset/problem/371/D
#include <stdio.h>
#include <map>
using namespace std;

typedef pair<int,int> pii;

int ans[212345];

int main(void)
{
	int n, tp, x, y, q;
	map<int,int> rdm;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &rdm[i]);
	scanf("%d", &q);
	while(q--)
	{
		scanf("%d", &tp);
		if(tp == 1)
		{
			scanf("%d %d", &x, &y);
			map<int,int>::iterator l = rdm.lower_bound(x);
			map<int,int>::iterator r = l;
			for(map<int,int>::iterator it = l; y != 0 && it != rdm.end(); it++)
			{
				int k = min(it->second, y);
				it->second -= k, y -= k, ans[it->first] += k;
				if(it->second == 0)
					r++;
			}
			if(l != r)
				rdm.erase(l, r);
		}
		else
		{
			scanf("%d", &x);
			printf("%d\n", ans[x]);
		}
	}
}