#include"bits/stdc++.h"
using namespace std;
int l[100005],r[100005],c[100005];
int ansl[100005],ansr[100005];
int ans[100005];
int lans[100005],rans[100005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)ansl[i]=1e9+1;
        for(int i=0;i<n;i++)ansr[i]=-1e9-1;
        for(int i=0;i<n;i++)ans[i]=2e9;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d%d",l+i,r+i,c+i);
            if(i>0)
            {
                ansl[i]=ansl[i-1];
                ansr[i]=ansr[i-1];
            }
            ansl[i]=min(ansl[i],l[i]);
            ansr[i]=max(ansr[i],r[i]);
        }
        {
            map<pair<int,int>,int>mp;
            for(int i=0;i<n;i++)
            {//cout<<"???"<<c[i]<<endl;
                auto pr=make_pair(l[i],r[i]);
                if(mp.find(pr)==mp.end())
                {
                    mp[pr]=c[i];
                }
                else mp[pr]=min(mp[pr],c[i]);
                auto it=mp.find(make_pair(ansl[i],ansr[i]));
                if(it!=mp.end())
                {
                    ans[i]=it->second;//cout<<ansl[i]<<" "<<ansr[i]<<endl;
                    //cout<<"<<"<<i<<"  "<<it->second<<endl;
                }
            }
        }
        {
            map<int,int>mp;
            for(int i=0;i<n;i++)
            {
                auto pr=l[i];
                if(mp.find(pr)==mp.end())mp[pr]=c[i];
                else mp[pr]=min(mp[pr],c[i]);
                auto it=mp.find(ansl[i]);
                if(it!=mp.end())
                {
                    lans[i]=it->second;
                }
                else return 1;
            }
        }
        {
            map<int,int>mp;
            for(int i=0;i<n;i++)
            {
                auto pr=r[i];
                if(mp.find(pr)==mp.end())mp[pr]=c[i];
                else mp[pr]=min(mp[pr],c[i]);
                auto it=mp.find(ansr[i]);
                if(it!=mp.end())
                {
                    rans[i]=it->second;
                }
                else return 1;
            }
        }
        for(int i=0;i<n;i++)
        {
            //cout<<"<<<"<<i<<"  "<<ans[i]<<"  "<<lans[i]<<"  "<<rans[i]<<endl;
            printf("%d\n",min(ans[i],lans[i]+rans[i]));
        }
    }
    return 0;
}