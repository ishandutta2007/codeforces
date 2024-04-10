//http://codeforces.com/contest/547/problem/C

#include <stdio.h>
#include <vector>
using namespace std;

typedef vector<int> vi;

int a[212345];
int in[212345];
int np[512345];
int nd[512345];

void fact(int x, vi &fx)
{
	while(x != 1)
	{
		fx.push_back(np[x]);
		int y = np[x];
		while(x % y == 0)
			x /= y;
	}
}

int
main(void)
{
	for(int i = 2; i <= 500000; i++)
		if(np[i] == 0)
			for(int j = i; j <= 500000; j += i)
				np[j] = i;
	
	int n, q, nfx, x;
	scanf("%d %d", &n, &q);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	long long ans = 0, sz = 0;
	while(q--)
	{
		scanf("%d", &x);
		vi fx;
		fact(a[x], fx);
		nfx = fx.size();
		int tmp = 0;
		if(in[x])
			for(int i = 1; i < (1 << nfx); i++)
			{
				int k = 1;
				for(int j = 0; j < nfx; j++)
					if(i & (1 << j))
						k *= fx[j];
				nd[k]--;
			}

		for(int i = 1; i < (1 << nfx); i++)
		{
			int k = 1;
			for(int j = 0; j < nfx; j++)
				if(i & (1 << j))
					k *= fx[j];
			if((__builtin_popcount(i) & 1))
				tmp += nd[k];
			else
				tmp -= nd[k];
		}
			
		if(!in[x])
			for(int i = 1; i < (1 << nfx); i++)
			{
				int k = 1;
				for(int j = 0; j < nfx; j++)
					if(i & (1 << j))
						k *= fx[j];
				nd[k]++;
			}

		if(in[x])
			ans -= tmp, in[x] = 0, sz--;
		
		else
			ans += tmp, in[x] = 1, sz++;
			
		printf("%I64d\n", ((sz*(sz-1))/2) - ans);
	}
}