#include"bits/stdc++.h"
#define ll long long
using namespace std;
int a[10005];
long long ans=0;
int n;
int c;
void solve(int i)
{
    while(i<=n)
    {
        c=a[i];
        if(a[i]!=1)a[i]--;
        i+=c;
    }
}
ll num[10005];
int main()
{
    int t;
    cin>>t;
    int cc;
    int be;
    int ed;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",a+i);
            num[i]=0;
        }
        ll ans2=0;
        ans=0;
        for(int i=1;i<=n;i++)
        {
            num[i]+=num[i-1];
            cc=n-i;
            ans+=a[i]-1;ans-=num[i];
            ans2=max(ans2,ans);
            if(a[i]>cc)
            {
                be=n;
            }
            else be=i+a[i];
            a[i]=1;
            ed=i+2;
            num[ed]++;
            num[be+1]--;//cout<<i<<" "<<ans<<" "<<ans2<<endl;
        }
        cout<<ans2<<endl;
    }
    return 0;
}