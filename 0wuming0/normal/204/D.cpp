#include"bits/stdc++.h"
using namespace std;
#define ll long long
char s[1000006];
ll mod=1e9+7;
void add(map<int,ll>&mp,int pos,ll t)
{
    t%=mod;
    map<int,ll>::iterator it=mp.find(pos);
    if(it==mp.end())
    {
        mp[pos]=t;
    }
    else it->second=(it->second+t)%mod;
}
int main()
{
    map<int,ll>mp1,mp2;
    ll n,k;
    cin>>n>>k;
    scanf("%s",s+1);
    int d1=0,d2=0;
    ll sum1=1,sum2=0,ok=0;
    mp1[0]=1;
    for(int i=1;i<=n;i++)
    {//cout<<s[i]<<" "<<sum1<<" "<<sum2<<endl;
        map<int,ll>::iterator it;
        if(s[i]=='W')
        {
            mp1.clear();
            d1=0;
            if(sum1>0)mp1[0]=sum1;
            d2--;
            it=mp2.find(d2+k);
            if(it!=mp2.end())
            {
                ll t=it->second;
                mp2.erase(it);
                sum2-=t;
                sum2%=mod;
                if(sum2<0)sum2+=mod;
                ok=(ok+t)%mod;
            }
        }
        else if(s[i]=='B')
        {
            mp2.clear();
            d2=0;
            if(sum2>0)mp2[0]=sum2;
            d1--;
            it=mp1.find(d1+k);
            if(it!=mp1.end())
            {
                ll t=it->second;
                sum1-=t;
                sum2+=t;
                sum1%=mod;
                sum2%=mod;
                if(sum1<0)sum1+=mod;
                mp1.erase(it);
                add(mp2,d2,t);
            }
        }
        else
        {//cout<<s[i]<<" "<<sum1<<" "<<sum2<<endl;
            ok=ok*2%mod;
            d1--;
            d2--;
            add(mp1,d1,sum1);
            add(mp2,d2,sum2);
            sum1=sum1*2%mod;
            sum2=sum2*2%mod;
            it=mp2.find(d2+k);
            if(it!=mp2.end())
            {
                ll t=it->second;
                mp2.erase(it);
                sum2-=t;
                sum2%=mod;
                if(sum2<0)sum2+=mod;
                ok=(ok+t)%mod;
            }//cout<<"ok"<<" "<<d1<<" "<<k<<endl;cout<<(mp1.find(0))->second<<endl;;
            it=mp1.find(d1+k);
            if(it!=mp1.end())
            {
                ll t=it->second;
                sum1-=t;
                sum2+=t;
                sum1%=mod;
                sum2%=mod;
                if(sum1<0)sum1+=mod;
                mp1.erase(it);
                add(mp2,d2,t);
            }
        }/*
        cout<<i<<endl;
        for(it=mp1.begin();it!=mp1.end();++it)
        {
            cout<<"<<<"<<it->first-d1<<" "<<it->second<<endl;
        }
        for(it=mp2.begin();it!=mp2.end();++it)
        {
            cout<<">>>"<<it->first-d2<<" "<<it->second<<endl;
        }*/
    }
    cout<<ok<<endl;
    return 0;
}