//////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.1.3 /////////////////
////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;
#define Sa1378 main()
#define chie(x) cerr << #x << " is " << x << endl;
#define INF 1e9
#define N (1100)
#define ll long long
#define ld long double
#define ST setprecision
#define MP make_pair
#define PB push_back
#define IB ios_base::sync_with_stdio(0);
const ll MOD=1e9+7;
ll tavan(ll a,ll b){int p=1;for(int i=0;i<b;i++)p*=a;return p;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}
//bool sortt(int x,int y){ return a[x] > a[y]; }
int mark[N][N];
int n,a[N],sumy,sumx,maxx,minx;
int Sa1378
{ 
    IB
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(i%2)
            sumx-=a[i]-1;
        else
            sumx+=a[i]-1;   
        sumy+=a[i]; 
        maxx=max(sumx,maxx);
        minx=min(sumx,minx);
    }
    int x=maxx,y=0;
    for(int i=0;i<n;i++)
    {
        int plus=-1;
        if(i%2)
            plus=1;
        for(int j=0;j<a[i];j++)
        {
            if(i%2)
                mark[x][y]=2;
            else
                mark[x][y]=1;
            if(j!=a[i]-1)       
                x+=plus;
            y++;
        }   
    }
    for(int i=0;i<=maxx-minx;i++)
    {
        for(int j=0;j<sumy;j++)
        {
            if(mark[i][j]==1)
                cout<<'/';
            else if(mark[i][j]==2)
                cout<<(char)92;
            else
                cout<<" ";
        }   
        cout<<"\n";             
    }
    
        
    return 0;
}