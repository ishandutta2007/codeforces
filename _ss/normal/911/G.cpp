#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")
 
#include<bits/stdc++.h>
 
using namespace std;
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const ll maxn=2e5,mod=1e9+7,inf=1e18;
int n,ans[maxn+10];
unsigned int a[101][6500];
int main()
{
    //freopen("ss.inp","r",stdin);
    scanf("%d",&n);
    int l,r,x,y,q;
    for (int i=0;i<n;i++)
    {
        scanf("%d",&x);
        a[x][i/32] ^=1<<(i%32);
    }
    cin>>q;
    for (int i=1;i<=q;i++)
    {
        scanf("%d %d %d %d",&l,&r,&x,&y);
        if (x==y) continue;
        l--;
        r--;
        int gl=l/32,gr=r/32;
        if (gl==gr)
        {
            for (int j=l%32;j<=r%32;j++)
                if (a[x][gl] & (1<<j))
                {
                    a[x][gl] ^=1<<j;
                    a[y][gl] ^=1<<j;
                }
            continue;
        }
        for (int j=gl+1;j<gr;j++) a[y][j] ^=a[x][j],a[x][j]=0;
        for (int j=l%32;j<32;j++)
            if (a[x][gl] & (1<<j))
            {
                a[x][gl] ^=1<<j;
                a[y][gl] ^=1<<j;
            }
        for (int j=0;j<=r%32;j++)
            if (a[x][gr] & (1<<j))
            {
                a[x][gr] ^=1<<j;
                a[y][gr] ^=1<<j;
            }
    }
    for (int i=1;i<=100;i++)
        for (int j=0;j<n;j++)
            if (a[i][j/32] & (1<<(j%32))) ans[j+1]=i;
    for (int i=1;i<=n;i++) printf("%d ",ans[i]);
    return 0;
}