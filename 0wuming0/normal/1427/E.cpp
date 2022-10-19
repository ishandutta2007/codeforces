#include"bits/stdc++.h"
using namespace std;
#define ll long long
int nn;
char s[100003][50];
ll base[65];
int solve(ll n)
{
    int now;
    for(int i=0;i<=20;i++)
    {
        if((1<<i)&n)
        {
            now=i;
        }
    }
    base[now]=n;
    for(int i=now+1;i<=now*2+2;i++)
    {
        base[i]=base[i-1]*2;
        sprintf(s[nn++],"%lld + %lld",base[i-1],base[i-1]);
    }
    ll k;
    if((n+1)&(1<<(now+1)))
    {
        k=n+base[now*2]+base[now*2]+base[now*2];
        sprintf(s[nn++],"%lld + %lld",n,base[now*2]);
        sprintf(s[nn++],"%lld + %lld",n+base[now*2],base[now*2]);
        sprintf(s[nn++],"%lld + %lld",n+base[now*2]+base[now*2],base[now*2]);
    }
    else
    {
        k=n+base[now*2];
        sprintf(s[nn++],"%lld + %lld",n,base[now*2]);
    }
    for(int i=now*2+2;i>now;i--)
    {
        if(k&(1ll<<i))
        {
            sprintf(s[nn++],"%lld ^ %lld",k,base[i]);
            k^=base[i];
        }
    }
    if(k%2==0)
    {
        while((k&(1<<now))==0)
        {
            sprintf(s[nn++],"%lld + %lld",k,k);
            k=k+k;
        }
        sprintf(s[nn++],"%lld ^ %lld",k,n);
        k^=n;
    }
    /*
    if(k==0)
    {
        cout<<n<<endl;
    }*/
    //cout<<nn<<endl;
    //for(int i=0;i<nn;i++)printf("%s\n",s[i]);
    //cout<<"<<"<<n<<" "<<k<<endl;
    return k;
}
int main()
{
    int n;
    cin>>n;
    //for(int i=3;i<1000000;i+=2)solve(i);return 0;
    while(n!=1)
    {
        n=solve(n);
    }
    cout<<nn<<endl;
    for(int i=0;i<nn;i++)printf("%s\n",s[i]);
    return 0;
}