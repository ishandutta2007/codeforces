#include"bits/stdc++.h"
using namespace std;
#define ll long long
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,d;int flag=0;
        cin>>n>>d;
        int b=sqrt(d)-2;
        for(int x=b;x<=b+5;x++)
        {
            if(x<0)continue;
            if(x+d/(x+1)+(d%(x+1)!=0)<=n)flag=1;
        }
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}