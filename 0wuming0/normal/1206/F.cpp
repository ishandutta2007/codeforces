#include"bits/stdc++.h"
using namespace std;
vector<int>v[1005];
int vis[1005];
int num[1005];
int pr[1005];
void solve(int i)
{
    for(vector<int>::iterator it=v[i].begin();it!=v[i].end();it++)if(*it!=pr[i])
    {
        if(vis[*it]==0)
        {
            pr[*it]=i;
            vis[*it]=1;
            solve(*it);
        }
        num[i]+=num[*it]+1;
    }
}
bool flag;
long long getans(int i,long long k)
{
    long long now=0;
    for(vector<int>::iterator it=v[i].begin();it!=v[i].end();it++)if(*it!=pr[i])
    {
        long long tt=getans(*it,k);
        if(now+k>1e6)flag=1;
        if(flag==1)cout<<i<<" "<<*it<<" "<<0<<endl;
        else cout<<i<<" "<<*it<<" "<<now+k<<endl;
        now+=tt+k;
    }
    return now;
}
bool cmp(int x,int y)
{
    return num[x]>num[y];
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vis[1]=1;
    int root=1;
    solve(1);//for(int i=1;i<=n;i++)cout<<i<<" "<<num[i]<<endl;
    while(1)
    {
        for(vector<int>::iterator it=v[root].begin();it!=v[root].end();it++)if(*it!=pr[root])
        {
            if(num[*it]>=(n-1)/2)
            {
                root=*it;
                goto afa;
            }
        }
        break;
        afa:;
    }//cout<<"ok"<<endl;
    for(int i=0;i<=n;i++)vis[i]=num[i]=pr[i]=0;
    vis[root]=1;
    solve(root);
    sort(v[root].begin(),v[root].end(),cmp);
    vector<int>v1,v2;
    int sum1=0,sum2=0;
    for(vector<int>::iterator it=v[root].begin();it!=v[root].end();++it)
    {
        if(sum1<=sum2)
        {
            v1.push_back(*it);
            sum1+=num[*it];
        }
        else
        {
            v2.push_back(*it);
            sum2+=num[*it];
        }
    }
    int now=0;
    for(vector<int>::iterator it=v1.begin();it!=v1.end();++it)
    {
        long long tt=getans(*it,1);
        if(now+1>1e6)flag=1;
        if(flag==1)cout<<root<<" "<<*it<<" "<<0<<endl;
        else cout<<root<<" "<<*it<<" "<<now+1<<endl;
        now+=tt+1;
    }
    int k=now+1;now=0;
    for(vector<int>::iterator it=v2.begin();it!=v2.end();++it)
    {
        long long tt=getans(*it,k);
        if(now+k>1e6)flag=1;
        if(flag==1)cout<<root<<" "<<*it<<" "<<0<<endl;
        else cout<<root<<" "<<*it<<" "<<now+k<<endl;
        now+=tt+k;
    }
    //getans(root,1);
    return 0;
}
/*
32
2 4
2 3
2 1
2 5
2 6
3 28
28 29
28 30
28 31
28 32
2 7
2 8
2 9
2 10
2 11
2 12
22 2
23 2
24 2
12 25
25 26
25 27
2 13
2 14
2 15
2 16
2 17
2 18
2 19
2 20
2 21
*/