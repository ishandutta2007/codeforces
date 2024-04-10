#include <bits/stdc++.h>

using namespace std;

int main()
{
    int z;
    scanf("%d",&z);
    while(z--)
    {
        long long n,t,a,b;
        scanf("%I64d%I64d%I64d%I64d",&n,&t,&a,&b);
        vector<pair<long long,int>> v(n);
        long long easy_left=0,hard_left=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&v[i].second);
            if(v[i].second==0) easy_left++;
            else hard_left++;
        }
        for(int i=0;i<n;i++) scanf("%I64d",&v[i].first);
        sort(v.begin(),v.end());
        long long easy=0,hard=0;
        int idx=0;
        int res=0;
        for(int i=0;i<=n;i++)
        {
            long long now;
            if(i<n) now=v[i].first-1;
            else now=t;
            while(idx<n&&v[idx].first<=now)
            {
                if(v[idx].second==0)
                {
                    easy++;
                    easy_left--;
                }
                else
                {
                    hard++;
                    hard_left--;
                }
                idx++;
            }
            long long sum=easy*a+hard*b;
            if(sum>now) continue;
            int cnt=0;
            long long d;
            d=min(easy_left,(now-sum)/a);
            cnt+=d;
            sum+=d*a;
            d=min(hard_left,(now-sum)/b);
            cnt+=d;
            sum+=d*b;
            res=max(res,(int)(easy+hard+cnt));
        }
        printf("%d\n",res);
    }
    return 0;
}