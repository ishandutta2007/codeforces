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
        vector<int> cnt(n+1,0);
        for(int i=0;i<n;i++)
        {
            int a;
            scanf("%d",&a);
            cnt[a]++;
        }
        vector<int> v;
        for(int i=1;i<=n;i++) if(cnt[i]) v.push_back(cnt[i]);
        sort(v.begin(),v.end());
        int res=n;
        for(int s=v[0]+1;s>=2;s--)
        {
            int m=0;
            bool ok=1;
            for(int i=0;i<(int)v.size();i++)
            {
                int num=(v[i]+s-1)/s;
                if(v[i]<num*(s-1)) ok=0;
                m+=num;
            }
            if(ok) res=min(res,m);
        }
        printf("%d\n",res);
    }
    return 0;
}