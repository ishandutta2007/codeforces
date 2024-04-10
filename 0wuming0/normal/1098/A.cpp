#include"bits/stdc++.h"
using namespace std;
int pr[100005];
int val[100005];
int h[100005];
#define ll long long
void geth(int i)
{
    if(h[i])return;
    geth(pr[i]);
    h[i]=h[pr[i]]+1;
}
vector<int>v[100005];
vector<int>hh[100005];
ll ans[100005];
void solve(int i,ll last)
{
    if(val[i]<last)
    {//cout<<val[i]<<" "<<last<<endl;
        cout<<-1<<endl;
        exit(0);
    }
    //ll ans=0;
    ans[i]=val[i]-last;
    for(vector<int>::iterator it1=v[i].begin();it1!=v[i].end();it1++)
    {
        for(vector<int>::iterator it=v[*it1].begin();it!=v[*it1].end();it++)
        {
            solve(*it,val[i]);
        }
    }
}
void solve2(int i)
{
    if(v[i].size()==0)return;
    ll sum=1e18;
    for(vector<int>::iterator it=v[i].begin();it!=v[i].end();it++)
    {
        sum=min(sum,ans[*it]);
    }
    for(vector<int>::iterator it=v[i].begin();it!=v[i].end();it++)
    {
        ans[*it]-=sum;
    }
    ans[i]+=sum;
}
int main()
{
    int n;
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        scanf("%d",pr+i);
        v[pr[i]].push_back(i);
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",val+i);
    }
    h[1]=1;
    for(int i=2;i<=n;i++)
    {
        geth(i);
    }
    for(int i=1;i<=n;i++)hh[h[i]].push_back(i);
    solve(1,0);
    for(int i=n;i>=1;i--)if(val[i]==-1)solve2(i);
    ll sum=0;
    for(int i=1;i<=n;i++)sum+=ans[i];
    cout<<sum<<endl;
    return 0;
}
/*
9
1 1 2 2 2 3 3 3
1 -1 -1 3 4 5 3 4 5
*/