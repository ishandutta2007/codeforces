#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=105;

int n;
char a[N][N];
int row[N], col[N];

int32_t main()
{
    IOS;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
            if(a[i][j]=='.')
                row[i]++, col[j]++;
        }
    }
    int checkrow=1, checkcol=1;
    for(int i=1;i<=n;i++)
    {
        checkrow&=(row[i]>0);
        checkcol&=(col[i]>0);
    }
    if(!(checkrow||checkcol))
    {
        cout<<"-1";
        return 0;
    }
    if(checkrow)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(a[i][j]=='.')
                {
                    cout<<i<<" "<<j<<endl;
                    break;
                }
            }
        }
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(a[j][i]=='.')
                {
                    cout<<j<<" "<<i<<endl;
                    break;
                }
            }
        }
    }
    return 0;
}