#include <bits/stdc++.h>

using namespace std;

#define int long long

main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,a,b;
    cin>>n>>a>>b;
    n*=6;
    int ba=100000000000,bb=1000000000;
    for(int ta=a;ta<=a+1e6;ta++)
    {
        int tb=max(b,n/ta+!!(n%ta));
        if(tb>=b && tb*ta<ba*bb) ba=ta,bb=tb;
    }
    for(int tb=b;tb<=b+1e6;tb++)
    {
        int ta=max(a,n/tb+!!(n%tb));
        if(tb*ta<ba*bb) ba=ta,bb=tb;
    }

    cout<<ba*bb<<' '<<ba<<' '<<bb<<endl;
}