#include <bits/stdc++.h>
#define gibon ios::sync_with_stdio(false); cin.tie(0);
#define fir first
#define sec second
#define pdd pair<double, double>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pmax pair<__int128, __int128>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
typedef long long ll;
using namespace std;
int dx[4]= {0, 1, 0, -1}, dy[4]= {1, 0, -1, 0};
int ddx[8]={1, 1, 0, -1, -1, -1, 0, 1}, ddy[8]={0, 1, 1, 1, 0, -1, -1, -1};
const int mxN=55;
const int mxM=350;
const int mxK=105;
const ll MOD=10000000000;
const ll INF=1000000000000000005;
int N;
bool Chk1[22][360], Chk2[22][360];
pii par[22][360];
void init()
{
    for(int i=1;i<=21;i++)  for(int j=0;j<360;j++)  par[i][j]={i, j};
    for(int i=1;i<=21;i++)  for(int j=0;j<360;j++)  Chk1[i][j]=Chk2[i][j]=false;
}
pii findpar(int a, int b)
{
    if(par[a][b].fir==a && par[a][b].sec==b)    return {a, b};
    else    return findpar(par[a][b].fir, par[a][b].sec);
}
void onion(int x1, int y1, int x2, int y2)
{
    pii p=findpar(x1, y1), q=findpar(x2, y2);
    par[p.fir][p.sec]=q;
}
int main()
{
    gibon
    int T;
    cin >> T;
    while(T--)
    {
        init();
        cin >> N;
        for(int i=0;i<N;i++)
        {
            char typ;
            int a, b, c;
            cin >> typ >> a >> b >> c;
            if(typ=='C')
            {
                int now=b;
                while(true)
                {
                    Chk1[a][now]=true;
                    now=(now+1)%360;
                    if(now==c)  break;
                }
            }
            else
            {
                for(int j=a+1;j<=b;j++)
                {
                    Chk2[j][c]=true;
                }
            }
        }
        for(int i=1;i<=21;i++)
        {
            for(int j=0;j<360;j++)
            {
                if(i!=21 && !Chk1[i][j])
                {
                    onion(i, j, i+1, j);
                }
                if(!Chk2[i][j])
                {
                    onion(i, (j+359)%360, i, j);
                }
            }
        }
        if(findpar(1, 0)==findpar(21, 0))   cout << "YES\n";
        else    cout << "NO\n";
    }
}