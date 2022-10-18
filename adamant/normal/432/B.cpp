#include <bits/stdc++.h>

using namespace std;

#define TASK "test"

main()
{
    //freopen(TASK".in","r",stdin);
    //freopen(TASK".out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    pair<int,int> x[n];
    vector<int> cnt(1e6,0);
    for(int i=0;i<n;i++)
        cin>>x[i].first>>x[i].second,
        cnt[x[i].first]++;
    for(int i=0;i<n;i++)
        cout<<n-1+cnt[x[i].second]<<' '<<n-1-cnt[x[i].second]<<endl;



}