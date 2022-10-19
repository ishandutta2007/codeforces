#include"bits/stdc++.h"
#define ll long long
using namespace std;
ll maxs[35],sum[35];
void solve(int a[],int n,int pos)
{
    if(pos==-1)return;
    if(n==0)return;
    ll ans=0;
    int *b,*c;
    b=new int[n];
    c=new int[n];
    int n0=0,n1=0,num=(1<<pos);
    for(int i=0;i<n;i++)
    {
        if(a[i]&num)c[n1++]=a[i];
        else
        {
            b[n0++]=a[i];
            ans+=n1;
        }
    }
    maxs[pos]+=n1*(ll)n0;
    sum[pos]+=ans;
    solve(b,n0,pos-1);
    solve(c,n1,pos-1);
    delete []b;
    delete []c;
}
int a[300005];
ll ans=0;
int x=0;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)scanf("%d",a+i);
    solve(a,n,30);
    for(int i=30;i>=0;i--)
    {
        if(maxs[i]<2*sum[i])
        {
            x^=(1<<i);
            ans+=maxs[i]-sum[i];
        }
        else ans+=sum[i];
    }
    cout<<ans<<" "<<x<<endl;
    return 0;
}