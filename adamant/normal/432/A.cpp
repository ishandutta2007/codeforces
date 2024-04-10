#include <bits/stdc++.h>

using namespace std;

#define TASK "test"

main()
{
    //freopen(TASK".in","r",stdin);
    //freopen(TASK".out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    int c=0;
    for(int i=0;i<n;i++)
        {cin>>a[i];
        if(5-a[i]>=k)c++;}
    cout<<c/3<<endl;

}