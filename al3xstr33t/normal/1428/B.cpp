#include<bits/stdc++.h>

using namespace std;

const int maxN = 300009;
int N, ans;
char sir[maxN];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

int tests;
scanf ("%d", &tests);
while (tests --)
{
    scanf ("%d\n%s", &N, sir + 1);
    int toLeft = 1, toRight = 1;
    for (int i=1; i<=N; i++)
        toLeft &= (sir[i] != '<'),
        toRight &= (sir[i] != '>');
    if (toLeft || toRight)
        printf ("%d\n", N);
    else
    {
        int ans = 0;
        sir[N + 1] = sir[1], sir[0] = sir[N];
        for (int i=1; i<=N; i++)
            ans += (sir[i] == '-' || sir[i - 1] == '-');
        printf ("%d\n", ans);
    }
}

return 0;
}