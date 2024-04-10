

#include<bits/stdc++.h>
using namespace std;
vector<long long> timeskip;
int N;
long long K;
long long a[101];
const int MAGIC = 387654;
int main()
{
    scanf("%d%lld",&N,&K);
    for(int i=0; i<N; ++i) scanf("%lld", a+i);
    for(int i=1; i<MAGIC; ++i)
        timeskip.push_back((long long)i);  
    for(int i=0; i<N; ++i)
    {
        for(int j=1; (a[i]+j-1)/j>=MAGIC; ++j)
            timeskip.push_back((a[i]+j-1)/j); 
    }
    long long ansv = 0;
    for(long long d: timeskip)
    {
        long long ans = 0;
        for(int i=0; i<N; ++i) ans += (d-a[i]%d)%d;
        long long dx = 0;
        for(int i=0; i<N; ++i) dx += (a[i]+d-1)/d;
        //if(d<10) printf("%lld %lld %lld\n",d, K, ans);
        if(K<ans) continue;
        
        ansv = max(ansv, d+(K-ans)/dx);
    }
    printf("%lld\n", ansv);   
}