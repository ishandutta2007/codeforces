#include <iostream>

#define mod 1000000007
using namespace std;

int din[100005];

int main()
{
    ios_base::sync_with_stdio(false);
    int t=0,k=0;
    cin>>t>>k;

    din[0]=1;
    for(int i=1;i<=100000;i++)
    {
        din[i]=din[i-1];
        if(i>=k)
            din[i]+=din[i-k];

        if(din[i]>=mod)
            din[i]-=mod;
    }

    for(int i=1;i<=100000;i++){
        din[i]+=din[i-1];
        if(din[i]>=mod)
            din[i]-=mod;
    }

    int a,b;
    while(t--){
        cin>>a>>b;
        cout<<(din[b]-din[a-1]+mod)%mod<<'\n';
    }

    return 0;
}