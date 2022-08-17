#include <iostream>
#include <vector>

#define MAXN 200

int n, m;
int a[MAXN], b[MAXN];
std::vector<int> Adj[MAXN];
int match[MAXN];
int vis[MAXN]; 

int Aug(int l)
{
	if(vis[l])
		return 0;
	vis[l] = true;
	for(int r : Adj[l])
	{
		if(match[r] == -1 || Aug(match[r]))
		{
			match[r] = l;
			return 1;
		}
	}
	return 0;
}

int main()
{
	std::cin >> n;
	for(int i = 0; i < n; i++)
		std::cin >> a[i];

	std::cin >> m;
	for(int i = 0; i < m; i++)
	{
		std::cin >> b[i];
		match[i] = -1;
	}

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(abs(a[i]-b[j]) <= 1)
				Adj[i].push_back(j);
		}
	}

	int mcbm = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			vis[j] = false;
		mcbm += Aug(i);
	}

	std::cout << mcbm;
}