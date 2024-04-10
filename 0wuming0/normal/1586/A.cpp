#include"bits/stdc++.h"
using namespace std;
int a[105];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int s=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",a+i);
            s+=a[i];
        }
        for(int i=2;i*i<=s;i++)if(s%i==0)
        {
            cout<<n<<endl;
            for(int i=1;i<=n;i++)printf("%d%c",i," \n"[i==n]);
            goto ne;
        }
        int k;
        for(int i=0;i<n;i++)if(a[i]&1)k=i+1;
        cout<<n-1<<endl;
        for(int i=1;i<=n;i++)if(i!=k)printf("%d%c",i," \n"[i==n||i==n-1&&k==n]);
        ne:;
    }
    return 0;
}