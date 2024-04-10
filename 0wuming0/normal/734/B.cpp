#include"bits/stdc++.h"
using namespace std;
int main()
{
    int n2,n3,n5,n6;
    cin>>n2>>n3>>n5>>n6;
    n5=min(n5,n6);
    int ans=256*min(n2,n5);
    n2-=min(n2,n5);
    ans+=32*min(n2,n3);
    cout<<ans<<endl;
    return 0;
}