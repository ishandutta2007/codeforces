#include<bits/stdc++.h>
using namespace std;
int N, K;
long long arr[55];
long long sum[55];
bool table[55][55]; //1~N 1~N
bool c[55][55];
bool can(long long rep)
{
    for(int i=1; i<=N; ++i)
        for(int j=i; j<=N; ++j)
        {
            long long s = sum[j] - sum[i-1];
            table[i][j] = ((s&rep) == rep) ;
        } 
    memset(c, 0, sizeof c);
    c[0][0] = true;
    for(int i=1; i<=N; ++i)
    {
        for(int j=1; j<=K; ++j)
        {
            for(int k=0; k<i; ++k)
            {
                if(table[k+1][i] && c[k][j-1])
                    c[i][j] = true;
            }   
        }
    }
    return c[N][K];
}
int main()
{
    scanf("%d%d", &N, &K);
    for(int i=1; i<=N; ++i)
    {
        scanf("%lld", arr+i);
        sum[i] = sum[i-1] + arr[i];
    }
    long long rep = 0;
    for(int i=57; i>=0; --i)
        if(can(rep + (1LL<<i))) rep += (1LL<<i); 
    printf("%lld\n", rep);
    return 0;
}