#include <iostream>
#include <algorithm>

using namespace std;

int v[2005];

int main()
{
    int n=0,k=0;
    cin>>n>>k;

    for(int i=1;i<=n;i++){
        cin>>v[i];
        v[i]=-v[i];
    }

    sort(v+1,v+n+1);

    int ans=0;
    for(int i=1;i<=n;i++)
        if((i%k)==(1%k))
            ans-=(v[i]+1);

    cout<<2*ans<<'\n';
    return 0;
}