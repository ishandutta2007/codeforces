#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll mod=998244353;
ll ans;
ll jc[300001];
int a[300005],b[300005],pos[300005];
bool cmp(int p,int q){if(a[p]==a[q])return b[p]<b[q];else return a[p]<a[q];}
bool cmp2(int p,int q){if(b[p]==b[q])return a[p]<a[q];else return b[p]<b[q];}
int main()
{
    jc[0]=1;
    for(int i=1;i<300001;i++)jc[i]=jc[i-1]*i%mod;
    ll n;
    cin>>n;if(n==1){cout<<0<<endl;return 0;}
    for(int i=0;i<300004;i++)pos[i]=i;
    for(int i=0;i<n;i++)scanf("%d%d",a+i,b+i);
    sort(pos,pos+n,cmp);
    ll ans1=1,ans2=1,ans3=1;
    int t,k,i;
    for(i=0;i<n;)
    {
        k=0;
        t=a[pos[i]];
        while(a[pos[i]]==t)i++,k++;
        ans1=ans1*jc[k]%mod;//cout<<k<<'-'<<endl;
    }
    for(int i=0;i<300004;i++)pos[i]=i;
    sort(pos,pos+n,cmp2);
    for(i=0;i<n;)
    {
        k=0;
        t=b[pos[i]];
        while(b[pos[i]]==t)i++,k++;
        ans2=ans2*jc[k]%mod;//cout<<k<<'-'<<endl;
    }
    for(i=1;i<n;i++)
    {
        if(a[pos[i-1]]>a[pos[i]])break;
    }//cout<<i<<'.'<<endl;
    if(i!=n)ans3=0;
    else
    {
        int t1,t2;
        for(i=0;i<n;)
        {
            k=0;
            t1=a[pos[i]];t2=b[pos[i]];
            while(b[pos[i]]==t2&&a[pos[i]]==t1)i++,k++;
            ans3=ans3*jc[k]%mod;
        }
    }
    ans=ans1+ans2-ans3;
    ans=(jc[n]-ans)%mod;
    if(ans<0)ans+=mod;
    //cout<<ans1<<endl;
    //cout<<ans2<<endl;
    //cout<<ans3<<endl;
    cout<<ans<<endl;
    return 0;
}
/*

*/