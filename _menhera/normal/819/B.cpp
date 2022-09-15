#include<bits/stdc++.h>
using namespace std;
int P[1010101];
int cnt[2020202];
int N;
int main()
{
    cin >> N;
    for(int i=0; i<N; ++i) cin >> P[i];
    long long ans = 0;
    for(int i=0; i<N; ++i)
        ans += abs(P[i] - (i+1));
    long long minv = ans;
    int mint = 0;
    int plus = 0;
    for(int i=0; i<N; ++i)
    {
        if(i+1<P[i])
        {
            cnt[P[i]-(i+1)]++;
            ++plus;
        }
    }
    for(int t=1; t<=N; ++t)
    {
        ans -= plus;
        ans += N - plus;
        ans -= abs(P[N-t]-(N+1));
        ans += abs(P[N-t]-1);
        
        if(minv>ans)
        {
            minv = ans;
            mint = t;
        }
        if(cnt[t])
        {
            plus -= cnt[t];
        }
        if(1<P[N-t])
        {
            ++plus;
            cnt[t+P[N-t]-1]++;
        }
        //    plus.insert(t+P[N-t]-1);
        //printf("%lld %d\n", ans, t);
    }
    printf("%lld %d\n", minv, mint);
}