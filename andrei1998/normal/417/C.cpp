#include <iostream>

using namespace std;

int main()
{
    int n,k,i,j;
    cin>>n>>k;

    if(k>=((n+1)/2))
        cout<<"-1\n";
    else
    {
        cout<<n*k<<'\n';
        for(i=1;i<=n;i++)
            for(j=1;j<=k;j++)
                cout<<i<<' '<<((i+j-1)%n+1)<<'\n';
    }

    return 0;
}