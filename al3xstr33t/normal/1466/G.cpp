#include<bits/stdc++.h>

using namespace std;

const int maxN = 100009, maxM = 109, maxQ = 1000009, maxL = (1 << 23) + 10, sigma = 27;
int L, Q, N, M, phi[maxL], p2[maxN], ip2[maxN], s[maxN][sigma], lg[maxQ];
char pat[maxL], s0[maxM], q[maxQ], t[maxN], v[maxQ];
const int mod = 1e9 + 7;

int add (int x, int y) {int ans = x + y; if (ans >= mod) ans -= mod; return ans;}
int subtract (int x, int y) {if (x >= y) return x - y; return x - y + mod;}
int mul (int x, int y) {return 1LL * x * y % mod;}
void adto (int &x, int y) {x += y; if (x >= mod) x -= mod;}

void build (int lev)
{
    if (lev == 0) return ;
    build (lev - 1);
    pat[++L] = t[lev];
    build (lev - 1);
}

void buildPhi ()
{
    int k = 0;
    for (int i=2; i<=L; i++)
    {
        while (k != 0 && pat[k + 1] != pat[i])
            k = phi[k];
        if (pat[k + 1] == pat[i])
            k ++;
        phi[i] = k;
    }
}

void consume (int &k, char c)
{
    while (k != 0 && pat[k + 1] != c)
        k = phi[k];
    if (pat[k + 1] == c)
        k ++;
}

bool good[maxQ];
int compute (int P, int nr)
{
    for (int i=0; i<=nr + 1; i++)
        good[i] = 0;
    int k = 0, ans = 0;
    for (int i=1; i<=nr; i++)
        consume (k, v[i]);
    while (1)
    {
        good[nr - k] = 1;
        if (k == 0)
            break;
        k = phi[k];
    }
    k = 0;
    for (int i=nr; i>=1; i--)
        consume (k, v[i]);
    while (1)
    {
        ///k + 1 is also good
        if (good[k + 1])
        {
            ///sum over i >= something: t[i] == v[k + 1] ? += p2[P - i]
            ///2^i-1 >= max (k, nr-k-1) => 2^i >= max(k+1, nr-k)
            int minI = lg[max (k + 1, nr - k)] + 1;
            if (minI <= P)
                adto (ans, subtract (s[P][v[k + 1]], s[minI - 1][v[k + 1]]));
        }
        if (k == 0)
            break;
        k = phi[k];
    }
    ans = mul (ans, p2[P]);
    return ans;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d\n", &N, &Q);
scanf ("%s\n", s0 + 1), M = strlen (s0 + 1);
scanf ("%s", t + 1);
for (int i=1; i<=N; i++)
    t[i] -= 'a';
build (min (N, 20));
buildPhi ();
p2[0] = 1;
for (int i=1; i<=N + 1; i++)
    p2[i] = add (p2[i - 1], p2[i - 1]);
ip2[0] = 1;
for (int i=1; i<=N + 1; i++)
{
    ip2[i] = ip2[i - 1];
    if (ip2[i] & 1)
        ip2[i] += mod;
    ip2[i] >>= 1;
}
for (int i=1; i<=N; i++)
{
    for (int j=0; j<26; j++)
        s[i][j] = s[i - 1][j];
    adto (s[i][t[i]], ip2[i]);
}
for (int i=1; i<=maxQ - 2; i++)
{
    lg[i] = lg[i - 1];
    if ((1 << lg[i]) < i)
        lg[i] ++;
}
while (Q --)
{
    int P, K;
    scanf ("%d %s\n", &P, q + 1);
    K = strlen (q + 1);
    int ans = 0;
    for (int i=1; i<=M + 1; i++)
    {
        ///assume I start on s0[i] (i = M + 1 means I start on some t)
        bool ok = 1;
        int nr = 0;
        for (int j=1, pos=i; j<=K; j++, pos = (pos == M + 1 ? 1 : pos + 1))
        {
            if (pos == M + 1) v[++nr] = q[j] - 'a';
            else
            if (q[j] != s0[pos])
            {
                ok = 0;
                break;
            }
        }
        if (!ok) continue;
        if (nr == 0)
        {
            adto (ans, p2[P]);///completely included in a s0
            continue;
        }
        adto (ans, compute (P, nr));
    }
    printf ("%d\n", ans);
}
return 0;
}