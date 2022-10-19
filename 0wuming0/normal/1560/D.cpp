#include"bits/stdc++.h"
using namespace std;
#define ll long long
int nn;
map<int,int>mp;
int ans[2055];
int ans2[10005];
void add(ll x,int ans)
{
    if(x>=1e9)return;
    if(mp.find(x)==mp.end())
    {
        mp[x]=ans;
    }
    else
    {
        mp[x]=min(mp[x],ans);
    }
}
int num[10];
int _10[10];
int main()
{
    _10[0]=1;
    for(int i=1;i<10;i++)_10[i]=_10[i-1]*10;
    mp[0]=1;
    for(int i=0;(1ll<<i)<1e18;i++)
    {
        ll now=(1ll<<i);
        int s=0;
        while(now)
        {
            add(now,s);
            now/=10;
            s++;
        }
    }
    for(int i=0;i<2055;i++)
    {
        int s=0;
        for(int j=0;j<13;j++)if((1<<j)&i)s++;
        ans[i]=s;
    }
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        if(n==1000000000)
        {
            printf("%d\n",9);
            continue;
        }
        int ss=0;
        for(int i=0;;i++)
        {
            if(_10[i]>n)
            {
                ss=i;
                break;
            }
        }
        for(int i=0;i<9;i++)
        {
            num[i]=n%10;//*_10[i];
            n/=10;
        }
        int anss=100;
        auto it=mp.end();
        for(int i=0;i<(1<<ss);i++)
        {
            int now=0;
            int as=0;
            bool flag=1;
            for(int j=ss-1;j>=0;j--)
            {
                if(i&(1<<j))
                {
                    now*=10;
                    now+=num[j];
                    if(flag)
                    {
                        if(num[j]==0)
                        {
                            goto ne;
                        }
                        else flag=0;
                    }
                }
                else
                {
                    as++;
                }
            }
            //if(i==13)cout<<now<<endl;
            it=mp.find(now);
            if(it!=mp.end())
            {
                anss=min(anss,as+it->second);
                //if(as+it->second==1)cout<<i<<" "<<now<<" "<<as<<" "<<it->second<<endl;
            }
            ne:;
        }
        printf("%d\n",anss);
    }
    return 0;
}