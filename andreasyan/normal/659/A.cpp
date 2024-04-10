#include <bits/stdc++.h>
using namespace std;
 
int n, a, b;
 
int main()
{
    scanf("%d%d%d", &n, &a, &b);
    --a;
    a += b;
    while (a < 0)
        a += n;
    a %= n;
    ++a;
    printf("%d\n", a);
    return 0;
}