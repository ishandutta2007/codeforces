////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.1 //////////////////
////////////////////////////////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;
#define what_is(x) cerr << #x << " is " << x << endl;
#define INF (1000*1000*1000)
#define N 100*1001
#define ll long long
ll tavan(ll a,ll b){int p=1;for(int i=0;i<b;i++)p*=a;return p;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}
ifstream fin("input.txt");
ofstream fout("output.txt");
int n,m,p,q,tool;
string s[55];
bool mark[55][55];

void dfs(int x,int y)
{
    if(x<0 || x>n || y<0 || y>m)
        return ;
    mark[x][y]=true;
    tool++; 
    for(int i=-1;i<=1;i+=2)
    {
        if(x+i==p && y==q && tool>3)
        {
            cout<<"Yes";
            exit(0);
        }
        if(x+i>=0 && x+i<n && s[x][y]==s[x+i][y] && mark[x+i][y]==false)
        {
            dfs(x+i,y);
            tool--;
        }
            
    }
    for(int i=-1;i<=1;i+=2)
    {
        if(x==p && y+i==q && tool>3)
        {
            cout<<"Yes";
            exit(0);
        }
        if(y+i>=0 && y+i<m && s[x][y]==s[x][y+i] && mark[x][y+i]==false)
        {
            dfs(x,y+i);
            tool--;
        }
            
    }
    mark[x][y]=false;
    
            
}


int main()
{
    
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>s[i];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            p=i;
            q=j;
            tool=0;
            dfs(i,j);
        }
    }   
    cout<<"No"; 
    return 0;
}