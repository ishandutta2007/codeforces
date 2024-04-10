#include<bits/stdc++.h>

using namespace std;

int tests, N, a[1009], ap[1009];

int getMex ()
{
    int ans = 0;
    while (ap[ans] > 0)
        ans ++;
    return ans;
}

vector < int > moves;
void perform (int i)
{
    int k = getMex (); moves.push_back (i);
    ap[a[i]] --, a[i] = k, ap[k] ++;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

int tests;
scanf ("%d", &tests);
while (tests --)
{
    scanf ("%d", &N);
    for (int i=1; i<=N; i++)
        scanf ("%d", &a[i]), ap[a[i]] ++;
    moves.clear ();
    while (1)
    {
        int k = getMex ();
        if (k == N)
        {
            bool ok = 0;
            for (int i=1; i<=N; i++)
                if (a[i] != i - 1)
                {
                    perform (i);
                    ok = 1;
                    break;
                }
            if (!ok)
                break;
            continue;
        }
        perform (k + 1);
    }
    for (int i=2; i<=N; i++)
        assert (a[i - 1] <= a[i]);
    printf ("%d\n", moves.size ());
    for (auto i : moves)
        printf ("%d ", i);
    printf ("\n");
    for (int i=0; i<=N; i++)
        ap[i] = 0;
}

return 0;
}