#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N=102;

int n,m,k;
int a[N][N];
int p[N][N];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("river.in","r",stdin);
    //freopen("river.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
            cin>>a[i][j];
    }
    for(int j=1;j<=m;++j)
    {
        for(int i=1;i<=n;++i)
            p[i][j]=p[i-1][j]+a[i][j];
    }
    int ans1=0,ans2=0;
    for(int j=1;j<=m;++j)
    {
        int maxu=0,maxi;
        for(int i=1;i<=n;++i)
        {
            if(!a[i][j])
                continue;
            int r=min(n,i+k-1);
            if(p[r][j]-p[i-1][j]>maxu)
            {
                maxu=p[r][j]-p[i-1][j];
                maxi=i;
            }
        }
        if(!maxu)
            continue;
        ans1+=maxu;
        ans2+=p[maxi-1][j];
    }
    cout<<ans1<<' '<<ans2;
    return 0;
}