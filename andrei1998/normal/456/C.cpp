#include <iostream>
#include <algorithm>

#define lint long long int
using namespace std;

int v[100005];
lint din[100005];

int main()
{
    int n,x;
    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>x;
        v[x]++;
    }

    lint ans=0;
    for(int i=100000;i>=0;i--)
        if(!v[i])
            ans+=din[i+1];
        else if(!v[i+1])
            din[i]=1ll*i*v[i];
        else
            din[i]=max(din[i+1],1ll*i*v[i]+din[i+2]);

    cout<<ans<<'\n';
    return 0;
}