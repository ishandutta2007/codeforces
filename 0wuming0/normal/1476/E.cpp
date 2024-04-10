#include"bits/stdc++.h"
using namespace std;
#define ll long long
int k;
char a[100005][5];
char b[100005][5];
int chnum[100005];
int vis123[100005];
int ans[100005],nn;
map<string,int>mp;
int mpt[100005];
int kk;
int add(int t)
{
    ans[nn++]=t;
}
int n;
vector<int>out[100005];
vector<int>in[100005];
void fail()
{
    cout<<"NO"<<endl;
    exit(0);
}
int vis[100005];
int del[100005];
void che(int i)
{
    if(vis[i])return;
    if(out[i].size()-del[i]==0)
    {
        add(mpt[i]);
        vis[i]=1;
        for(vector<int>::iterator it=in[i].begin();it!=in[i].end();++it)
        {
            if(!vis[*it])
            {
                del[*it]++;
                che(*it);
            }
        }
    }
}
void solve()
{
    n=mp.size();
    for(int i=0;i<n;i++)
    {
        che(i);//cout<<nn<<endl;
    }
    if(nn!=n)fail();
}
int main()
{
    int n,m;
    cin>>n>>m>>k;
    for(int i=0;i<n;i++)scanf("%s",a[i]);
    string t0="";
    if(k==3)t0="a";
    else if(k==2)t0="aa";
    else if(k==1)t0="aaa";
    int flfg=0;
    for(int i=0;i<m;i++)
    {//cout<<i<<m<<endl;
        scanf("%s%d",b[i],chnum+i);
        string s=a[chnum[i]-1];
        for(int j=0;j<k;j++)
        {
            if(s[j]=='_')continue;
            if(s[j]!=b[i][j])flfg=1;
        }
        if(vis123[chnum[i]-1])continue;
        vis123[chnum[i]-1]=1;
        s=t0+s;
        mp[s]=kk;
        mpt[kk]=chnum[i]-1;
        kk++;
    }
    if(flfg)fail();
    for(int i=0;i<m;i++)
    {
        string s=b[i];
        s=t0+s;
        for(int j=0;j<16;j++)
        {
            string ch=s;
            for(int k=0;k<4;k++)if(j&(1<<k))ch[k]='_';//cout<<ch<<endl;
            map<string,int>::iterator it=mp.find(ch);
            if(it==mp.end())continue;
            //string sss=b[i];
            string ssss=a[chnum[i]-1];
            //if(ssss==3)continue;
            int aaa=it->second,bbb=mp.find(t0+ssss)->second;
            if(aaa==bbb)continue;//cout<<aaa<<"  "<<bbb<<"  "<<ch<<"  "<<s<<endl;
            out[aaa].push_back(bbb);
            in[bbb].push_back(aaa);
        }
    }
    solve();
    for(int i=0;i<n;i++)if(!vis123[i])add(i);
    cout<<"YES"<<endl;
    for(int i=0;i<n;i++)
    {
        printf("%d%c",ans[i]+1," \n"[i==n-1]);
    }
    return 0;
}
/*
3 2 2
aa
__
cd
cd 3
ba 2
*/