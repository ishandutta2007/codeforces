#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef pair <int, int> Pii;
#define x first
#define y second
#define mp make_pair
#define N 1000000 + 5

int n, In[N], Out[N], A[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        In[v] = u, Out[u] = v;
        if (Out[u] == 0) Out[u] = -1;
    }
    for (int i = 2, u = Out[0]; u > 0 && i <= n; u = Out[u], i += 2)
        A[i] = u;
    int i;
    for (i = 1; i < N; i ++)
        if (Out[i] != 0 && !In[i] && Out[0] != i) break ;
    for (int j = 1, u = i; u > 0 && j <= n; u = Out[u], j += 2)
        A[j] = u;    
    for (int i = 1; i <= n; i ++)
        printf("%d%c", A[i], i == n ? '\n' : ' ');    
    return 0;
}