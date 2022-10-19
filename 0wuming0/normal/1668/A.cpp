#include"bits/stdc++.h"
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        if(a>b)swap(a,b);
        if(a==1&&b>=3)cout<<-1<<endl;
        else if(a==1)cout<<b-1<<endl;
        else
        {
            long long ans=a*2-2;
            b-=a;
            if(b&1)ans+=b*2-1;
            else ans+=b*2;
            cout<<ans<<endl;
        }
    }
    return 0;
}