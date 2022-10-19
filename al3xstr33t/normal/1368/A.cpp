#include<bits/stdc++.h>

using namespace std;

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

int tests;
scanf ("%d", &tests);
while (tests --)
{
    long long a, b, n;
    scanf ("%I64d %I64d %I64d", &a, &b, &n);
    int steps = 0;
    while (a <= n && b <= n)
    {
        steps ++;
        if (a < b) a += b;
        else b += a;
    }
    printf ("%d\n", steps);
}
return 0;
}