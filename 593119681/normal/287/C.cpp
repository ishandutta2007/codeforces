#include <cmath> 
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 100000 + 5

int n, A[N];

inline void Solve(int l, int r, int delta)
{
    if (l > r) return ;
    if (l == r)
    {
        A[l] = delta + 1;
        return ;
    }
    A[l] = delta + 2, A[l + 1] = delta + r - l + 1;
    A[r - 1] = delta + 1, A[r] = delta + r - l;
    Solve(l + 2, r - 2, delta + 2);
}

int main()
{
    scanf("%d", &n);
    if ((n & 3) >= 2) puts("-1");
    else
    {
        Solve(1, n, 0);
        for (int i = 1; i <= n; i ++)
            printf("%d%c", A[i], i == n ? '\n' : ' ');
    }
    
    return 0;
}