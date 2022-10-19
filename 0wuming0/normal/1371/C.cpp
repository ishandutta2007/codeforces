#include"bits/stdc++.h"
using namespace std;
#define ll long long
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll a,b,n,m;
        cin>>a>>b>>n>>m;
        if(a+b>=n+m&&min(a,b)>=m)cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    return 0;
}