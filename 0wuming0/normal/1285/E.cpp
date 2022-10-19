#include"bits/stdc++.h"
using namespace std;
#define ll long long
int a[1000006];
ll l[200005],r[200005];
int sumr[1000006];
int suml[1000006];
int n;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        map<ll,int>mp;
        for(int i=0;i<n;i++)
        {
            scanf("%lld%lld",l+i,r+i);
            l[i]*=3;
            r[i]*=3;
            r[i]++;
            mp[l[i]]=1;
            mp[r[i]]=1;
            mp[l[i]-1]=1;
            mp[r[i]+1]=1;
        }
        int nn=0;
        for(map<ll,int>::iterator it=mp.begin();it!=mp.end();it++)
        {
            it->second=(nn++);
        }
        for(int i=0;i<n;i++)l[i]=mp[l[i]],r[i]=mp[r[i]];
        for(int i=0;i<=nn;i++)a[i]=suml[i]=sumr[i]=0;
        for(int i=0;i<n;i++)
        {
            a[l[i]]++;
            a[r[i]+1]--;
        }
        for(int i=1;i<nn;i++)
        {
            a[i]+=a[i-1];
        }//for(int i=0;i<nn;i++)printf("%d%c",a[i]," \n"[i==nn-1]);
        int sum=0,ans=0;
        for(int i=0;i<nn;i++)
        {
            if(a[i])
            {
                while(a[i])i++;
                sum++;
            }
        }//cout<<"<<<"<<sum<<endl;
        for(int i=0;i<nn;i++)
        {
            if(a[i]==1)
            {
                int l=i,r;
                while(a[i]==1)i++;
                r=i-1;//cout<<r<<endl;
                sumr[r]++;
                suml[l+1]++;
            }
        }
        for(int i=1;i<nn;i++)suml[i]+=suml[i-1],sumr[i]+=sumr[i-1];
        for(int i=0;i<n;i++)
        {
            int now=sum;
            now+=sumr[r[i]]-suml[l[i]];//cout<<suml[l[i]]<<endl;
            if(a[r[i]+1]==0&&a[r[i]]==1)now--;
            if(a[l[i]-1]==0&&a[l[i]]==1)now--;
            ans=max(ans,now);
        }
        cout<<ans<<endl;
    }
    return 0;
}