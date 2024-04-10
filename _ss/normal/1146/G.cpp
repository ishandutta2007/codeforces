#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const ll N=1e5+10,mod=1e9+7,inf=1e18;

struct ds {int l,r,x,c; };
int dp[60][60][60],n,h,m;
ds a[N];

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>h>>m;
    for (int i=1;i<=m;i++) cin>>a[i].l>>a[i].r>>a[i].x>>a[i].c;
    for (int len=1;len<=n;len++)
        for (int l=1;l<=n-len+1;l++)
        {
            int r=l+len-1;
            for (int v=1;v<=h;v++)
            {
                dp[l][r][v]=dp[l][r][v-1];
                for (int mid=l;mid<=r;mid++)
                {
                    int fine=0;
                    for (int i=1;i<=m;i++)
                        if (l<=a[i].l && a[i].r<=r && v>a[i].x && a[i].l<=mid && a[i].r>=mid) fine+=a[i].c;
                    dp[l][r][v]=max(dp[l][r][v],dp[l][mid-1][v]+dp[mid+1][r][v]+v*v-fine);
                }
            }
        }
    cout<<max(dp[1][n][h],0);
    return 0;
}