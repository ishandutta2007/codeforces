#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
typedef long long ll;
#define files(name) freopen(name".sol","r",stdin); freopen (name".dat","w",stdmn);
int dp[100][100][100];
vector<pair<int,int> > reb[100];
signed main()
{
    int n=0, k=0;
    cin >> n >> k;
    int m;
    cin>>m;
    while (m--)
    {
        int a=0,b=0,time=0;
        cin >> a >> b >> time;
        reb[a].pb({b,time});
    }
    for (int start=1;start<=n;start++)
        for (int fin=1;fin<=n;fin++)
        for (int cnt=2;cnt<=k;cnt++)
        dp[start][fin][cnt]=1e9;
    for (int siz=2;siz<=n;siz++)
        for (int cnt=1;cnt<=k;cnt++)
        {
            for (int i=1;i+siz-1<=n;i++)
                for (int j=0;j<reb[i].size();j++)
                {
                    int to=reb[i][j].fir;
                    int time=reb[i][j].sec;
                    if (to>i && to<=i+siz-1)
                        dp[i][i+siz-1][cnt+1]=min(dp[i][i+siz-1][cnt+1],min(dp[to][i+1][cnt],dp[to][i+siz-1][cnt])+time);
                }
            for (int i=siz;i<=n;i++)
                for (int j=0;j<reb[i].size();j++)
                {
                    int to=reb[i][j].fir;
                    int time=reb[i][j].sec;
                    if (to<i && to>=i-siz+1)
                        dp[i][i-siz+1][cnt+1]=min(dp[i][i-siz+1][cnt+1],min(dp[to][i-1][cnt],dp[to][i-siz+1][cnt])+time);
                }
        }
    int ans=1e9;
    for (int i=1;i<=n;i++)
    	for (int j=1;j<=n;j++)
    		ans=min(ans,dp[i][j][k]);
    if(ans==1e9) cout<<-1; else cout<<ans;
}