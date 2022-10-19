#include<bits/stdc++.h>

using namespace std;

const int maxN = 1e6 + 100;
int N, x[maxN], y[maxN];
char s[maxN];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

int tests;
scanf ("%d\n", &tests);
while (tests --)
{
    scanf ("%d\n%s\n", &N, s + 1);
    bool ok = 1;
    int cnt = 0, cnt2 = 0;
    for (int i=1; i<=N; i++)
        if (s[i] == '0')
            cnt ++;
        else
            cnt2 ++;
    if (cnt % 2 == 1 || cnt2 % 2 == 1)
    {
        printf ("NO\n");
        continue;
    }
    else
    {
        int a = 0, b = 0, pos = 0;
        for (int i=1; i<=N; i++)
        {
            if (s[i] == '0')
            {
                cnt --;
                if (cnt & 1) x[i] = +1, y[i] = -1;
                else x[i] = -1, y[i] = +1;
            }
            else
            {
                pos ++;
                if (pos <= cnt2 / 2) x[i] = y[i] = +1;
                else x[i] = y[i] = -1;
            }
            a += x[i], b += y[i];
            if (a < 0 || b < 0)
                ok = 0;
        }
        if (a != 0 || b != 0)
            ok = 0;
        if (!ok) printf ("NO\n");
        else
        {
            printf ("YES\n");
            for (int i=1; i<=N; i++)
                if (x[i] > 0) printf ("(");
                else printf (")");
            printf ("\n");
            for (int i=1; i<=N; i++)
                if (y[i] > 0) printf ("(");
                else printf (")");
            printf ("\n");
        }
    }
}
return 0;
}