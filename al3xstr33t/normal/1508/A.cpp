#include<bits/stdc++.h>

using namespace std;

const int maxN = 1000009;
int N;
char s[3][maxN];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

int tests;
scanf ("%d", &tests);
while (tests --)
{
    scanf ("%d\n", &N);
    int maj[3];
    for (int i=0; i<3; i++)
    {
        scanf ("%s", s[i]);
        maj[i] = 0;
        for (int j=0; j<2 * N; j++)
            maj[i] += (s[i][j] - '0');
        maj[i] = (maj[i] >= N);
    }
    int p = 0, q = 0;
    for (int i=0; i<3; i++)
        for (int j=i + 1; j<3; j++)
            if (maj[i] == maj[j])
                p = i, q = j;
    assert (p + q > 0);
    int i = 0, j = 0;
    char c = maj[p] + 48;
    while (i < 2 * N || j < 2 * N)
    {
        if (i < 2 * N && s[p][i] != c) printf ("%c", s[p][i]), i ++;
        else
        if (j < 2 * N && s[q][j] != c) printf ("%c", s[q][j]), j ++;
        else
        {
            printf ("%c", c);
            i ++, j ++;
        }
    }
    printf ("\n");
}

return 0;
}