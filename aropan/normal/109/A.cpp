#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
//#include <iostream>


using namespace std;

int n, m;
int x, y;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif

    scanf("%d", &n);
    for (int i = n / 7; i >= 0; i--)
    	if ((n - 7 * i) % 4 == 0)
    	{
    		for (int j = (n - 7 * i) / 4; j > 0; j--) printf("4");
    		for (int j = i; j > 0; j--) printf("7");
    		printf("\n");
    		return 0;
    	}
    printf("-1");
    return 0;
}