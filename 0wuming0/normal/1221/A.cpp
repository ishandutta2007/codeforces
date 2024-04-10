#include"bits/stdc++.h"
using namespace std;
int a[105];
int main()
{
    int n;

    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",a+i);
            if(a[i]<=3000)ans+=a[i];
        }
        if(ans>2047)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}