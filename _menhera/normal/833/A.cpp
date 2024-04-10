#include<bits/stdc++.h>
using namespace std;
long long x(long long a)
{
    long long lo = 0;
    long long hi = 1e6+10;
    while(lo+1!=hi)
    {
        long long mi = (lo+hi)/2;
        if(mi*mi*mi <= a) lo = mi;
        else hi = mi;
    }
    return lo;
}
bool solve(int u, int v)
{
    long long uv = 1LL*u*v;
    long long res = x(uv);
    if(res*res*res!=uv) return false;
    if(u%res !=0) return false;
    if(v%res!=0) return false;
    u /= res; v/= res;
    if(res % u !=0) return false;
    if(res % v !=0) return false;
    return true;
}
int main()
{
    int N;
    scanf("%d", &N);
    for(int i=0; i<N; ++i)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        if(solve(u, v)) puts("Yes");
        else puts("No");
    }
}