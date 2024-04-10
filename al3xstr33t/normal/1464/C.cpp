#include<bits/stdc++.h>

using namespace std;

const int maxN = 100009;
int N, l[100], r[100];
char s[maxN];
long long T;

void fail ()
{
    printf ("No\n");
    exit (0);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %I64d\n", &N, &T);
scanf ("%s", s + 1);
for (int i=1; i<=N; i++)
    s[i] -= 'a';
T -= 1LL << s[N];
T += 1LL << s[N - 1];
for (int i=1; i<=N - 2; i++)
    T += 1LL << s[i],
    r[s[i] + 1] ++;
for (int i=0; i<62; i++)

if (T < 0)
    fail ();
for (int i=0; i<62; i++)
{
    if (r[i] > 2)
    {
        if (r[i] % 2 == 1)
            r[i + 1] += r[i] / 2,
            r[i] = 1;
        else
            r[i + 1] += r[i] / 2 - 1,
            r[i] = 2;
    }
    int bit = ((T & (1LL << i)) > 0);
    if (bit)
    {
        if (r[i] == 0)
            fail ();
    }
    else
    {
        if (r[i] == 2)
            r[i + 1] ++;
    }
}
printf ("Yes\n");
return 0;
}