#include"bits/stdc++.h"
using namespace std;
#define ll long long
int a[100005],b[100005],c[100005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)scanf("%d",a+i);
        for(int i=1;i<=n;i++)scanf("%d",b+i);
        for(int i=1;i<=n;i++)scanf("%d",c+i);
        ll now=a[n]-1,ans=0;
        for(int i=n-1;i>=1;i--)
        {
            ans=max(ans,now+2+abs(b[i+1]-c[i+1]));
            if(i==1)break;
            ll nnow=a[i]-1;
            if(b[i+1]!=c[i+1])
            {
                nnow=max(nnow,now+a[i]-1-abs(b[i+1]-c[i+1])+2);
            }
            now=nnow;
        }
        cout<<ans<<endl;
    }
    return 0;
}