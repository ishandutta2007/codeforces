#include<bits/stdc++.h>

using namespace std;

const int maxN = 1000;
int N;
char s[maxN][maxN];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

int tests;
scanf ("%d", &tests);
while (tests --)
{
    scanf ("%d\n", &N);
    int f[3] = {0, 0, 0};
    for (int i=1; i<=N; i++)
        scanf ("%s\n", s[i] + 1);
    for (int i=1; i<=N; i++)
        for (int j=1; j<=N; j++)
            if (s[i][j] == 'X')
                f[(i + j) % 3] ++;
    int dl = 0;
    if (f[1] < f[dl])
        dl = 1;
    if (f[2] < f[dl])
        dl = 2;
    for (int i=1; i<=N; i++, printf ("\n"))
        for (int j=1; j<=N; j++)
        {
            if (s[i][j] == 'X' && (i + j) % 3 == dl)
                s[i][j] = 'O';
            printf ("%c", s[i][j]);
        }
}
return 0;
}