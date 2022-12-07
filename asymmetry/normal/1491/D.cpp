//Autor: Bartomiej Czarkowski
#include <bits/stdc++.h>

using namespace std;

void solve()
{
	int n, m;
	scanf("%d%d", &n, &m);
	vector <int> u(32, 0), v(32, 0), dp(32, 0), pp(32, 0);
	for(int i=0; i<32; ++i)
	{
		if(n&1) u[i]=1;
		if(m&1) v[i]=1;
		//~ if(n && !m)
		//~ {
			//~ printf("NO\n");
			//~ return;
		//~ }
		n>>=1;
		m>>=1;
	}
	if(v[0] && !u[0])
	{
		printf("NO\n");
		return;
	}
	if(u[0] && !v[0]) pp[0]=1;
	else dp[0]=1;
	for(int i=1; i<32; ++i)
	{
		if(v[i] && !u[i])
		{
			if(!pp[i-1])
			{
				printf("NO\n");
				return;
			}
			pp[i]=pp[i-1]-1;
			dp[i]=1;
		}
		else if(v[i] && u[i])
		{
			dp[i]=dp[i-1];
			pp[i]=pp[i-1];
		}
		else if(!v[i] && u[i])
		{
			pp[i]=pp[i-1]+1;
		}
		else
		{
			dp[i]=dp[i-1];
			pp[i]=pp[i-1];
		}
	}
	if(!dp[31]) printf("NO\n");
	else printf("YES\n");
}

int main()
{
	//~ ios_base::sync_with_stdio(false);
	//~ cin.tie(NULL);
	int q=1;
	scanf("%d", &q);
	while(q--)
	{
		solve();
	}
	return 0;
}