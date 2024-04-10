#include<bits/stdc++.h>

using namespace std;

const int maxN = 500009;
//const int maxN = 50;
int nr, N, l[2 * maxN], prv[2 * maxN], nxt[2 * maxN];
char sir[maxN];
long long ans;
vector < int > v[maxN];

long long segms (int N)
{
    return 1LL * N * (N + 1) / 2;
}

long long sumSegms = 0, sumDs = 0, cntDs = 0;
void add (int d, int sg = +1)
{
    assert (d > 0);
    sumSegms += 1LL * sg * segms (d);
    sumDs += 1LL * sg * d;
    cntDs += sg;
}

void del (int d)
{
    add (d, -1);
}

long long cntBetween (int l)
{
    ///sum by d of 2(l-1)*d + (l-1)^2 + segms(d)
    return 2LL * (l - 1) * sumDs + 1LL * (l - 1) * (l - 1) * cntDs + sumSegms;
}

long long sumOnes = 0, nrOnes = 0;
void addOnes (int cnt1, int sg = +1)
{
    sumOnes += 1LL * sg * cnt1;
    nrOnes += sg;
}

void delOnes (int cnt1)
{
    addOnes (cnt1, -1);
}

long long cntEnd (int d, int l)
{
    return segms (d) + 1LL * d * (l - 1);
}

long long cntOnes (int l)
{
    l -= 2; ///sum by L in ones of #(i, j) 1<=i<=j<=L with j-i<=l
    if (l < 0)
        return 0;
    ///sum of (l + 1) * (L - l) + segms (l)
    return 1LL * nrOnes * (segms (l) - 1LL * l * (l + 1)) + 1LL * sumOnes * (l + 1);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d\n", &N);
scanf ("%s", sir + 1);
for (int i=1; i<=N; i++)
{
    int j = i;
    while (j < N && sir[j + 1] == sir[i])
        j ++;
    if (sir[i] == '1' && nr == 0)
        nr = 1, l[nr] = 0;
    l[++nr] = j - i + 1;
    i = j;
}
if (nr % 2 == 0)
    l[++nr] = 0;
for (int i=1; i<nr; i++)
    nxt[i] = i + 1,
    prv[i + 1] = i;
for (int i=2; i<=nr; i+=2)
    v[l[i]].push_back (i),
    addOnes (l[i]);
for (int i=3; i<nr; i+=2)
    add (l[i]);
int fst = 1, lst = nr;
for (int currL = 1; currL <= N; currL ++)
{
    ///currently split by >= currL
    if (fst == lst)
    {
        assert (l[fst] == N && fst == 1);
        ///nobody has >= currL
        break;
    }
    long long curr = segms (N) - cntEnd (l[fst], currL) - cntEnd (l[lst], currL) - cntOnes (currL) - cntBetween (currL);
    ans += curr;
    for (auto i : v[currL])
    {
        int j = prv[i], k = nxt[i]; ///merge into j
        delOnes (l[i]);
        if (prv[j] > 0)
            del (l[j]);
        if (nxt[k] > 0)
            del (l[k]); ///not last
        nxt[j] = nxt[k];
        if (nxt[j] > 0)
            prv[nxt[j]] = j;
        else
            lst = j;
        l[j] += l[i] + l[k];
        if (prv[j] > 0 && nxt[j] > 0) add (l[j]);
    }
}
printf ("%lld\n", ans);
return 0;
}