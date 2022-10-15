#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 20;

int n;
int a[MAXN];


int main()
{
    #ifndef ONLINE_JUDGE
        freopen(".in", "r", stdin);
        freopen(".out", "w", stdout);
    #endif
    scanf("%d", &n);
    for (int i = 0; i < n * n; i++)
    	scanf("%d", &a[i]);
    sort(a, a + n * n);
    do
    {
    	bool f = true;
    	int s = 0;
    	for (int i = 0; i < n; i++) s += a[i];

    	for (int i = 0; i < n && f; i++)
    	{
    		int c = 0;
    		for (int j = 0; j < n; j++)
    			c += a[i * n + j];
    		f &= c == s;
    	}

    	for (int i = 0; i < n && f; i++)
    	{
    		int c = 0;
    		for (int j = 0; j < n; j++)
    			c += a[j * n + i];
    		f &= c == s;
    	}

    	int c;

    	c = 0;
    	for (int i = 0; i < n; i++)
    		c += a[i * n + i];
    	f &= c == s;

    	c = 0;
    	for (int i = 0; i < n; i++)
    		c += a[i * n + (n - i - 1)];
    	f &= c == s;

    	if (f)
    	{
    		printf("%d\n", s);
    		for (int i = 0; i < n; i++)
    		{
    			for (int j = 0; j < n; j++)
    			{
    				if (j) printf(" ");
    				printf("%d", a[i * n + j]);
    			}
    			printf("\n");
			}
			return 0;
    	}
    } while (next_permutation(a, a + n * n));

    fprintf(stderr, "Time execute: %.3lf\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}