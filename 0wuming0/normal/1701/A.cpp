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
        if(a+b+c+d==0)cout<<0<<endl;
        else if(a+b+c+d==4)cout<<2<<endl;
        else cout<<1<<endl;
    }
    return 0;
}