#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    vector<int> v(n+m);
    for(int i=0;i<n;i++) v[i]=n-i;
    vector<int> one(n+1);
    vector<int> two(n+1);
    for(int i=1;i<=n;i++) one[i]=two[i]=i;
    for(int i=0;i<m;i++)
    {
        scanf("%d",&v[n+i]);
        one[v[n+i]]=1;
    }
    const int sz=775;
    vector<int> id[n+1];
    for(int i=0;i<n+m;i++) id[v[i]].push_back(i);
    for(int i=1;i<=n;i++) id[i].push_back(n+m-1);
    vector<array<int,3>> queries;
    for(int o=1;o<=n;o++)
    {
        for(int i=0;i<(int)id[o].size()-1;i++) queries.push_back({id[o][i],id[o][i+1],o});
    }
    sort(queries.begin(),queries.end(),[](array<int,3> a,array<int,3> b){return ((a[0]/sz)<(b[0]/sz)||((a[0]/sz)==(b[0]/sz)&&a[1]<b[1]));});
    int now=0;
    vector<int> cnt(n+1,0);
    int l=0,r=-1;
    auto add=[&](int idx)->void
    {
        if(cnt[v[idx]]==0) now++;
        cnt[v[idx]]++;
    };
    auto rm=[&](int idx)->void
    {
        if(cnt[v[idx]]==1) now--;
        cnt[v[idx]]--;
    };
    auto update=[&](int ll,int rr)->void
    {
        while(ll<l)
        {
            l--;
            add(l);
        }
        while(r<rr)
        {
            r++;
            add(r);
        }
        while(l<ll)
        {
            rm(l);
            l++;
        }
        while(rr<r)
        {
            rm(r);
            r--;
        }
    };
    for(array<int,3> a:queries)
    {
        update(a[0],a[1]);
        two[a[2]]=max(two[a[2]],now);
    }
    for(int i=1;i<=n;i++) printf("%d %d\n",one[i],two[i]);
    return 0;
}