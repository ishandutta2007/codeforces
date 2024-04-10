#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define m_p make_pair
#define get leirogoerg
#define files(s) freopen(s".in","r",stdin); freopen(s".out","w",stdout);
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pii;
typedef vector <pii> vii;
const ld pi = acos(-1);
const int arr = 4*1e5+100;
const ll md = 1e9+7;
const ll base=31;
const int AaA = 'a'-'A';
ld eps=1e-7;
#define int ll
int a[500][500],b[500][500];
string st[500];

int dp[17][2][40000][3][3];

signed main()
{
    int n,m;
    cin>>n>>m;
    /*if (n>9 || m>9)
        exit(1);*/
    for (int i=1;i<=n;i++)
    {
        cin>>st[i];
        for (int j=1;j<=m;j++)
            a[i][j]=(st[i][j-1]=='x');
    }

    if (n>m)
    {
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                b[j][i]=a[i][j];
        swap(n,m);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                a[i][j]=b[i][j];
    }

    dp[1][1][0][0][0]=1;

    int mxmask=(1<<n);

    for (int j=1;j<=m;j++)
    {
        for (int i=1;i<n;i++)
            for (int mask=0;mask<mxmask;mask++)
            for (int up=0;up<=1;up++)
            {
                if (dp[i][j%2][mask][0][up]==0 && dp[i][j%2][mask][1][up]==0) continue;

                if (a[i][j])
                {
                    int nmask=mask/2;
                    dp[i+1][j%2][nmask][0][0]+=dp[i][j%2][mask][0][up];
                    dp[i+1][j%2][nmask][1][0]+=dp[i][j%2][mask][1][up];
                    dp[i+1][j%2][nmask][0][0]%=md;
                    dp[i+1][j%2][nmask][1][0]%=md;
                } else
                if (mask%2)
                {
                    int nmask=mask/2+(1<<(n-1));
                    dp[i+1][j%2][nmask][0][up]+=dp[i][j%2][mask][0][up]%md;
                    dp[i+1][j%2][nmask][1][up]+=dp[i][j%2][mask][1][up]%md;
                    dp[i+1][j%2][nmask][0][1]+=dp[i][j%2][mask][0][up]%md;
                    dp[i+1][j%2][nmask][1][1]+=dp[i][j%2][mask][1][up]%md;
                    dp[i+1][j%2][nmask][0][up]%=md;
                    dp[i+1][j%2][nmask][1][up]%=md;
                    dp[i+1][j%2][nmask][0][1]%=md;
                    dp[i+1][j%2][nmask][1][1]%=md;


                } else
                if (up)
                {
                    int nmask=mask/2;
                    dp[i+1][j%2][nmask][0][up]+=dp[i][j%2][mask][0][up]%md;
                    dp[i+1][j%2][nmask][1][up]+=dp[i][j%2][mask][1][up]%md;
                    dp[i+1][j%2][nmask][0][up]%=md;
                    dp[i+1][j%2][nmask][1][up]%=md;

                    nmask=mask/2+(1<<(n-1));
                    dp[i+1][j%2][nmask][0][up]+=dp[i][j%2][mask][0][up]%md;
                    dp[i+1][j%2][nmask][1][up]+=dp[i][j%2][mask][1][up]%md;
                    dp[i+1][j%2][nmask][0][up]%=md;
                    dp[i+1][j%2][nmask][1][up]%=md;
                } else
                {
                    int nmask=mask/2+(1<<(n-1));
                    dp[i+1][j%2][nmask][0][1]+=dp[i][j%2][mask][0][0];
                    dp[i+1][j%2][nmask][1][1]+=dp[i][j%2][mask][1][0];
                    dp[i+1][j%2][nmask][0][1]%=md;
                    dp[i+1][j%2][nmask][1][1]%=md;
                    nmask=mask/2;
                    dp[i+1][j%2][nmask][1][0]+=dp[i][j%2][mask][0][0];
                    dp[i+1][j%2][nmask][1][0]%=md;
                }
            }
        for (int mask=0;mask<mxmask;mask++)
            for (int up=0;up<=1;up++)
            {
                if (dp[n][j%2][mask][0][up]==0 && dp[n][j%2][mask][1][up]==0) continue;
                //cout<<n<<' '<<j<<' '<<mask<<'!'<<'\n';
                    if (a[n][j])
                    {
                        int nmask=mask/2;
                        dp[1][(j+1)%2][nmask][0][0]+=dp[n][j%2][mask][0][up];
                        dp[1][(j+1)%2][nmask][0][0]%=md;
                        dp[1][(j+1)%2][nmask][1][0]+=dp[n][j%2][mask][1][up];
                        dp[1][(j+1)%2][nmask][1][0]%=md;
                    } else
                    if (mask%2)
                    {
                        int nmask=mask/2+(1<<(n-1));
                        dp[1][(j+1)%2][nmask][0][0]+=2*dp[n][j%2][mask][0][up]%md;
                        dp[1][(j+1)%2][nmask][1][0]+=2*dp[n][j%2][mask][1][up]%md;
                        dp[1][(j+1)%2][nmask][0][0]%=md;
                        dp[1][(j+1)%2][nmask][1][0]%=md;
                    } else
                    if (up)
                    {
                        int nmask=mask/2;
                        dp[1][(j+1)%2][nmask][0][0]+=dp[n][j%2][mask][0][up];
                        dp[1][(j+1)%2][nmask][1][0]+=dp[n][j%2][mask][1][up];
                        dp[1][(j+1)%2][nmask][0][0]%=md;
                        dp[1][(j+1)%2][nmask][1][0]%=md;
                        nmask=mask/2+(1<<(n-1));
                        dp[1][(j+1)%2][nmask][0][0]+=dp[n][j%2][mask][0][up];
                        dp[1][(j+1)%2][nmask][1][0]+=dp[n][j%2][mask][1][up];
                        dp[1][(j+1)%2][nmask][0][0]%=md;
                        dp[1][(j+1)%2][nmask][1][0]%=md;

                    } else
                    {
                        int nmask=mask/2+(1<<(n-1));
                        dp[1][(j+1)%2][nmask][0][0]+=dp[n][j%2][mask][0][up];
                        dp[1][(j+1)%2][nmask][1][0]+=dp[n][j%2][mask][1][up];
                        dp[1][(j+1)%2][nmask][0][0]%=md;
                        dp[1][(j+1)%2][nmask][1][0]%=md;
                        nmask=mask/2;
                        dp[1][(j+1)%2][nmask][1][0]+=dp[n][j%2][mask][0][up];
                        dp[1][(j+1)%2][nmask][1][0]%=md;
                    }
            }
        for (int i=1;i<=n;i++)
            for (int mask=0;mask<mxmask;mask++)
                for (int up=0;up<=1;up++)
                {
                    dp[i][j%2][mask][0][up]=0;
                    dp[i][j%2][mask][1][up]=0;
                }
    }

    //cout<<dp[1][2][1][0][0]<<'\n';

    int ans=0;

    for (int mask=0;mask<mxmask;mask++)
    {
         ans+=(dp[1][(m+1)%2][mask][0][0]+dp[1][(m+1)%2][mask][1][0])%md;
         ans%=md;
    }

    cout<<ans;
}