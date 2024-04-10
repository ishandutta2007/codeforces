#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int MAXN = 100001;
int last[MAXN];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif

    int t;
    scanf("%d", &t);
    for (int j = 1; j <= t; j++)
    {
    	int x, y;
    	scanf("%d %d", &x, &y);

    	int ans = 0;
    	for (int i = 1; i * i <= x; i++)
    		if (x % i == 0)
    		{
    			if (last[i] < j - y) ans++; 
    			if (i * i < x && last[x / i] < j - y) ans++;

    			last[i] = j;
    			last[x / i] = j;
    		}
    	printf("%d\n", ans);
    }

    return 0;
}