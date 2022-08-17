#include <iostream>

int par[150001];
int nex[150001];
int low[150001];

int root(int u)
{
	if(par[u] < 0)
		return u;
	else
		return par[u] = root(par[u]);
}

void merge(int x,int y)
{	
	if((x = root(x)) == (y = root(y)))     return ;
	if(par[y] < par[x])
		x ^= y ^= x^= y;
		
	par[x] += par[y];
	par[y] = x;
	nex[y] = low[x];
	low[x] = low[y];
}

int main()
{
	int n;
	std::cin >> n;
	
	for(int i = 0; i < n; i++)
	{
		par[i] = nex[i] = -1;
		low[i] = i;
	}
	
	for(int i = 0; i < n; i++)
	{
		int a, b;
		std::cin >> a >> b;
		a--; b--;
		merge(a, b);
	}
	
	int u = low[root(0)];
	std::cout << u + 1 << " ";
	while(nex[u] != -1)
	{
		u = nex[u];
		std::cout << u + 1 << " ";
	}
	
	return 0;
}