#include <bits/stdc++.h>
#define all(a) (a).begin(),(a).end()
#define ld long double
#define ll long long
#define sqr(a) (a)*(a)
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define inf (int)1e9
#define pi pair<int,int>
#define y1 fdfs
using namespace std;
inline void read(int &x){x = 0;while(1){char ch = getchar();if(ch==' '||ch=='\n') break;x = x*10 + ch - '0';}}
inline void write(int x){char wr[12];int k = 0;if(!x) ++k,wr[k] = '0';while(x){++k;wr[k] = char(x%10+'0');x/=10;}for(int i=k;i>=1;--i)putchar(wr[i]);}
const int N = 105;
int n,m,q,type,i,j,x;
int a[N][N],c[N][N];
pair<int,int> b[N][N];
int main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin>>n>>m>>q;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            a[i][j] = inf + 1,b[i][j] = mp(i,j);
    while(q--)
    {
        cin>>type;
        if(type==1)
        {
            cin>>i;
            int x = a[i][1];
            pi z = b[i][1];
            for(int j=1;j<m;++j)
                a[i][j] = a[i][j+1],b[i][j] = b[i][j+1];
            a[i][m] = x;
            b[i][m] = z;
        }
        if(type==2)
        {
            cin>>j;
            int x = a[1][j];
            pi z = b[1][j];
            for(int i=1;i<n;++i)
                a[i][j] = a[i+1][j],b[i][j] = b[i+1][j];
            a[n][j] = x;
            b[n][j] = z;
        }
        if(type==3)
        {
            cin>>i>>j>>x;
            a[i][j] = x;
        }
    }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
    {
        c[b[i][j].x][b[i][j].y] = a[i][j];
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            if(c[i][j]==inf+1) c[i][j] = 0;
            cout<<c[i][j]<<' ';
        }
        cout<<"\n";
    }
}