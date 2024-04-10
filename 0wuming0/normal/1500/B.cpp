#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll gcd(ll a,ll b)
{
    if(a==0||b==0)return a+b;
    return gcd(b,a%b);
}
int a[500005],b[500005];
map<int,int>mpa,mpb;
ll pows(ll a,ll b,ll mod)
{
    ll ans=1;
    for(;b;b>>=1,a=a*a%mod)
    {
        if(b%2)ans=ans*a%mod;
    }
    return ans%mod;
}
int eular[500005];
int prime[500005];
ll dev(ll a,ll b)
{
    return pows(a,eular[b]-1,b);
}
int main()
{
    for(int i=2;i<500005;i++)if(prime[i]==0)
    {
        for(int j=2;i*j<500005;j++)
        {
            prime[i*j]=i;
        }
    }
    //for(int i=2;i<500005;i++)if(prime[i]==0)cout<<i<<endl;
    eular[1]=1;
    for(int i=2;i<500005;i++)
    {
        if(prime[i]==0)eular[i]=i-1;
        else
        {
            int j=prime[i];
            int now=i/j;
            int ans=j-1;
            while(now%j==0)
            {
                now/=j;
                ans*=j;
            }
            ans*=eular[now];
            eular[i]=ans;
        }
    }
    //for(int i=1;i<=10;i++)cout<<i<<" "<<eular[i]<<endl;
    int n,m;
    cin>>n>>m;
    ll k;
    cin>>k;
    ll g=gcd(n,m);
    for(int i=0;i<n;i++)
    {
        scanf("%d",a+i);
        mpa[a[i]]=i;
    }
    for(int i=0;i<m;i++)
    {
        scanf("%d",b+i);
        mpb[b[i]]=i;
    }
    set<ll>time;
    for(int i=1;i<=1000000;i++)
    {
        if(mpa.find(i)==mpa.end())continue;
        if(mpb.find(i)==mpb.end())continue;
        int pos1=(mpa.find(i))->second,pos2=(mpb.find(i))->second;
        if((pos1-pos2)%g)continue;
        ll k=(pos2-pos1)/g*dev(n/g,m/g)%(m/g);//cout<<n<<" "<<m<<" "<<dev(n/g,m/g)<<endl;
        if(k<0)k+=m/g;//cout<<k<<" "<<pos1<<endl;
        time.insert(k*n+pos1+1);
    }//cout<<time.size()<<endl;
    ll sz=n/g*(ll)m-time.size();
    ll ans=0;
    ll num=(k-1)/sz;//cout<<*time.begin()<<endl;
    k-=num*sz;
    ans+=num*n/g*m;
    ll ans2=0;
    set<ll>::iterator it=time.begin();
    while(it!=time.end()&&*it<=k)
    {
        it++;
        k++;
    }
    cout<<ans+k<<endl;
    return 0;
}
/*
2 1 1000000000000
1 2
2

2 1 1
1 2
1
*/