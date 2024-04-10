#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        vector<int> v(n);
        for(int i=0;i<n;i++) scanf("%d",&v[i]);
        bool ok=1;
        auto solve=[&]()->bool
        {
            long long sum=0;
            for(int i=0;i<n-1;i++)
            {
                sum+=v[i];
                if(sum<=0) return 0;
            }
            return 1;
        };
        if(solve()==0) ok=0;
        reverse(v.begin(),v.end());
        if(solve()==0) ok=0;
        if(ok) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}