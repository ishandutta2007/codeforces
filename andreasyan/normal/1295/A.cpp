#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n;
void solv()
{
    scanf("%d", &n);
    if (n % 2 == 0)
    {
        for (int i = 0; i < n / 2; ++i)
            printf("1");
        printf("\n");
    }
    else
    {
        printf("7");
        for(int i = 0; i < (n / 2) - 1; ++i)
            printf("1");
        printf("\n");
    }
}

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
    {
        solv();
    }
    return 0;
}