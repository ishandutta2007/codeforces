#include"bits/stdc++.h"
using namespace std;
int a[200006];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)a[i]=0;
        for(int i=0;i<n;i++)
        {
            int q;
            scanf("%d",&q);
            a[((q+i+1)%n+n)%n]++;
        }
        int flag=1;
        for(int i=0;i<n;i++)if(a[i]>1)flag=0;
        if(flag)cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    return 0;
}