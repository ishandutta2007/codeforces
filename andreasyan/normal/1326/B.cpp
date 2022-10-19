#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 200005;

int n;
int b[N];

int a[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &b[i]);
    int maxu = 0;
    for (int i = 1; i <= n; ++i)
    {
        a[i] = b[i] + maxu;
        maxu = max(maxu, a[i]);
    }
    for (int i = 1; i <= n; ++i)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}