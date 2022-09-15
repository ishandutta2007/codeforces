#include <bits/stdc++.h>
using namespace std;

const int MAXN = 262144, MAXM = 303030, MAXQ = 505050;

int ufd[MAXN+1];
void Init(int N){for(int i=1; i<=N; ++i) ufd[i]=i;}
int Find(int a){if(a==ufd[a]) return a; return ufd[a] = Find(ufd[a]);}
void Union(int a, int b){ ufd[Find(a)] = Find(b);}

int N, M, Q;
int p[MAXN+1];

int a[MAXM+1], b[MAXM+1]; bool f[MAXM+1]; //no edge deletion flag
int t[MAXQ+1], v[MAXQ+1], nodeind[MAXQ+1];

// -1, v => v
int nodeL[2*MAXN], nodeR[2*MAXN], Lran[2*MAXN], Rran[2*MAXN];
int curnode[MAXN+1];

int dfscur = 0;
void dfs(int q)
{
    Lran[q] = dfscur;
    if(nodeL[q] == -1)
        ++dfscur;
    else
        dfs(nodeL[q]), dfs(nodeR[q]);
    Rran[q] = dfscur-1;
}

int arr[MAXN];
int idx[2*MAXN];
int getv(int a, int b)
{
    int maxi = -1;
    a += MAXN; b += MAXN;
    while(a<=b)
    {
        if(a%2==1)
        {
            if(maxi==-1 || arr[maxi] < arr[idx[a]]) maxi = idx[a];
            ++a;
        }
        if(b%2==0)
        {
            if(maxi==-1 || arr[maxi] < arr[idx[b]]) maxi = idx[b];
            --b;
        }
        a/=2; b/=2;
    }
    return maxi;
}

void setv(int a, int v)
{
    arr[a] = v;
    a += MAXN;
    while((a=a/2))
    {
        if(arr[idx[2*a]]>arr[idx[2*a+1]])
            idx[a] = idx[2*a];
        else
            idx[a] = idx[2*a+1];
    }
}

void initseg(int N)
{
    for(int i=1; i<=N; ++i) idx[i+MAXN] = i;
    for(int i=MAXN-1; i>=1; --i) idx[i] = idx[2*i];
}

int main()
{
    scanf("%d%d%d", &N, &M, &Q);
    for(int i=1; i<=N; ++i) scanf("%d", p+i);
    for(int i=1; i<=M; ++i) scanf("%d%d", a+i, b+i);
    for(int i=1; i<=Q; ++i)
    {
        scanf("%d%d", t+i, v+i);
        if(t[i] == 2) f[v[i]] = 1;
    }
    Init(N);
    for(int i=1; i<=N; ++i)
        nodeL[i] = -1, nodeR[i] = i, curnode[i] = i;

    int tp = N;
    auto mer = [&](int x, int y)
    {
        if(Find(x)!=Find(y))
        {
            ++tp;
            nodeL[tp] = curnode[Find(x)];
            nodeR[tp] = curnode[Find(y)];
            Union(x, y); int v = Find(x);
            curnode[v] = tp;
        }
    };
    for(int i=1; i<=M; ++i) if(!f[i]) mer(a[i], b[i]);
    for(int i=Q; i>=1; --i)
        if(t[i] == 1) nodeind[i] = curnode[Find(v[i])];
        else mer(a[v[i]], b[v[i]]);
    for(int i=2; i<=N; ++i) mer(1, i);
    dfs(tp);

    initseg(N);
    for(int i=1; i<=N; ++i)
        setv(Lran[i], p[i]);

    for(int i=1; i<=Q; ++i)
    {
        if(t[i] == 1)
        {
            int a = Lran[nodeind[i]], b = Rran[nodeind[i]];
            int idx = getv(a, b);
            //printf("%d %d %d\n", a, b, idx);
            //for(int i=1; i<2*MAXN; ++i) printf("%2d %d\n", i, ::idx[i]);
            printf("%d\n", arr[idx]);
            setv(idx, 0);
        }
    }
}