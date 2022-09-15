#include<bits/stdc++.h>
using namespace std;

int N, K;
int arr[1010101];
int main()
{
    long long cur = 0;
    scanf("%d%d", &N, &K); ++K;
    for(int i=0; i<N; ++i)
        scanf("%d", arr+i);
    sort(arr, arr+N);
    for(int i=0; i<N; ++i)
        cur += 1LL*arr[i]*(i/K);

    long long ans = cur;
    
    long long build = 0;
    for(int i=N-1; i>=0; --i)
    {
        build += arr[i];
        if(i%K == 0) continue; // do not have to consider delta
        cur += build;
        ans = max(ans, cur);
    }
    printf("%lld\n", ans);


}