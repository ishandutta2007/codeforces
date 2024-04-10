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
        vector<pair<int,int>> v(n);
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&v[i].first,&v[i].second);
            sum+=v[i].second;
        }
        sort(v.begin(),v.end());
        int idx=0;
        long long cnt=0;
        priority_queue<int> q;
        for(int i=0;i<n;i++)
        {
            while(idx<n&&v[idx].first<=i) q.push(v[idx++].second);
            if(!q.empty())
            {
                cnt+=q.top();
                q.pop();
            }
        }
        printf("%I64d\n",sum-cnt);
    }
    return 0;
}