#include <iostream>

#define MOD 1000000007
#define MAXN 100000

int par[MAXN];

long long power(long long x, int y, long long p) 
{ 
    long long res = 1;
    x = x % p;
  
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x) % p; 

        y = y>>1;
        x = (x*x) % p;   
    } 
    return res; 
} 

int root(int u)
{
	if(par[u] < 0)
		return u;
	else
		return par[u] = root(par[u]);
}

void merge(int x, int y)
{	
	if((x = root(x)) == (y = root(y)))     return ;
	if(par[y] < par[x])
		x ^= y ^= x^= y;
		
	par[x] += par[y];
	par[y] = x;
}

int main()
{
	long long n;
	int k;
	std::cin >> n >> k;
	
	for(int i = 0; i < n; i++)
		par[i] = -1;
	
	for(int i = 1; i < n; i++)
	{
		int a, b, c;
		std::cin >> a >> b >> c;
		if(!c)
			merge(a-1, b-1);
	}
	
	long long answer = power(n, k, MOD);
	for(int i = 0; i < n; i++)
	{
		if(par[i] < 0)
		{
			answer = (answer - power(-par[i], k, MOD) + MOD)%MOD;
		}
	}
	
	std::cout << answer;
	
	return 0;
}