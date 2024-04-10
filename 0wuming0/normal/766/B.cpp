#include"bits/stdc++.h"
using namespace std;
int a[100005];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        scanf("%d",a+i);
    }
    sort(a,a+n);
    for(int i=0;i<n-2;i++)
    {
        if(a[i]+a[i+1]>a[i+2])
        {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}