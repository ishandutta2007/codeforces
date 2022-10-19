#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair

int n,k;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("hall.in","r",stdin);
    //freopen("hall.out","w",stdout);
    cin>>n>>k;
    if(k==n || k==0)
    {
        cout<<"0 0"<<endl;
        return 0;
    }
    if(k<=n/3)
    {
        cout<<"1 "<<k*2<<endl;
        return 0;
    }
    int ans=(n/3)*2;
    k-=(n/3);
    if(n%3==1)
        --k;
    if(n%3==2)
    {
        --k;
        ++ans;
    }
    if(k==0)
    {
        cout<<"1 "<<ans<<endl;
        return 0;
    }
    ans-=k;
    cout<<"1 "<<ans<<endl;
    return 0;
}