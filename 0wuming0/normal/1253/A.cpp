#include"bits/stdc++.h"
using namespace std;
int a[100005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)scanf("%d",a+i);
        for(int i=1;i<=n;i++)
        {
            int k;
            scanf("%d",&k);
            a[i]=k-a[i];
        }
        int l=1,r=n;
        for(int i=1;i<=n;i++)
        {
            if(a[i]<0)
            {
                cout<<"NO"<<endl;
                goto ne;
            }
        }
        a[0]=1;
        a[n+1]=1;
        while(a[l]==0)l++;
        while(a[r]==0)r--;
        if(r==0)
        {
            cout<<"YES"<<endl;
            goto ne;
        }
        for(int i=l;i<=r;i++)
        {
            if(a[l]!=a[i])
            {
                cout<<"NO"<<endl;
                goto ne;
            }
        }
        cout<<"YES"<<endl;
        ne:;
    }
    return 0;
}