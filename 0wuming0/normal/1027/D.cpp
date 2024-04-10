#include"bits/stdc++.h"
using namespace std;
#define ll long long
int c[200005];
int m[200005];
int r[200005];
int ans[200005];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%d",c+i);
    for(int i=1;i<=n;i++)
        scanf("%d",m+i);
    for(int i=1;i<=n;i++)
    {
        int now=i;
        ppp:
        if(r[now]==0)r[now]=-i;
        else if(r[now]==-i)
        {
            while(r[now]!=i)
            {
                r[now]=i;
                now=m[now];
            }
            continue;
        }
        else
        {
            continue;
        }
        now=m[now];
        goto ppp;
    }
    for(int i=1;i<=n;i++)
    {
        if(r[i]>0)
        {
            if(ans[r[i]]==0)ans[r[i]]=c[i];
            else ans[r[i]]=min(ans[r[i]],c[i]);
        }
    }
    int sum=0;
    for(int i=1;i<=n;i++)sum+=ans[i];
    cout<<sum<<endl;
    return 0;
}