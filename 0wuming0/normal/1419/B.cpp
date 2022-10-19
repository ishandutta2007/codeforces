#include"bits/stdc++.h"
#define ll long long
using namespace std;
ll a[300];
int main()
{
    ll best=3*(ll)(1e18)+10;
    ll b=1;
    for(int i=1;b<=best/2;i++)
    {
        b*=2;
        a[i]=b-1;
    }
    //cout<<a[4];
    int t;
    cin>>t;
    while(t--)
    {
        ll ans;
        cin>>ans;
        for(int i=1;;i++)
        {
            ans-=a[i]*(a[i]+1)/2;
            //cout<<"!"<<i<<":"<<ans<<endl;
            if(ans<0)
            {
                cout<<i-1<<endl;
                break;
            }
        }
        //
    }
    return 0;
}
/*
1
4
1221
*/