#include"bits/stdc++.h"
using namespace std;
int a[10005];
int b[10005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",a+i);
            b[i]=a[i];
        }
        sort(a,a+n);
        for(int i=0;i<n;i++)if(a[i]!=b[i])
        {
            cout<<"YES"<<endl;
            goto ne;
        }
        cout<<"NO"<<endl;
        ne:;
    }
    return 0;
}