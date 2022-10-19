#include<bits/stdc++.h>

using namespace std;

vector < int > performMove (vector < int > v, int k)
{
    if ((k > 0 && v[k] > v[k - 1]) || (k + 1 < v.size () && v[k] < v[k + 1]))
    {
        vector < int > v2;
        for (auto j : v)
            if (j > v[k]) v2.push_back (j - 1);
            else
            if (j < v[k]) v2.push_back (j);
        return v2;
    }
    return {-1};
}

map < vector < int >, bool > dp;

int getInversions (vector < int > v)
{
    int inv = 0;
    for (int i=0; i<v.size (); i++)
        for (int j=i + 1; j<v.size (); j++)
            inv += (v[i] > v[j]);
    return inv;
}

void printVector (vector < int > v, string s)
{
    bool needSpace = 0;
    for (auto j : v)
    {
        if (needSpace)
            printf (" ");
        printf ("%d", j), needSpace = 1;
    }
    //printf ("--%d", getInversions (v));
    printf ("%s", s.c_str ());
}

bool solve (vector < int > v)
{
    if (v.size () == 1)
        dp[v] = 1;
    if (dp.count (v))
        return dp[v];
    dp[v] = 0;
    for (int i=0; i<v.size (); i++)
    {
        auto v2 = performMove (v, i);
        if (v2.size () == 1 && v2[0] == -1)
            continue;
        if (solve (v2))
        {
            dp[v] = 1;
            //printVector (v, " due to "), printVector (v2, "\n");
            break;
        }
    }
    assert (dp[v] == (v[0] < v[v.size () - 1]));
    return dp[v];
}

/*bool smartSolve (vector < int > v)
{
    int bg = v[0], l = 0;
    vector < pair < int, int > > v3;
    for (auto it : v)
        if (it >= bg)
            v3.push_back ({it, l}),
            l ++;
    vector < int > v2;
    sort (v3.begin (), v3.end ());
    for (auto it : v3)

}*/

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

/*for (int l=1; l<=6; l++)
{
    vector < int > v (l);
    for (int i=0; i<l; i++)
        v[i] = i + 1;
    int cnt = 0;
    do {
        if (solve (v))
            //printVector (v, "\n"),
            cnt ++;
        //else
          //  printf ("%d\n", getInversions (v));
    }while (next_permutation (v.begin (), v.end ()));
    printf ("%d -> %d\n", l, cnt);
}*/

int tests, N;
scanf ("%d", &tests);
while (tests --)
{
    scanf ("%d", &N);
    int x = -1, y = -1;
    for (int i=1; i<=N; i++)
    {
        int z;
        scanf ("%d", &z);
        if (i == 1) x = z;
        else y = z;
    }
    if (x < y) printf ("YES\n");
    else printf ("NO\n");
}

return 0;
}