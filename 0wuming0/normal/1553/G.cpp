#include"bits/stdc++.h"
using namespace std;
int prime[1000005];
int p[1000005],pn;
int a[150005];
int fa[1000005];
int finds(int u)
{
    if(fa[u]!=u)
    {
        fa[u]=finds(fa[u]);
    }
    return fa[u];
}
void unin(int u,int v)
{
    int fau=finds(u);
    int fav=finds(v);
    if(fau==fav)return;
    fa[fav]=fau;
}
set<int>save[1000005];
int temp[15],nn;
int main()
{
    for(int i=2;i<1000005;i++)
    {
        p[pn++]=i;fa[i]=i;
        if(prime[i]==0)for(int j=2;i*j<1000005;j++)prime[i*j]=i;
    }
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",a+i);
        int b=a[i];
        set<int>st;
        while(prime[b])
        {
            st.insert(prime[b]);
            b/=prime[b];
        }
        if(b!=1)st.insert(b);
        nn=0;
        for(auto c:st)temp[nn++]=c;
        for(int j=0;j<nn;j++)for(int k=j+1;k<nn;k++)
        {
            unin(temp[j],temp[k]);
        }
    }
    for(int i=1;i<=n;i++)
    {
        int b=a[i];
        set<int>st;
        while(prime[b])
        {
            st.insert(finds(prime[b]));
            b/=prime[b];
        }
        if(b!=1)st.insert(finds(b));
        b=a[i]+1;
        while(prime[b])
        {
            st.insert(finds(prime[b]));
            b/=prime[b];
        }
        if(b!=1)st.insert(finds(b));
        nn=0;
        if(st.find(finds(2))!=st.end())
        {
            st.erase(st.find(finds(2)));
        }
        for(auto c:st)temp[nn++]=c;
        for(int j=0;j<nn;j++)for(int k=j+1;k<nn;k++)
        {
            save[temp[k]].insert(temp[j]);
        }
    }
    while(q--)
    {
        int i,j;
        scanf("%d%d",&i,&j);
        i=a[i];
        j=a[j];
        if(prime[i])i=prime[i];
        if(prime[j])j=prime[j];
        i=finds(i);
        j=finds(j);
        if(i==j)printf("0\n");
        else if(i==finds(2))printf("1\n");
        else if(finds(2)==j)printf("1\n");
        else if(save[max(i,j)].find(min(i,j))!=save[max(i,j)].end())printf("1\n");
        else printf("2\n");
    }
    return 0;
}