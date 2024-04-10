#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll mod=1e9+7;
ll ans;
int p[200005];
int pos[200005],nn;
int ppos[200005];
int a[200005];
map<int,int>mp[200005];//
set<pair<int,int> >st[200005];
int n,q;
void add(int i,int t)
{
    ll c,d;
    if(st[t].size()<n)c=0;
    else c=(st[t].begin())->first;
    map<int,int>::iterator it=mp[i].find(t);
    if(it!=mp[i].end())
    {
        pair<int,int>pr;
        pr.first=it->second;
        pr.second=i;
        st[t].erase(st[t].find(pr));
        pr.first++;
        st[t].insert(pr);
        it->second++;
    }
    else
    {
        mp[i][t]=1;
        pair<int,int>pr;
        pr.first=1;
        pr.second=i;
        st[t].insert(pr);
    }
    if(st[t].size()<n)d=0;
    else d=(st[t].begin())->first;
    if(c+2<=d)exit(1);
    if(c+1==d)ans=ans*t%mod;//cout<<"<<<"<<c<<" "<<d<<endl;
}
void add2(int i,int t)
{//cout<<"ok"<<i<<" "<<t<<endl;
    if(t==1)return;
    if(p[t]==0)
    {
        add(i,t);
        return;
    }
    add(i,p[t]);
    t/=p[t];
    add2(i,t);
}
int main()
{
    ans=1;
    for(int i=2;i<200005;i++)if(p[i]==0)for(int j=2;i*j<200005;j++)
    {
        p[i*j]=i;
    }
    for(int i=2;i<200005;i++)if(p[i]==0)
    {
        pos[nn]=i;
        ppos[i]=nn;
        nn++;
    }
    //for(int i=0;i<30;i++)printf("%d\n",pos[i]);
    //cout<<nn<<endl;
    cin>>n>>q;
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    for(int i=1;i<=n;i++)add2(i,a[i]);
    while(q--)
    {
        int i,t;
        scanf("%d%d",&i,&t);
        add2(i,t);
        printf("%lld\n",ans);
    }
    return 0;
}