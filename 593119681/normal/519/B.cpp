#include <map>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 1000000 + 5

int n, A[N], B[N];

map <int, int> Map;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
    {
        scanf("%d", A + i);
        Map[A[i]] ++;
    }
    int t;
    for (int i = 1; i < n; i ++)
    {
        scanf("%d", B + i);
        Map[B[i]] --;
    }
    for (int i = 1; i <= n; i ++)
        if (Map[A[i]])
        {
            printf("%d\n", A[i]);
            Map[A[i]] --;
        }
    for (int i = 1; i < n; i ++)
        Map[B[i]] ++;
    for (int i = 1; i < n - 1; i ++)
    {
        scanf("%d", &t);
        Map[t] --;
    }
    for (int i = 1; i <= n; i ++)
        if (Map[A[i]])
        {
            printf("%d\n", A[i]);
            Map[A[i]] --;
        }
    return 0;
}