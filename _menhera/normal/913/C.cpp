#include<bits/stdc++.h>
using namespace std;
int N; long long L;
long long c[31];
map<long long, long long> M;
long long solve(long long x)
{
    if(x==0) return 0;
    if(M.find(x) != M.end()) return M[x];
    long long ans = 0x3f7f7f7f7f7f7f7fll;
    for(int i=0; i<N; ++i)
    {
        
        if(x>=(1<<i)) ans = min(ans, solve(x % (1<<i)) + (x/(1<<i))*c[i]);
        ans = min(ans, (x/(1<<i)+1)*c[i]);
    }
    return M[x] = ans;
}
int main()
{
    scanf("%d%lld", &N, &L);
    for(int i=0; i<N; ++i)
        scanf("%lld", c+i);
    printf("%lld\n", solve(L));
}