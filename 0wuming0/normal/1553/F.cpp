#include"bits/stdc++.h"
using namespace std;
#define ll long long
int num[300005];
int snum[300005];
ll x[300005];
ll sum[300005];
ll mod[550];
vector<int>v;
int main()
{
    int n;
    cin>>n;
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        if(v.size()==550)
        {
            for(auto b:v)
            {
                num[b]++;
                x[b]+=b;
                for(int j=2;j<550;j++)mod[j]+=b%j;
            }
            v.clear();
            for(int i=1;i<=300000;i++)
            {
                snum[i]=snum[i-1]+num[i];
                sum[i]=sum[i-1]+x[i];
            }
        }
        int a;
        scanf("%d",&a);
        ans+=snum[300000]*(ll)a;
        for(int i=1,last=a,next;;i++)
        {
            next=a/(i+1);
            if(next<i)next=i;
            ans-=i*(sum[last]-sum[next]);
            ans-=a/i*x[i];
            if(i==next)break;
            last=next;
        }
        if(a<550)
        {
            ans+=mod[a];
        }
        else
        {
            ll d=0;
            for(int i=a;i<=300000;i+=a)
            {
                d+=snum[300000]-snum[i-1];
            }
            ans+=sum[300000]-d*a;
        }
        for(auto &b:v)
        {
            ans+=b%a+a%b;
        }
        v.push_back(a);
        printf("%lld%c",ans," \n"[i==n]);
    }
    return 0;
}