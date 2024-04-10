#include<bits/stdc++.h>

using namespace std;

int N, M, ans[609][609], dst[609], which[609], cnt[609][609], d[609][609], ap[609];
bool unq[609][609];
vector < int > v[609];
vector < int > prv[609][609];
const int mod = 998244353;

int add (int x, int y) {int ans = x + y; if (ans >= mod) ans -= mod; return ans;}
int subtract (int x, int y) {if (x >= y) return x - y; return x - y + mod;}
int mul (int x, int y) {return 1LL * x * y % mod;}
void adto (int &x, int y) {x += y; if (x >= mod) x -= mod;}

int power (int a, int b)
{
    int p = 1;
    for (int i=0; (1<<i) <= b; i++)
    {
        if (b & (1 << i)) p = mul (p, a);
        a = mul (a, a);
    }
    return p;
}

int fac[2000009], inv[2000009];
void Prec (int lim){fac[0] = inv[0] = 1;for (int i=1; i<=lim; i++)fac[i] = mul (fac[i - 1], i);
inv[lim] = power (fac[lim], mod - 2);for (int i=lim - 1; i>=0; i--)inv[i] = mul (inv[i + 1], i + 1);}
int comb (int N, int K){if (K > N || N < 0 || K < 0) return 0; int ans = mul (fac[N], inv[N - K]);ans = mul (ans, inv[K]);return ans;}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);
for (int i=1; i<=N; i++)
    for (int j=1; j<=N; j++)
        d[i][j] = (i == j ? 0 : 2 * N + 1), unq[i][j] = 1;
for (int i=1; i<=M; i++)
{
    int x, y;
    scanf ("%d %d", &x, &y);
    v[x].push_back (y);
    v[y].push_back (x);
    d[x][y] = d[y][x] = 1;
}
for (int k=1; k<=N; k++)
    for (int i=1; i<=N; i++)
        for (int j=1; j<=N; j++)
            d[i][j] = min (d[i][j], d[i][k] + d[k][j]);
for (int i=1; i<=N; i++)
{
    pair < int, int > h[N + 2];
    for (int j=1; j<=N; j++)
        h[j] = {d[i][j], j};
    sort (h + 1, h + N + 1);
    cnt[i][i] = 1, unq[i][i] = 1;
    for (int jj=2; jj<=N; jj++)
    {
        int j = h[jj].second;
        for (auto k : v[j])
            if (d[i][k] + 1 == d[i][j])
                unq[i][j] &= unq[i][k],
                prv[i][j].push_back (k);
        if (prv[i][j].size () > 1) unq[i][j] = 0;
    }
}
for (int i=1; i<=N; i++, printf ("\n"))
    for (int j=1; j<=N; j++)
    {
        if (i <= j)
        {
            if (!unq[i][j])
                ans[i][j] = 0;
            else
            {
                vector < int > path;
                int p = j;
                while (p != i)
                    path.push_back (p),
                    p = prv[i][p][0];
                path.push_back (i);
                for (int k=1; k<=N; k++)
                    dst[k] = 2 * N + 1;
                queue < int > cc;
                for (auto k : path)
                    dst[k] = 0, which[k] = k, cc.push (k);
                bool ok = 1;
                while (!cc.empty () && ok)
                {
                    int nod = cc.front ();
                    cc.pop ();
                    for (auto it : v[nod])
                        if (dst[it] > N)
                        {
                            dst[it] = dst[nod] + 1;
                            which[it] = which[nod];
                            cc.push (it);
                        }
                        else
                        if (dst[it] == dst[nod] + 1 && which[it] != which[nod])
                        {
                            ok = 0;
                            break;
                        }
                }
                if (!ok) ans[i][j] = 0;
                else
                {
                    ans[i][j] = 1;
                    for (int k=1; k<=N; k++)
                        if (which[k] != k)
                        {
                            if (d[i][k] != d[which[k]][k] + d[i][which[k]] || d[j][k] != d[which[k]][k] + d[j][which[k]])
                            {
                                ans[i][j] = 0;
                                break;
                            }
                            ans[i][j] = mul (ans[i][j], prv[which[k]][k].size ());
                        }
                }
            }
        }
        else ans[i][j] = ans[j][i];
        printf ("%d ", ans[i][j]);
    }
return 0;
}