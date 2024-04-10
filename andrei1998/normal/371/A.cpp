#include <iostream>

using namespace std;

int main()
{
    int n,k,i,j,rap,v[105];
    cin>>n>>k;
    for(i=1;i<=n;i++)
    {
        cin>>v[i];
        v[i]--;
    }
    rap=n/k;
    int total;
    int ans=0;
    for(i=1;i<=k;i++)
    {
        total=0;
        for(j=0;j<rap;j++)
            total+=v[i+j*k];
        if(2*total<rap)
            ans+=total;
        else
            ans+=(rap-total);
    }
    cout<<ans<<'\n';

    return 0;
}