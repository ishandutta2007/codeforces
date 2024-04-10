#include<bits/stdc++.h>
using namespace std;
#define ll long long
int isprime(int n)
{
    for(int i=2;i<sqrt(n+1);i++)
        if(n%i==0)return 0;
    return 1;
}
int p[80000],pn;//78498
void parray()
{
    for(int i=2;i<1000000;i++)//1000000
        if(isprime(i))p[pn]=i,pn++;
}
int t[80000];
int re(int t)
{
    int x1=0,x2=pn;
    while(x1+1!=x2)
    {
        int x=(x1+x2)/2;
        if(p[x]>t)
        {
            x2=x;
        }
        else x1=x;
    }
    return x1;
}
void pnum(int n)
{
    //memset(t,0,sizeof(int)*80000);
    for(int i=0;i<pn&&p[i]<sqrt(n+1);i++)
        if(n%p[i]==0)
        {
            int j=1;
            n/=p[i];
            while(n%p[i]==0)n/=p[i],j++;
            //j
            t[i]=max(t[i],j);
        }
    if(n>1)//n
        t[re(n)]=max(t[re(n)],1);
}
ll g(ll a,ll b)
{
    ll a1=a,b1=b;
    while(a!=0&&b!=0)
    {
        if(a>b)a%=b;
        else b%=a;
    }
    return a1/(a+b)*b1;
}
int main()
{
    int i,j,n;
    parray();
    int o;
    cin>>o;
    while(o--)
    {
        memset(t,0,sizeof(int)*80000);
        cin>>n;
        int a[505];
        for(i=0;i<n;i++)
        {
            scanf("%d",a+i);
            pnum(a[i]);
        }
        sort(a,a+n);
        int mu=1,op=-1,w;
        for(i=0;i<80000;i++)
        {
            if(t[i])op++,w=p[i];
            mu*=t[i]+1;
        }
        ll ans=1;
        for(i=0;i<pn;i++)
        {
            if(t[i]==0)continue;
            for(j=0;j<t[i];j++)
                ans=ans*p[i];
        }
        if(ans!=a[n-1])
        {
            if(n+2==mu)
                cout<<ans<<endl;
            else
                cout<<-1<<endl;
        }
        else
        {
            if(n+1==mu&&!op)
                cout<<ans*w<<endl;
            else
                cout<<-1<<endl;
        }
    }
    return 0;
}