#include <bits/stdc++.h>
#pragma pack(1)

using namespace std;

#define TASK "test"

main()
 {
    #ifndef ONLINE_JUDGE
    freopen(TASK".in","r",stdin);
    freopen(TASK".out","w",stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    int i;
    for(i=1;n;i++)
    {
        n--;
        if(!(i%m)) n++;
    }
    cout<<i-1<<endl;
 }