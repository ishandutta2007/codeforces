#include <bits/stdc++.h>
using namespace std;
const int N = 102;

int n;
char a[N];

int m;
char ans[N];

int main()
{
    scanf(" %s", a);
    n = strlen(a);
    int l = n / 2 - !(n % 2), r = n / 2 - !(n % 2);
    ans[m++] = a[l];
    bool z = true;
    while (1)
    {
        if (l == 0 && r == n - 1)
            break;
        if (z)
        {
            ++r;
            ans[m++] = a[r];
        }
        else
        {
            --l;
            ans[m++] = a[l];
        }
        z ^= true;
    }
    printf("%s\n", ans);
    return 0;
}