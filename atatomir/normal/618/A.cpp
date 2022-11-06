#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back

int n, i;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 20; i >= 0; i--)
        if (n & (1 << i))
            printf("%d ", i + 1);


    return 0;
}