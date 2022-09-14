#include <bits/stdc++.h>

using namespace std;
const int MAXN = 300;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int u[10];
    int n;
    scanf("%d", &n);
    long long m;
    scanf("%I64d", &m);
    for (int i = 0; i < 10; i++)
        u[i] = 0;
    for (int i = 0; i < n; i++)
    {
        int k = m % 10;
        if (k == 2)
            u[2]++;
        if (k == 3)
            u[3]++;
        if (k == 4)
        {
            u[3]++;
            u[2] += 2;
        }
        if (k == 5)
            u[5]++;
        if (k == 6)
        {
            u[5]++;
            u[3]++;
        }
        if (k == 7)
            u[7]++;
        if (k == 8)
        {
            u[7]++;
            u[2] += 3;
        }
        if (k == 9)
        {
            u[7]++;
            u[3] += 2;
            u[2]++;
        }
        m /= 10;
    }
    for (int i = 9; i > 1; i--)
        for (int j = 0; j < u[i]; j++)
            printf("%d", i);
    return 0;
}