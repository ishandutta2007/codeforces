#include<bits/stdc++.h>

using namespace std;

const int maxN = 100009;
int x, y, N, nr, initSz;
long long coefs[maxN], init;
char s[maxN];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%s\n", s + 1);
scanf ("%d %d", &x, &y);
N = strlen (s + 1);
for (int i=1; i<=N; i++)
{
    long long coef = 1LL * x * (i - 1) + 1LL * (N - i) * y;
    if (s[i] == '1') init += coef, initSz ++;
    else
    if (s[i] == '?')
        coefs[++nr] = coef;
}
long long ans = 0;
sort (coefs + 1, coefs + nr + 1);
for (int i=0; i<=nr; i++)
{
    int sz = i + initSz;
    if (i > 0)
        init += coefs[i];
    long long curr = init - 1LL * (x + y) * sz * (sz - 1) / 2;
    if (curr < ans || i == 0)
        ans = curr;
}
printf ("%I64d\n", ans);

return 0;
}