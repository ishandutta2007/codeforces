#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        long long k;
        scanf("%d%I64d",&n,&k);
        vector<int> cnt(60,0);
        for(int i=0;i<n;i++)
        {
            long long x;
            scanf("%I64d",&x);
            int idx=0;
            while(x)
            {
                cnt[idx++]+=(x%k);
                x/=k;
            }
        }
        bool ok=1;
        for(int i=0;i<60;i++) if(cnt[i]>=2) ok=0;
        if(ok) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}