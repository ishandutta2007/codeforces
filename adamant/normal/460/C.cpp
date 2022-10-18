#include <bits/stdc++.h>
#pragma pack(1)

using namespace std;

#define TASK "test"

bool ok(vector<int> a,int les,int m,int w)
{
    int n=a.size();
    vector<int> dd(n,0);
    long long T=0;
    int C=0;
    for(int i=0;i<n;i++)
    {
        a[i]+=C+=dd[i];
        if(a[i]<les)
        {
            T+=les-a[i];
            if(i+1<n) dd[i+1]+=les-a[i];
            if(i+w<n) dd[i+w]-=les-a[i];
        }
    }
    return T<=m;
}

main()
 {
    #ifndef ONLINE_JUDGE
    freopen(TASK".in","r",stdin);
    freopen(TASK".out","w",stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,w;
    cin>>n>>m>>w;
    vector<int> a(n);
    for(auto &it:a) cin>>it;
    int l=0,r=1e9+1e6;
    while(r-l>1)
    {
        int M=(l+r)/2;
        if(ok(a,M,m,w)) l=M;
        else r=M;
    }
    cout<<l<<endl;
 }