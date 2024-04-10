#include <bits/stdc++.h>
using namespace std;
const int N=200005;

int n;
int a[N];

int d[N];

int main()
{
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        d[i]=N;
    }
    for(int i=0;i<n;++i)
    {
        if(a[i]==0)
        {
            d[i]=0;
            for(int j=i-1,k=1;j>=0 && a[j]!=0;--j,++k)
                d[j]=min(d[j],k);
            for(int j=i+1,k=1;j<n && a[j]!=0;++j,++k)
                d[j]=min(d[j],k);
        }
    }
    for(int i=0;i<n;++i)
        cout<<d[i]<<' ';
    cout<<endl;
    return 0;
}