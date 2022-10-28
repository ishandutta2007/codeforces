#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=1e5+5;
const int M=(1LL<<20);

int n, ans=0;
int a[N], f[M], nxt[21][N];

void work(int k)
{
    if(f[a[k]]==0)
        ans++;
    f[a[k]]|=1;
    int cur=a[k], idx=k;
    while(true)
    {
        int next=n+1, store=0;
        for(int j=0;j<20;j++)
        {
            if(cur&(1LL<<j))
                continue;
            if(nxt[j][idx]<next)
            {
                next=nxt[j][idx];
                store=a[next];
            }
        }
        if(next==n+1)
            break;
        idx=next;
        cur=(cur|store);
        if(f[cur]==0)
            ans++;
        f[cur]|=1;
    }
}

int32_t main()
{
    IOS;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=n;i>=1;i--)
    {
        for(int j=0;j<20;j++)
        {
            if(a[i]&(1<<j))
                nxt[j][i]=i;
            else
                nxt[j][i]=nxt[j][i+1];
            if(!nxt[j][i])
                nxt[j][i]=n+1;
        }
    }
    for(int i=1;i<=n;i++)
        work(i);
    cout<<ans;
    return 0;
}