#include"bits/stdc++.h"
using namespace std;
int main()
{
    int n,x;
    cin>>n>>x;
    if(x%n)cout<<"-1"<<endl;
    else
    {
        int t=x/n;
        int ans=0;
        while(t%2==0)ans++,t/=2;
        while(t%3==0)ans++,t/=3;
        if(t==1)cout<<ans<<endl;else cout<<-1<<endl;
    }
    return 0;
}