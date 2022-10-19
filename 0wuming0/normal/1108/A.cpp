#include"bits/stdc++.h"
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        if(a==d)cout<<b<<" "<<c<<endl;
        else cout<<a<<" "<<d<<endl;
    }
    return 0;
}