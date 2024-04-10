#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll a[500005];
ll sum[500005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%lld",a+i);
        for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
        int now=0;
        map<ll,int>mp,save;
        save[0]=0;
        mp[0]=0;
        for(int i=1;i<=n;i++)
        {
            //cout<<"????"<<i<<" "<<now<<endl;
            if(a[i]<0)now+=2;
            else if(a[i]==0)now++;
            //cout<<"????"<<i<<" "<<now<<endl;
            //sum[i]+first>0
            //sum[i]+first==0
            auto it=mp.upper_bound(-sum[i]);
            if(it!=mp.end())
            {
                now=min(now,it->second);
            }
            //
            it=save.find(-sum[i]);
            if(it!=save.end())
            {
                now=min(now,it->second+i);
            }
            //
            //
            if(save.find(-sum[i])==save.end())
            {
                save[-sum[i]]=now-i;
            }
            else if(save[-sum[i]]>now-i)
            {
                save[-sum[i]]=now-i;
            }
            //
            sum[i]=-sum[i];
            if(mp.find(sum[i])!=mp.end())
            {
                if(mp[sum[i]]>now)
                {
                    mp[sum[i]]=now;
                    it=mp.find(sum[i]);
                    bool flag=1;
                    if(it!=mp.end())
                    {
                        it++;
                        if(it!=mp.end()&&it->second<=now)
                        {
                            flag=0;
                            mp.erase(mp.find(sum[i]));
                        }
                    }
                    while(flag)
                    {
                        it=mp.find(sum[i]);
                        if(it==mp.begin())break;
                        it--;
                        if(it->second>=now)mp.erase(it);
                        else break;
                    }
                }
            }
            else
            {
                mp[sum[i]]=now;
                it=mp.find(sum[i]);
                bool flag=1;
                if(it!=mp.end())
                {
                    it++;
                    if(it!=mp.end()&&it->second<=now)
                    {
                        flag=0;
                        mp.erase(mp.find(sum[i]));
                    }
                }
                while(flag)
                {
                    it=mp.find(sum[i]);
                    if(it==mp.begin())break;
                    it--;
                    if(it->second>=now)mp.erase(it);
                    else break;
                }
            }
            //cout<<"<<"<<i<<endl;
            //for(auto pr:mp)cout<<pr.first<<" "<<pr.second<<endl;
            //cout<<"!!"<<now<<endl;
        }
        printf("%d\n",n-now);
    }
    return 0;
}
/*
1
5
-1 -2 3 -1 -1
*/