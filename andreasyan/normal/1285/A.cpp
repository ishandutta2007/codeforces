#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n;
char a[N];

int l, r;

int main()
{
    scanf("%d", &n);
    scanf(" %s", a);
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == 'L')
            --l;
        else
            ++r;
    }
    printf("%d\n", r - l + 1);
    return 0;
}