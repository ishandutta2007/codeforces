#include"bits/stdc++.h"
using namespace std;
#define ll long long
int l[200005],r[200005];
char s[200005];
char ss[400005];
int pos[400005];
int ok[200005];
int nn;
void dfs(int i)
{
    if(i==0)return;
    dfs(l[i]);
    pos[nn]=i;
    ss[nn++]=s[i];
    dfs(r[i]);
}
int k;
int dfs2(int i,int now)
{
    if(i==0)return 0;
    if(dfs2(l[i],now+1)==1)
    {
        ss[nn++]=s[i];
        ss[nn++]=s[i];
        dfs2(r[i],1);
        return 1;
    }
    else if(ok[i]==0)
    {
        ss[nn++]=s[i];
        dfs(r[i]);
        return 0;
    }
    else
    {
        ss[nn++]=s[i];
        if(now<=k)
        {
            k-=now;
            ss[nn++]=s[i];
            dfs2(r[i],1);
            return 1;
        }
        else
        {
            dfs(r[i]);
            return 0;
        }
    }

}
int main()
{
    int n;
    cin>>n>>k;
    cin>>(s+1);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",l+i,r+i);
    }
    dfs(1);
    //cout<<ss<<endl;
    {
        int i=n-1;
        char last=ss[n-1];
        while(ss[i]==ss[n-1]&&i>=0)i--;
        for(;i>=0;i--)
        {
            if(ss[i]==ss[i+1])
            {
                //
            }
            else
            {
                last=ss[i+1];
            }//cout<<"  "<<i<<" "<<ss[i]<<" "<<last<<endl;
            if(ss[i]<last)ok[pos[i]]=1;
        }
    }
    nn=0;
    dfs2(1,1);
    cout<<ss<<endl;
    return 0;
}