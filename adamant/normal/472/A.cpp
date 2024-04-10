#include <bits/stdc++.h>

using namespace std;

#define TASK "test"

main()
{
#ifndef ONLINE_JUDGE
    //freopen(TASK".in","r",stdin);
    //freopen(TASK".out","w",stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    if(!(n%2)) cout<<4<<' '<<n-4<<endl;
    else cout<<9<<' '<<' '<<n-9<<endl;
}