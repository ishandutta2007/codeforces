#include"bits/stdc++.h"
using namespace std;
int prime[4004],p[4004],nn;
int a[200005];
int vis[10000007];
int solve(int *a,int n,int k,int ans)
{
    //
}
int main()
{
    for(int i=2;i<4004;i++)if(prime[i]==0)
    {
        p[nn++]=i*i;
        for(int j=2;i*j<4004;j++)prime[i*j]=i;
    }
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",a+i);
            for(int j=0;j<nn;j++)
            {
                while(a[i]%p[j]==0)a[i]/=p[j];
            }
        }
        int sum=1e9;
        if(k>=n)
        {
            cout<<0<<endl;
            continue;
        }
        for(int c=0;c<=k;c++)
        {
            int ans=0;
            int num=k-c;
            int bg,ed;
            bg=c+1;
            vector<int>save;
            ne:;
            if(n-bg+1<=num)
            {
                sum=min(sum,ans);
                continue;
            }
            ans++;
            {
                for(ed=bg;;ed++)
                {
                    if(vis[a[ed]]||ed==n+1)
                    {
                        bg=ed;
                        for(vector<int>::iterator it=save.begin();it!=save.end();it++)
                        {
                            vis[*it]=0;
                        }
                        save.clear();
                        goto ne;
                    }
                    vis[a[ed]]=1;
                    save.push_back(a[ed]);
                }
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}