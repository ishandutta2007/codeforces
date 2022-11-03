#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define m_p make_pair
#define get leirogoerg
#define files(s) freopen(s".in","r",stdin); freopen(s".out","w",stdout);
#define left dogjreg
#define right dgfdogjreg
typedef long long ll;
typedef double ld;
const int arr=2e5+1000;

int a[20][20][20][20];

signed main()
{
    for (int i=1;i<=3;i++)
    {
        string st;
        for (int j=1;j<=3;j++)
        {
            for (int k=1;k<=3;k++)
            {
                cin>>st;
                for (int l=1;l<=3;l++)
                    a[i][k][j][l]=st[l-1];
            }
        }

    }

    int x,y;
    cin>>x>>y;
    x--;
    y--;
    x%=3;
    y%=3;
    x++;
    y++;

    int cnt=0;
    for (int i=1;i<=3;i++)
        for (int j=1;j<=3;j++)
        if (a[x][y][i][j]=='.')
        cnt++;


    for (int i=1;i<=3;i++)
    {
        for (int j=1;j<=3;j++)
        {
            for (int k=1;k<=3;k++)
            {
                for (int l=1;l<=3;l++)
                {
                    if (a[i][k][j][l]=='.' && (i==x && k==y || (cnt==0)))
                        cout<<'!'; else
                        cout<<char(a[i][k][j][l]);
                }
                cout<<' ';
            }
            cout<<'\n';
        }
        cout<<'\n';
    }
}