#include"bits/stdc++.h"
using namespace std;
void add(map<int,int>&save,int k)
{
    map<int,int>::iterator it=save.find(k);
    if(it==save.end())
    {
        save[k]=1;
    }
    else
    {
        it->second++;
    }
}
void del(map<int,int>&save,int k)
{
    map<int,int>::iterator it=save.find(k);
    if(it==save.end())
    {
        save[k]=1;
    }
    else
    {
        it->second--;
    }
    if(it->second==0)save.erase(it);
}
int fd(map<int,int>&save)
{
    int x1=0,x2=1e9;
    while(x1+1!=x2)
    {
        int x=x1+x2+1;
        x/=2;
        if(save.lower_bound(-x)!=save.end())x2=x;
        else x1=x;
    }
    return x2;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a[4000]={0};
        int n,m,k;
        cin>>n>>m>>k;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",a+i);
        }
        m--;
        if(k>m)k=m;/*
        m-=k;

        for(int i=m+1;i<=m+k;i++)
        {
            add(save,a[i]);
        }
        for(int i=n;i>=n-k+1;i--)
        {
            add(save,a[i]);
        }
        int ans=fd(save);
        for(int i=1;i<=m;i++)
        {
            add(save,a[m+1-i]);
            add(save,a[n-k+1-i]);
            del(save,a[m+k+1-i]);
            del(save,a[n+1-i]);
            ans=min(ans,fd(save));
        }
        cout<<ans<<endl;*/
        int c=n-m-1;
        int b[4000]={0};
        for(int i=1;i+c<=n;i++)
        {
            b[i]=max(a[i],a[i+c]);
        }
        n=n-c;//cout<<"!"<<n<<endl;
        //for(int i=1;i<=n;i++)cout<<b[i]<<endl;;
        map<int,int>save;
        for(int i=k+1;i<=n;i++)
        {
            add(save,-b[i]);//cout<<-b[i]<<endl;
        }
        int ans=fd(save);
        for(int i=1;i<=k;i++)
        {
            add(save,-b[k-i+1]);
            del(save,-b[n-i+1]);
            ans=max(ans,fd(save));
        }
        cout<<ans<<endl;
    }
    return 0;
}
/*
4
3 1 0
3 3 3
4 4 1
2 13 60 4
4 1 3
1 2 2 1
1 1 0
9
*/