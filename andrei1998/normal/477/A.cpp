#include <iostream>

#define mod 1000000007
using namespace std;

int main()
{
    int a=1,b=1;
    cin>>a>>b;

    int ans=0;
    for(int x=1;x<b;x++){
        ans+=((1ll*a*x)%mod+((1ll*b*x)%mod*(((a*(a+1ll))/2)%mod))%mod)%mod;
        if(ans>=mod)
            ans-=mod;
    }

    cout<<ans<<'\n';
    return 0;
}