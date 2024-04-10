//100gods

#include <bits/stdc++.h>
//#define int long long
#define vec2 vector<vector<int>>
#define fio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define FRE freopen("elegant.in","r",stdin);freopen("elegant.out","w",stdout)
#define pii pair <int,int>
#define vii vector <int>
#define vpii vector <pii>
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define minii LLONG_MAX
#define all(x) x.begin(), x.end()
#define mem(a,b) memset(a,b,sizeof(a))
#define double long double
#define eb emplace_back
const double pi = 3.1415926535898;
const int mod=1e9+7;
//const int mod=998244353;

using namespace std;

int n,m,k;
int a[1001][1001];

int solve(int x,int y)
{
    if (x==n)
    {
        return y;
    }
    if (a[x][y]==2)
    {
        a[x][y]=2;
        return solve(x+1,y);

    }
    if (a[x][y]==1)
    {
        a[x][y]=2;
        return solve(x,y+1);
    }
    if (a[x][y]==3)
    {
        a[x][y]=2;
        return solve(x,y-1);
    }
    return -1;
}

int32_t main()
{
    fio;
    cin>>n>>m>>k;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    int b[k];
    for (int i=0;i<k;i++)
    {
        cin>>b[i];
        cout<<solve(0,b[i]-1)+1<<" ";
    }
    return 0;
}