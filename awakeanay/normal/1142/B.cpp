#include <iostream>

#define LOG 20

int main()
{
	int n, m, q;
	std::cin >> n >> m >> q;
	
	int adj[n+1];
	int p[n];
	
	for(int i = 0; i < n; i++)
		std::cin >> p[i];
		
	for(int i = 0; i < n; i++)
		adj[p[i]] = p[(i + 1)%n];
	
	int seq[m];
	for(int i = 0; i < m; i++)
		std::cin >> seq[i];
	
	int next[LOG][m];
	int close[n+1];
	for(int i = 1; i <= n; i++)
		close[i] = m;
	
	for(int i = m-1; i >= 0; i--)
	{
		next[0][i] = close[adj[seq[i]]];
		close[seq[i]] = i;
	}
	
	for(int j = 1; j < LOG; j++)
	{
		for(int i = m-1; i >= 0; i--)
		{
			if(next[j-1][i] == m)
				next[j][i] = m;
			else
				next[j][i] = next[j-1][next[j-1][i]];
		}
	}
	
	int final[m];
	for(int i = 0; i < m; i++)
	{
		int d = n-1;
		final[i] = i;
		int x = LOG;
		while(d > 0)
		{
			if(d >= (1 << x))
			{
				final[i] = next[x][final[i]];
				if(final[i] == m)
					break;
				d -= (1 << x);
			}
			x--;
		}
	}
        
        for(int i = m-2; i >= 0; i--)
            final[i] = std::min(final[i+1], final[i]);
	
	for(int i = 0; i < q; i++)
	{
		int l, r;
		std::cin >> l >> r;
		l--; r--;
		if(final[l] <= r)
			std::cout << 1;
		else
			std::cout << 0;
	}
	
	return 0;
}