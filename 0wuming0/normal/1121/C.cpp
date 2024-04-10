#include"bits/stdc++.h"
using namespace std;
int n,k;
int a[1005];
struct _
{
    int pos;
    int bg;
};
multimap<int,_>mp;
int vis[1005];
int getd(int k)
{
    int d=100*k/n;
    if(100*k%n*2>=n)d++;
    return d;
}
int main()
{
    int ans=0;
    /*

    a.first=1;
    a.second=2;
    mp.insert(a);
    a.second=2;
    mp.insert(a);
    cout<<mp.size()<<endl;;
    for(multimap<int,int>::iterator it=mp.begin();it!=mp.end();++it)cout<<it->second<<endl;
        */
    cin>>n>>k;
    for(int i=0;i<n;i++)scanf("%d",a+i);/* */
    for(int i=0;i<min(k,n);i++)
    {
        pair<int,_> aa;
        _ t;
        t.bg=0;
        t.pos=i;
        aa.first=a[i];
        aa.second=t;
        mp.insert(aa);
    }
    int nowt=0;
    int d,dc=0;
    int now=min(k,n);
    while(1)
    {
        d=getd(dc);
        if(mp.size()==0)break;
        map<int,_>::iterator it=mp.begin();
        int last;
        last=it->first;
        for(map<int,_>::iterator it=mp.begin();it!=mp.end();it++)
        {
            int r=it->first;
            int l=(it->second).bg;
            int x=d+l-1;
            if(nowt<=x&&x<last)vis[(it->second).pos]=1;
        }
        nowt=last;
        while(1)
        {
            it=mp.begin();
            if(nowt==it->first)
            {
                mp.erase(it);
                dc++;
            }
            else break;
        }
        while(mp.size()<k&&now!=n)
        {
            pair<int,_> aa;
            _ t;
            t.bg=nowt;
            t.pos=now;
            aa.first=nowt+a[now];
            aa.second=t;
            mp.insert(aa);
            now++;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(vis[i])ans++;
    }
    cout<<ans<<endl;
    return 0;
}
/*
1 10
49
*/