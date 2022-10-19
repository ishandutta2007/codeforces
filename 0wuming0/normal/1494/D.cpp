#include"bits/stdc++.h"
using namespace std;
int a[505][505];
int ans[1005];
int pr[1005];
int n;
int vis[505];
int now1=1;
int givenum;
vector<int>save[10000];
int solve(vector<int> &v)
{
    int now2=now1+1;
    int t=-1,posss;
    for(vector<int>::iterator it=v.begin();it!=v.end();it++)for(vector<int>::iterator it2=it+1;it2!=v.end();it2++)
    {
        t=max(t,a[*it][*it2]);
    }
    for(vector<int>::iterator it=v.begin();it!=v.end();it++)for(vector<int>::iterator it2=it+1;it2!=v.end();it2++)
    {
        if(a[*it][*it2]!=t)
        {
            if(vis[*it]<=now1)
            {
                vis[*it]=now2;
                save[now2].push_back(*it);
                vis[*it2]=now2;
                save[now2].push_back(*it2);
                now2++;//cout<<t<<" "<<now2<<endl;
            }
            else if(vis[*it2]<=now1)
            {
                vis[*it2]=vis[*it];
                save[vis[*it]].push_back(*it2);
            }
        }
    }//cout<<"ok"<<endl;
    for(vector<int>::iterator it=v.begin();it!=v.end();it++)if(vis[*it]<=now1)
    {
        vis[*it]=now2;
        save[now2].push_back(*it);
        now2++;
    }
    int i=now1+1;//cout<<"<<<"<<t<<" "<<now1<<" "<<now2<<endl;
    now1=now2;
    vector<int>lef;
    for(;i<now2;i++)
    {//cout<<i<<endl;
        //cout<<"<<<"<<save[i].size()<<endl;
        if(save[i].size()==1)
        {
            lef.push_back(save[i][0]);
        }
        else
        {
            int t=solve(save[i]);
            lef.push_back(t);
        }
    }
    for(vector<int>::iterator it=lef.begin();it!=lef.end();++it)
    {//cout<<"<<<"<<*it<<endl;
        pr[*it]=givenum;
    }
    ans[givenum]=t;
    return givenum++;
}
int main()
{
    cin>>n;givenum=n+1;
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)scanf("%d",&a[i][j]);
    vector<int>v;
    for(int i=1;i<=n;i++)
    {
        ans[i]=a[i][i];
        v.push_back(i);
    }
    int aaa=solve(v);
    cout<<aaa<<endl;
    for(int i=1;i<=aaa;i++)printf("%d%c",ans[i]," \n"[i==aaa]);
    cout<<aaa<<endl;
    for(int i=1;i<aaa;i++)printf("%d %d\n",i,pr[i]);
    return 0;
}
/*
9
5 6 6 7 7 7 7 7 7
6 5 6 7 7 7 7 7 7
6 6 5 7 7 7 7 7 7
7 7 7 5 6 6 7 7 7
7 7 7 6 5 6 7 7 7
7 7 7 6 6 5 7 7 7
7 7 7 7 7 7 5 6 6
7 7 7 7 7 7 6 5 6
7 7 7 7 7 7 6 6 5
*/