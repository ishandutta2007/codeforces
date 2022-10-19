#include"bits/stdc++.h"
using namespace std;
int main()
{
    int save=1e9,ans=0;
    int n;
    cin>>n;
    while(n--)
    {
        int a;
        cin>>a;
        ans+=a;
        if(a%2!=0&&save>a)save=a;
    }
    if(save==1e9)ans=0;
    else if(ans%2==0)ans-=save;
    cout<<ans<<endl;
    return 0;
}