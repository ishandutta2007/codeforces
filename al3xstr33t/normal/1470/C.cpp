#include<bits/stdc++.h>

using namespace std;

const int maxN = 300009;
int N, K;
mt19937 rng(666);

int query (int pos)
{
    printf ("? %d\n", pos + 1);
    fflush (stdout);
    int ans;
    scanf ("%d", &ans);
    if (ans < K) return 0;
    if (ans > K) return 2;
    return 1;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

int tests = 1;
while (tests --)
{
    scanf ("%d %d", &N, &K);
    uniform_int_distribution < int > posRng (0, N - 1);
    int step = 1, pos = posRng (rng), ans;
    while (1)
    {
        pos = (pos + step) % N;
        ans = query (pos);
        if (ans != 1)
            break;
        step ++;
    }
    if (ans == 0) step = 1;
    else step = N - 1;
    while (1)
    {
        pos = (pos + step) % N;
        ans = query (pos);
        if (ans == 1)
            break;
    }
    printf ("! %d\n", pos + 1);
    fflush (stdout);
}
return 0;
}