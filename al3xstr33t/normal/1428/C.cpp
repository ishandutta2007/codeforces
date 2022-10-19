#include<bits/stdc++.h>

using namespace std;

const int maxN = 200009;
int N;
char sir[maxN];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

int tests;
scanf ("%d\n", &tests);
while (tests --)
{
    scanf ("%s\n", sir + 1), N = strlen (sir + 1);
    int cntA = 0, cntB = 0;
    for (int i=1; i<=N; i++)
    {
        if (sir[i] == 'A') cntA ++;
        else
        if (sir[i] == 'B' && cntA > 0) cntA --;
        else cntB ++;
    }
    cntB &= 1;
    printf ("%d\n", cntA + cntB);
}

return 0;
}