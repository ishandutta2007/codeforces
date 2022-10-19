#include"bits/stdc++.h"
using namespace std;
int a[10005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        for(int i=0;i<n;i++)scanf("%d",a+i);
        for(int i=1;i<n;i++)
        {
            int c=min(a[i],k/i);
            k-=c*i;
            a[i]-=c;
            a[0]+=c;
        }
        cout<<a[0]<<endl;
    }
    return 0;
}