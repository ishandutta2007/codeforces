#include<bits/stdc++.h>
using namespace std;
const int MOD = (int)1e9+7;

int arr[1010];
int main()
{
    int N; scanf("%d", &N);
    if(N >= 100)
    {
        puts("1"); return 0;
    }
    for(int i=0; i<N; ++i) scanf("%d", arr+i);
    int ans = (int)1e9;
    for(int i=0; i<=N; ++i)
    {
        int ijx = 0; // [i, j)
        for(int j=i+1; j<=N; ++j)
        {
            ijx ^= arr[j-1];
            int jkx = 0;
            for(int k=j+1; k<=N; ++k)
            {
                jkx ^= arr[k-1];
                if(ijx > jkx)
                {
                    ans = min(ans, k-i-2);
                }
            }
        }
    }
    if(ans <=101010) printf("%d\n", ans);
    else puts("-1");
}