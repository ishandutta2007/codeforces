#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=505;

int n, m, k;
char a[N][N];
int star[N][N], sum[N][N];
int dx[5]={0, 0, 0, +1, -1};
int dy[5]={0, +1, -1, 0, 0};

int32_t main()
{
    IOS;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int check=1;
            for(int dir=0;dir<5;dir++)
            {
                check&=(a[i+dx[dir]][j+dy[dir]]=='1');
            }
            star[i][j]=check;
            sum[i][j]=sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1] + star[i][j];
        }
    }
    int ans=0;
    for(int p=2;p<=n-1;p++)
    {
        for(int r=p;r<=n-1;r++)
        {
            int s=2;
            for(int q=2;q<=m-1;q++)
            {
                while(s<=m-1 && sum[r][s] - sum[r][q-1] - sum[p-1][s] + sum[p-1][q-1] < k)
                    s++;
                ans+=m-s;
            }
        }
    }
    cout<<ans;
    return 0;
}