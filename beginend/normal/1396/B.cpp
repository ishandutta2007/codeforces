#include<bits/stdc++.h>
using namespace std;

const int N = 105;

int n, a[N];
priority_queue<int> que;

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]), que.push(a[i]);
		int ls = 0, i;
		for (i = 0; !que.empty(); i ^= 1)
		{
			int now = que.top(); que.pop();
			if (ls) que.push(ls);
			ls = now - 1;
		}
		if (i) puts("T");
		else puts("HL");
	}
	return 0;
}