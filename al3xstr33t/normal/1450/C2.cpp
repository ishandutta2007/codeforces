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
    int x[3] = {0, 0, 0};
    int o[3] = {0, 0, 0};
    for (int i=1; i<=N; i++)
        scanf ("%s\n", s[i] + 1);
    int K = 0;
    for (int i=1; i<=N; i++)
        for (int j=1; j<=N; j++)
            if (s[i][j] != '.')
            {
                if (s[i][j] == 'X')
                    x[(i + j) % 3] ++;
                else
                    o[(i + j) % 3] ++;
                K ++;
            }
    bool done = 0;
    for (int needO = 0; needO < 3; needO ++)
    {
        for (int needX = 0; needX < 3; needX ++)
            if (needO != needX && x[needO] + o[needX] <= K / 3)
            {
                for (int i=1; i<=N; i++, printf ("\n"))
                    for (int j=1; j<=N; j++)
                    {
                        if (s[i][j] != '.')
                        {
                            if ((i + j) % 3 == needO) s[i][j] = 'O';
                            if ((i + j) % 3 == needX) s[i][j] = 'X';
                        }
                        printf ("%c", s[i][j]);
                    }
                done = 1;
                break;
            }
        if (done)
            break;
    }
    assert (done);
}
return 0;
}