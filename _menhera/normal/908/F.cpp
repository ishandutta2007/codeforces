#include<bits/stdc++.h>
using namespace std;
vector<long long> Rs;
vector<long long> Bs;
long long C1solve(long long L, long long R)
{
    long long ans = R-L;
    if(Rs.size() != 0)
    {
        long long dv = max(Rs[0] - L, R - Rs[Rs.size()-1]);
        for(int i=0; i<Rs.size()-1; ++i)
            dv = max(dv, Rs[i+1] - Rs[i]);
        ans += R-L-dv;
    }
    if(Bs.size() != 0)
    {
        long long dv = max(Bs[0] - L, R - Bs[Bs.size()-1]);
        for(int i=0; i<Bs.size()-1; ++i)
            dv = max(dv, Bs[i+1] - Bs[i]);
        ans += R-L-dv;
    }
    return ans;
}
long long C2solve(long long L, long long R)
{
    return 2*(R-L);
}
long long solve(long long L, long long R)
{
    long long ans = 0;
    if(L==(long long)(-1e15) && R==(long long)(1e15))
    {
        if(Rs.size() != 0)
            ans += Rs[Rs.size()-1]-Rs[0];
        if(Bs.size() != 0)
            ans += Bs[Bs.size()-1]-Bs[0];
        return ans;
    }
    if(L==(long long)(-1e15))
    {
        if(Rs.size() != 0) ans += R-Rs[0];
        if(Bs.size() != 0) ans += R-Bs[0];
        return ans;
    }
    if(R==(long long)(1e15))
    {
        if(Rs.size() != 0) ans += Rs[Rs.size()-1] - L;
        if(Bs.size() != 0) ans += Bs[Bs.size()-1] - L;
        return ans;
    }
    return min(C1solve(L, R), C2solve(L, R));
}
int main()
{
    int N;
    long long pG = (long long)(-1e15);
    scanf("%d", &N);
    long long ans = 0;
    for(int i=0; i<N; ++i)
    {
        int x; char c;
        scanf("%d %c", &x, &c);
        if(c=='G')
        {
            ans += solve(pG, x);
            pG = x;
            Rs.clear(); Bs.clear();
        }
        else if(c=='B')
            Bs.push_back(x);
        else
            Rs.push_back(x);
    }
    ans += solve(pG, (long long)1e15);
    printf("%lld\n", ans);
    return 0;
    
}