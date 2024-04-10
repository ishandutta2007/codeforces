#include"bits/stdc++.h"
using namespace std;
int now;
int a[300005];
int n,q,mod;
void add(int i,long long d)
{
    if(i<1||i>n)return;
    if(a[i]==0)now++;
    a[i]=(a[i]+d)%mod;
    if(a[i]==0)now--;
}
int f[300005];
int main()
{
    cin>>n>>q>>mod;
    f[1]=f[2]=1%mod;
    for(int i=3;i<300005;i++)f[i]=(f[i-2]+f[i-1])%mod;
    for(int i=1;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        add(i,a);
        add(i+1,-a);
        add(i+2,-a);
    }
    for(int i=1;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        add(i,-a);
        add(i+1,a);
        add(i+2,a);
    }
    char s[10];
    while(q--)
    {
        int l,r;
        scanf("%s%d%d",s,&l,&r);
        long long k=1;
        if(s[0]=='B')k=-1;
        add(l,k);
        add(r+1,-k*f[r-l+2]);
        add(r+2,-k*f[r-l+1]);
        if(now)printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}