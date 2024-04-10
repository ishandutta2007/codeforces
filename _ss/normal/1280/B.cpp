#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const ll N=1e5+10,mod=1e9+7,inf=1e18;
int a[110][110],m,n;
int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        cin>>m>>n;
        int check=1,check2=1;
        for (int i=1;i<=m;i++)
        {
            char ch;
            for (int j=1;j<=n;j++)
            {
                cin>>ch;
                a[i][j]=(ch=='A');
                if (a[i][j]) check=0;
                else check2=0;
            }
        }
        if (check)
        {
            cout<<"MORTAL\n";
            continue;
        }
        if (check2)
        {
            cout<<"0\n";
            continue;
        }
        int sl=0;
        for (int i=1;i<=n;i++) sl+=a[1][i];
        if (sl==n) check=1;
        sl=0;
        for (int i=1;i<=n;i++) sl+=a[m][i];
        if (sl==n) check=1;
        sl=0;
        for (int i=1;i<=m;i++) sl+=a[i][1];
        if (sl==m) check=1;
        sl=0;
        for (int i=1;i<=m;i++) sl+=a[i][n];
        if (sl==m) check=1;
        if (check)
        {
            cout<<"1\n";
            continue;
        }
        if (a[1][1] || a[1][n] || a[m][1] || a[m][n]) check=1;
        for (int i=1;i<=m;i++)
        {
            sl=0;
            for (int j=1;j<=n;j++) sl+=a[i][j];
            if (sl==n) check=1;
        }
        for (int j=1;j<=n;j++)
        {
            sl=0;
            for (int i=1;i<=m;i++) sl+=a[i][j];
            if (sl==m) check=1;
        }
        if (check)
        {
            cout<<"2\n";
            continue;
        }
        sl=0;
        for (int i=1;i<=n;i++) sl+=a[1][i];
        if (sl!=0) check=1;
        sl=0;
        for (int i=1;i<=n;i++) sl+=a[m][i];
        if (sl!=0) check=1;
        sl=0;
        for (int i=1;i<=m;i++) sl+=a[i][1];
        if (sl!=0) check=1;
        sl=0;
        for (int i=1;i<=m;i++) sl+=a[i][n];
        if (sl!=0) check=1;
        if (check) cout<<"3\n"; else cout<<"4\n";
    }
    return 0;
}