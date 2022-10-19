#include<bits/stdc++.h>

using namespace std;

const int maxN = 500009;
int nr, N, M, sz[maxN],a[maxN], b[maxN], cntFull[maxN], ap[maxN], pos[maxN], where[2 * maxN];
long long K;

int cnt (int val, int lin, int l, int r)
{
    ///return number of values != val on lin between positions l and r
    int ans = r - l + 1, j = where[val];
    if (j != -1 && ap[j] == lin)
        ans -= (l <= pos[j] && pos[j] <= r);
    return ans;
}

long long mismatches (long long t)
{
    long long ans = 0;
    for (int i=0; i<N; i++)
    if (t >= i)
    {
        int lin = ap[i % M], linSize = sz[lin], pos0 = pos[i % M];
        long long f = (t - i) / N + 1;
        ///cycle f times around v[lin]
        ans += 1LL * cntFull[i] * (f / linSize);
        long long r = f % linSize;
        if (r > 0)
        {
            if (pos0 + r - 1 < linSize)
                ans += cnt (a[i], lin, pos0, pos0 + r - 1);
            else
                ans += cntFull[i] - cnt (a[i], lin, (pos0 + r) % linSize, pos0 - 1);
        }
    }
    return ans;
}

void Read (int &x);
void Read (long long &x);

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

Read (N), Read (M), Read (K);
for (int i=0; i<N; i++)
    Read (a[i]), where[a[i]] = -1;
for (int i=0; i<M; i++)
    Read (b[i]);
for (int i=0; i<M; i++)
    where[b[i]] = i;
for (int i=0; i<M; i++)
    if (ap[i] == 0)
    {
        ap[i] = ++nr;
        pos[i] = 0, sz[nr] = 1;
        int j = i;
        while (1)
        {
            j = (j + N) % M;
            if (ap[j] != 0)
                break;
            ap[j] = nr;
            pos[j] = sz[nr];
            sz[nr] ++;
        }
    }
for (int i=0; i<N; i++)
    cntFull[i] = cnt (a[i], ap[i % M], 0, sz[ap[i % M]] - 1);
/*printf ("%I64d\n", mismatches (0));
int currBrute = 0;
for (int r=0; r<=10000; r ++)
{
    currBrute += (a[r % N] != b[r % M]);
    if (currBrute != mismatches (r))
    {
        printf ("WA t=%d, %I64d instead of %d\n", r, mismatches (r), currBrute);
        return 0;
    }
}*/
long long p = max (0LL, K - 1), u = 1LL << 60, mid, ans = -1;
while (p <= u)
{
    mid = p + (u - p) / 2LL;
    long long curr = mismatches (mid);
    if (curr >= K) ans = mid, u = mid - max (1LL, curr - K);
    else p = mid + K - curr;
}
printf ("%I64d\n", ans + 1);
return 0;
}

#define maxl 100000
int pppos = maxl - 1;
char sir[maxl];

void Next ()
{
    if (++pppos == maxl)
        fread (sir, 1, maxl, stdin), pppos = 0;
}

void Read (int &x)
{
    while (sir[pppos] < '0' || sir[pppos] > '9') Next ();
    for (x = 0; sir[pppos] >= '0' && sir[pppos] <= '9'; Next ()) x = x * 10 + sir[pppos] - '0';
}

void Read (long long &x)
{
    while (sir[pppos] < '0' || sir[pppos] > '9') Next ();
    for (x = 0; sir[pppos] >= '0' && sir[pppos] <= '9'; Next ()) x = 1LL * x * 10 + sir[pppos] - '0';
}