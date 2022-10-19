#include <bits/stdc++.h>
using namespace std;
const int N = 102;

int n;
char a[N];

int main()
{
    scanf("%d", &n);
    scanf(" %s", a);
    int mek = 0, zro = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == '1')
            ++mek;
        else
            ++zro;
    }
    mek = min(1, mek);
    while (mek--)
        printf("1");
    while (zro--)
        printf("0");
    printf("\n");
    return 0;
}