#include <bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen (name".out","w",stdout);
#define time pdojegoritg
#define left eorgjrptgj
#define right rtyjtokh
typedef long long ll;

int dp[110][110][30];

vector<pair<int,int> > vec[110];

bool is_win(int i, int j, int c)
{
    if (dp[i][j][c]!=-1)
        return(dp[i][j][c]);
    dp[i][j][c]=0;
    for (auto to:vec[i])
        if (to.sec>=c)
        dp[i][j][c]|=!is_win(j,to.fir,to.sec);
    return(dp[i][j][c]);
}

signed main()
{
    int n,m;
    cin>>n>>m;

    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        for (int c=0;c<30;c++)
        dp[i][j][c]=-1;

    while (m--)
    {
        int u,v;
        char c;
        cin>>u>>v>>c;
        vec[u].pb({v,c-'a'+1});
    }

    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        if (is_win(i,j,0))
            cout<<'A'; else
            cout<<'B';
        cout<<'\n';
    }
}