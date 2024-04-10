#include"bits/stdc++.h"
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a=0,b=0;
    bool flag=0;
    while(n--)
    {
        int u,v;
        cin>>u>>v;
        a+=u;
        b+=v;
        if((u+v)%2)flag=1;
    }
    if(a%2==0&&b%2==0)cout<<0<<endl;
    else if((a+b)%2)cout<<-1<<endl;
    else if(flag)cout<<1<<endl;
    else cout<<-1<<endl;
    return 0;
}