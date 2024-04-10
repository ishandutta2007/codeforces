#include <iostream>
using namespace std;

int a[500][500];

int main()
{
    int n,k;
    cin>>n>>k;

    int cur=1;
    for(int i=0; i<n; i++)
        for(int j=0; j+1<k; j++)
            a[i][j]=cur++;

    for(int i=0; i<n; i++)
        for(int j=k-1; j<n; j++)
            a[i][j]=cur++;

    int sum=0;
    for(int i=0; i<n; i++)
        sum+=a[i][k-1];

    cout<<sum<<endl;
    for(int i=0; i<n; i++,cout<<"\n")
        for(int j=0; j<n; j++)
            cout<<a[i][j]<<' ';
    return 0;
}