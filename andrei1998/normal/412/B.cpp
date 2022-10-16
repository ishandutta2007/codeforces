#include <iostream>
#include <algorithm>

using namespace std;

int v[105];

int main()
{
    int n,k,i;

    cin>>n>>k;
    for(i=1;i<=n;i++)
        cin>>v[i];

    sort(v+1,v+n+1);
    cout<<v[n-k+1]<<'\n';

    return 0;
}