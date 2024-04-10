#include<bits/stdc++.h>
using namespace std;
const int MAXN = 524288;
int idx[2*MAXN];


void setv(int a, int v)
{
    a += MAXN;
    idx[a] = v;
    while(a = a/2)
    {
        idx[a] = __gcd(idx[2*a], idx[2*a+1]);
    }
}
int l, r, v;
void inv(int i, int s, int e, int &cnt)
{
    if( e<l || r<s) return;
    int m = (s+e)/2;
    if(e-s==0)
    {
        if(idx[i]%v!=0) ++cnt;
        return;
    }
    if(l<=s && e <= r)
    {
        if(idx[i] % v == 0) return;
        bool L = (idx[2*i] % v != 0);
        bool R = (idx[2*i+1] % v != 0);
        if(L&&R)
        {
            cnt = 2; return;
        }
        if(L) inv(2*i, s, m, cnt);
        else inv(2*i+1, m+1, e, cnt);
        return;
    }
    inv(2*i, s, m, cnt);
    if(cnt>=2) return;
    inv(2*i+1, m+1, e, cnt);
    if(cnt>=2) return;
}

int main()
{
    int N; scanf("%d", &N);
    for(int i=0; i<N; ++i)
    {
        int v; scanf("%d", &v);
        setv(i, v);
    }
    int Q;
    scanf("%d", &Q);
    for(int i=0; i<Q; ++i)
    {
        int t; scanf("%d", &t);
        if(t==1)
        {
            scanf("%d%d%d", &l, &r, &v);
            l--; r--;
            int x = 0; inv(1, 0, MAXN-1, x);
            if(x<=1) puts("YES");
            else puts("NO");
        }
        else
        {
            int a, y; scanf("%d%d", &a, &y); --a;
            setv(a, y);
        }
    }
    return 0;
}