#include <iostream>

using namespace std;

int main()
{
    int a[3005],b[3005];
    int n,m,i,j;

    cin>>n>>m;
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=0;i<m;i++)
        cin>>b[i];

    i=0,j=0;
    while(i<n && j<m)
        if(b[j]>=a[i])
            i++,j++;
        else
            j++;

    cout<<n-i<<'\n';
    return 0;
}