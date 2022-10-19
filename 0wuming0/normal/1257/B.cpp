#include"bits/stdc++.h"
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c,d;
        cin>>a>>b;
        if(b<=1)cout<<"yes"<<endl;
        else if(a==1)cout<<"no"<<endl;
        else if(b<=3)cout<<"yes"<<endl;
        else if(a<=3)cout<<"no"<<endl;
        else cout<<"yes"<<endl;
    }
    return 0;
}