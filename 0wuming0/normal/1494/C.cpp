#include"bits/stdc++.h"
using namespace std;
int a[200005];
int b[200005];
int save[200005],nn;
int pos[200005],nn2;
int solve()
{
    if(nn==0||nn2==0)return 0;
    int ans=0;
    int now;
    map<int,int>mp;
    for(int i=0;i<nn2;i++)mp[pos[i]]=1;
    for(int i=0;i<nn;i++)if(mp.find(save[i])!=mp.end())ans++;
    now=ans;
    int num=0;
    int p=0;
    save[nn]=2e9;
    int ansl=0,ansr=0;//cout<<"ok"<<endl;
    for(int i=0,j=0;;)
    {
        if(ansl<nn2&&pos[ansl]<p)
        {
            ansl++;
        }
        else if(ansr<nn2&&pos[ansr]<p+num)
        {
            ansr++;
            ans=max(ans,now+ansr-ansl);//cout<<"<<<"<<ansl<<" "<<ansr<<" "<<now<<" "<<ans<<endl;
            if(ansr==nn2)break;
        }
        else if(p+num==save[i])
        {
            num++;
            if(mp.find(save[i])!=mp.end())now--;
            i++;
        }
        else
        {
            p+=
            min(
            pos[ansr]-(p+num)+1,
            save[i]-(p+num));
        }
    }
    return ans;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        //map<int,int>mp;
        for(int i=1;i<=n;i++)scanf("%d",a+i);
        for(int i=1;i<=m;i++)
        {
            scanf("%d",b+i);
        }
        int ansl=0,ansr=0;
        int now;
        int t=0;
        for(t=1;t<=n;t++)if(a[t]>0)break;
        int tt;
        for(tt=1;tt<=m;tt++)if(b[tt]>0)break;
        nn=0;nn2=0;
        for(int i=t;i<=n;i++)save[nn++]=a[i];
        for(int i=tt;i<=m;i++)pos[nn2++]=b[i];
        int ans=0;
        ans+=solve();//cout<<nn<<" "<<nn2<<endl;
        nn=0;nn2=0;
        for(int i=t-1;i>=1;i--)save[nn++]=-a[i];
        for(int i=tt-1;i>=1;i--)pos[nn2++]=-b[i];
        ans+=solve();
        cout<<ans<<endl;
    }
    return 0;
}
/*
1
3 5
-1 1 2
-2 -1 1 2 5
*/