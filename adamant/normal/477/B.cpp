#include <bits/stdc++.h>

using namespace std;

#define int int64_t

main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n,k;
    cin>>n>>k;
    cout<<k*(2*n+3+4*(n-1))<<endl;
    for(int i=0;i<n;i++)
        cout<<k*(2+6*i)<<' '<<k*(1+6*i)<<' '<<k*(3+6*i)<<' '<<k*(5+6*i)<<"\n";
}