#include<bits/stdc++.h>

using namespace std;

int f[1009];
long long K;
const string s = "codeforces";
const int L = s.length ();
const long long INF = 1LL << 60;

long long mul (long long a, long long b)
{
    if (a == 0 || b == 0)
        return 0;
    if (a > INF / b)
        return INF;
    return 1LL * a * b;
}

long long getMax (int extra)
{
    int c = extra / L;
    long long curr = 1;
    for (int i=1; i<=L; i++)
        f[i] = 1 + c + (extra % L >= i),
        curr = mul (curr, f[i]);
    return curr;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%lld", &K);
int extra = 0;
while (1)
{
    long long ma = getMax (extra);
    if (ma >= K)
        break;
    extra ++;
}
for (int i=1; i<=L; i++)
    for (int j=1; j<=f[i]; j++)
        printf ("%c", s[i - 1]);
printf ("\n");
return 0;
}