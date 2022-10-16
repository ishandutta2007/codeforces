#include<cstdio>
#include<bitset>
#include<vector>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<map>
#include<set>
#include<queue>
#include<algorithm>

using namespace std;

int N, nr, P, X[10009], st[10009], dr[10009];
long long INF, dp[2][10009];
vector < int > v;
map < int , int > mp;

void baga (int x)
{
    v.push_back (x);
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &P), baga (P), INF = 1LL<<50;
for (int i=1; i<=N; i++)
    scanf ("%d %d", &st[i], &dr[i]), baga (st[i]), baga (dr[i]);
sort (v.begin (), v.end ());
v.resize(unique(v.begin(), v.end()) - v.begin());
for (vector < int > :: iterator it = v.begin (); it != v.end (); it ++)
    mp[*it] = ++nr, X[nr] = *it;
/*for (int i=1; i<=nr; i++)
    printf ("%d ", X[i]);
printf ("\n");*/
P = mp[P];
for (int i=1; i<=N; i++)
    st[i] = mp[st[i]], dr[i] = mp[dr[i]];
for (int i=1; i<=nr; i++)
    dp[0][i] = INF;
dp[0][P] = 0;
for (int i=1; i<=N; i++)
{
   // if (i == 3)
     //   i = 3;
    long long mini = INF;
    for (int j=1; j<=nr; j++)
    {
       // if (j == nr)
         //   j = nr;
        if (dp[(i&1) ^ 1][j] - X[j] < mini)
            mini = dp[(i&1) ^ 1][j] - X[j];
        int cost = 0;
        if (X[j] < X[st[i]]) cost = X[st[i]] - X[j];
        else
        if (X[j] > X[dr[i]]) cost = X[j] - X[dr[i]];
        dp[i&1][j] = mini + cost + X[j];
    }
    mini = INF;
    for (int j=nr; j>=1; j--)
    {
        if (dp[(i&1) ^ 1][j] + X[j] < mini)
            mini = dp[(i&1) ^ 1][j] + X[j];
        int cost = 0;
        if (X[j] < X[st[i]]) cost = X[st[i]] - X[j];
        else
        if (X[j] > X[dr[i]]) cost = X[j] - X[dr[i]];
        if (mini + cost - X[j] < dp[i&1][j])
            dp[i&1][j] = mini + cost - X[j];
    }
/*    for (int j=1; j<=nr; j++)
        printf ("%3I64d ", dp[i&1][j]);
    printf ("\n");*/
}
long long best = INF;
for (int i=1; i<=nr; i++)
    if (dp[N&1][i] < best)
        best = dp[N&1][i];
printf ("%I64d\n", best);
return 0;
}