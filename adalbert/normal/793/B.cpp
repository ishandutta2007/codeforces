#include <bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
typedef long long ll;
#define files(name) freopen(name".sol","r",stdin); freopen (name".dat","w",stdout);
#pragma GCC optimize ("O3")
#define time pdojegoritg
typedef long double ld;

bool a[2000][2000],use[2000][2000][6][6];
vector<pair<int,int> > go;
void dfs(int x, int y, int way, int cnt)
{
    if (cnt==3) return;
    use[x][y][way][cnt]=1;
    for (int i=1;i<=4;i++)
        if (i==way)
        {
            if (a[x+go[i-1].fir][y+go[i-1].sec] &&!use[x+go[i-1].fir][y+go[i-1].sec][i][cnt])
                dfs(x+go[i-1].fir,y+go[i-1].sec,i,cnt);
        } else
        if (abs(i-way)!=2)
        {
            if (a[x+go[i-1].fir][y+go[i-1].sec] &&!use[x+go[i-1].fir][y+go[i-1].sec][i][cnt+1])
                dfs(x+go[i-1].fir,y+go[i-1].sec,i,cnt+1);
        }
}

signed main()
{
    int n=0,m=0;
    cin >> n >> m;
    int si=0, sj=0, fi=0, fj=0;
    for (int i=1;i<=n;i++)
    {
        string st="";
        cin >> st;
        for (int j=1;j<=m;j++)
            if (st[j-1]!='*')
            a[i][j]=1;
        for (int j=1;j<=m;j++)
            if (st[j-1]=='S')
            {
                si=i;
                sj=j;
            } else
            if (st[j-1]=='T')
            {
                fi=i;
                fj=j;
            }
    }

    go.pb({1,0});
    go.pb({0,1});
    go.pb({-1,0});
    go.pb({0,-1});
    dfs(si,sj,1,0);
    dfs(si,sj,2,0);
    dfs(si,sj,3,0);
    dfs(si,sj,4,0);

    for (int way=1;way<=4;way++)
        for (int cnt=0;cnt<=2;cnt++)
        if (use[fi][fj][way][cnt])
    {
        cout << "YES";
        return(0);
    }
    cout << "NO";

}