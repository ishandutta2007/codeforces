//////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.1.3 /////////////////
////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;
#define Sa1378 main()
#define chie(x) cerr << #x << " is " << x << endl;
#define INF (1000*1000*1000)
#define N (2200)
#define ll long long
#define ld long double
#define ST setprecision
#define MP make_pair
#define PB push_back
#define MOD (ll)1e9+7
#define IB ios_base::sync_with_stdio(0);
ll tavan(ll a,ll b){int p=1;for(int i=0;i<b;i++)p*=a;return p;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}
//bool sortt(int x,int y){ return a[x] > a[y]; }
ofstream fout("output.txt");

int n,m;
char a[N][N];

void dfs(int x,int y)
{
    if(x<0 || y<0 || x>=n-1 || y>=m-1)
        return ;
    int ex=0;   
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            if(a[x+i][y+j]=='*')
                ex++;
    if(ex==1)
    {
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                a[x+i][y+j]='.';
        for(int i=-1;i<2;i++)
            for(int j=-1;j<2;j++)   
                dfs(x+i,y+j);   
    }
}

int Sa1378
{ 
    IB
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>a[i][j];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            dfs(i,j);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cout<<a[i][j];
        cout<<"\n"; 
    }
                        
    return 0;
}