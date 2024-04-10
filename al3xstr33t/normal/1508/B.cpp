#include<bits/stdc++.h>

using namespace std;

const int maxN = 1000009;
int N;
long long K, p2[maxN];
const long long INF = 1LL << 60;

long long add (long long a, long long b) {if (a >= INF - b) return INF; return a + b;}

void solve (int lft, int rgt, long long K)
{
    if (lft > rgt) return ;
    long long cnt = 0;
    for (int i=lft; i<=rgt; i++)
    {
        long long oldCnt = cnt;
        cnt = add (cnt, p2[max (rgt - i - 1, 0)]);
        if (cnt >= K)
        {
            cnt = oldCnt;
            K -= cnt;
            for (int j=i; j>=lft; j--)
                printf ("%d ", j);
            solve (i + 1, rgt, K);
            break;
        }
    }
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

int tests;
scanf ("%d", &tests);
while (tests --)
{
    scanf ("%d %I64d", &N, &K);
    p2[0] = 1;
    for (int i=1; i<=N; i++)
        p2[i] = add (p2[i - 1], p2[i - 1]);
    if (K > p2[N - 1]) printf ("-1\n");
    else
    {
        solve (1, N, K);
        printf ("\n");
    }
}

return 0;
}