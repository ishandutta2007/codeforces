#include"bits/stdc++.h"
using namespace std;
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    int flag=0;
    while(c>=0)
    {
        if(c%b==0)flag=1;
        c-=a;
    }
    if(flag)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}