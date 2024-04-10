#include"bits/stdc++.h"
using namespace std;
int a[100005];
int save[100005][2],nn;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<=n;i++)
        {
            a[i]=i;
        }
        long long ans=0;
        nn=0;
        for(int i=2;i<=n/2;i++)
        {
            save[nn][0]=i;
            save[nn][1]=n;
            nn++;
            ans+=(n-i)*(long long)(n-i);
        }
        for(int i=n/2+1;i<=n;i++)
        {
            save[nn][0]=i;
            save[nn][1]=1;
            nn++;
            ans+=(1-i)*(long long)(1-i);
        }
        for(int i=nn-1;i>=0;i--)swap(a[save[i][0]],a[save[i][1]]);
        cout<<ans<<endl;
        for(int i=1;i<=n;i++)printf("%d%c",a[i]," \n"[i==n]);
        cout<<nn<<endl;
        for(int i=0;i<nn;i++)printf("%d %d\n",save[i][0],save[i][1]);
    }
    return 0;
}