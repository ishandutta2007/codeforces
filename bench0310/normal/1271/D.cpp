#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    vector<int> a(n+1),b(n+1),c(n+1);
    for(int i=1;i<=n;i++) scanf("%d%d%d",&a[i],&b[i],&c[i]);
    vector<int> t[n+1];
    for(int i=0;i<m;i++)
    {
        int one,two;
        scanf("%d%d",&one,&two);
        t[two].push_back(one);
    }
    vector<pair<int,int>> v;
    for(int i=1;i<=n;i++)
    {
        t[i].push_back(i);
        sort(t[i].begin(),t[i].end());
        v.push_back({c[i],t[i].back()});
    }
    sort(v.begin(),v.end(),greater<pair<int,int>>());
    vector<int> cnt(n+1,0);
    cnt[0]=k;
    for(int i=1;i<=n;i++)
    {
        if(k<a[i])
        {
            printf("-1\n");
            return 0;
        }
        k+=b[i];
        if(i<n) cnt[i]=k-a[i+1];
        else cnt[i]=k;
    }
    for(int i=n;i>0;i--) cnt[i-1]=min(cnt[i-1],cnt[i]);
    int res=0;
    for(int o=0;o<n;o++)
    {
        int pos=v[o].second;
        if(cnt[pos]>0)
        {
            res+=v[o].first;
            for(int i=pos;i<=n;i++) cnt[i]--;
            for(int i=n;i>0;i--) cnt[i-1]=min(cnt[i-1],cnt[i]);
        }
    }
    printf("%d\n",res);
    return 0;
}