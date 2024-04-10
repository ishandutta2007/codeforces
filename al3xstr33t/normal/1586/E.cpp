#include<bits/stdc++.h>

using namespace std;

const int maxN = 1e6 + 100;
int N, M, a[maxN], b[maxN], f[maxN], t[maxN], lev[maxN];
vector<int> v[maxN];

void dfs(int nod)
{
    for (auto it : v[nod])
        if (t[it] == 0)
            lev[it] = lev[nod] + 1,
            t[it] = nod,
            dfs(it);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);
while (M --) {
    int x, y;
    scanf ("%d %d", &x, &y);
    v[x].push_back(y);
    v[y].push_back(x);
}
t[1] = -1, dfs(1);
int Q;
scanf ("%d", &Q);
for (int i=1; i<=Q; i++)
    scanf ("%d %d", &a[i], &b[i]), f[a[i]] ++, f[b[i]] ++;
int odd = 0;
for (int i=1; i<=N; i++)
    odd += (f[i] % 2 == 1);
if (odd > 0) printf ("NO\n%d\n", odd / 2);
else {
    printf ("YES\n");
    for (int i=1; i<=Q; i++) {
        int x = a[i], y = b[i];
        vector<int> p1, p2;
        while(x != y) {
            if (lev[x] > lev[y]) p1.push_back(x), x = t[x];
            else p2.push_back(y), y = t[y];
        }
        printf ("%d\n", p1.size () + p2.size() + 1);
        for (auto j : p1)
            printf ("%d ", j);
        printf ("%d", x);
        reverse(p2.begin(), p2.end());
        for (auto j : p2)
            printf(" %d", j);
        printf("\n");
    }
}
return 0;
}

/*
const int seed = time (0);
mt19937 gen (seed);
long long getRand(long long a, long long b) {return uniform_int_distribution < long long > (a, b) (gen);}
*/