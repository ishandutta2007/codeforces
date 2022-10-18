#include <bits/stdc++.h>

using namespace std;

#define TASK "test"
#define int long long

const int INF=1e18;

 main()
 {
    #ifndef ONLINE_JUDGE
    freopen(TASK".in","r",stdin);
    freopen(TASK".out","w",stdout);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m,n;
    cin>>m>>n;
    vector<int> a(m),b(n);
    for(int i=0;i<m;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int ans=INF;
    int s1=accumulate(a.begin(),a.end(),0ll);
    int s2=accumulate(b.begin(),b.end(),0ll);
    int cur=s2;
    for(int i=0;i<m-1;i++)
        cur+=min(a[i],s2);
    ans=min(ans,cur);
    cur=s1;
    for(int i=0;i<n-1;i++)
        cur+=min(b[i],s1);
    ans=min(ans,cur);
    cout<<ans<<endl;
 }