#include<bits/stdc++.h>

using namespace std;

const int maxN = 200009;
int N, ans[maxN];
vector < int > v[maxN];

void dfs (int nod, int tata, int parity)
{
    ans[nod] = parity * ((int) v[nod].size());
    for (auto it : v[nod])
        if (it != tata)
            dfs (it, nod, -parity);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

int tests, testId = 0;
scanf ("%d", &tests);
while (tests --)
{
    scanf ("%d", &N);
    for (int i=1; i<N; i++)
    {
        int x, y;
        scanf ("%d %d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs (1, -1, -1);
    for (int i=1; i<=N; i++)
        printf ("%d%c", ans[i], " \n"[i == N]), v[i].clear ();
}

return 0;
}

/*
const int seed = time (0);
mt19937 gen (seed);
long long getRand(long long a, long long b) {return uniform_int_distribution < long long > (a, b) (gen);}
*/