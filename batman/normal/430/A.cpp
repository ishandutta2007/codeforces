#include <bits/stdc++.h>
using namespace std;
int n,m,a[1000],b[1000],c,d;
int main()
{
    
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    for(int j=0;j<m;j++)
        cin>>c>>d;
    sort(a,a+n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(b[i]==a[j])
            	cout<<j%2<<" ";
    return  0;
}