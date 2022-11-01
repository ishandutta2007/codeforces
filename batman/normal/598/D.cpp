#include <bits/stdc++.h>
using namespace std;
#define INF ((ll)1e9)
#define N (1111)
#define ll long long
#define ld long double
#define PI ((ld)3.141592)
inline ll tavan(ll a,ll n) {ll p=1;while(n>0){if(n%2){p=p*a;}n>>=1;a*=a;a;}return p;}

ll n,m,k,p,ans[N][N];
string s[N];
bool mark[N][N],mark2[N][N];

ll check(ll x,ll y)
{
    if(x<0 || y<0 || x>=n || y>=m)
        return -1;
    if(s[x][y]=='*')
        return 0;   
    return 1;   
}

void dfs(ll x,ll y)
{
    //cout<<x<<" "<<y<<endl;
    mark[x][y]=1;
    p+=(check(x-1,y)==0);
    p+=(check(x+1,y)==0);
    p+=(check(x,y-1)==0);
    p+=(check(x,y+1)==0);
    if(check(x-1,y)==1 && !mark[x-1][y])dfs(x-1,y);
    if(check(x+1,y)==1 && !mark[x+1][y])dfs(x+1,y);
    if(check(x,y-1)==1 && !mark[x][y-1])dfs(x,y-1);
    if(check(x,y+1)==1 && !mark[x][y+1])dfs(x,y+1); 
}

void dfs2(ll x,ll y)
{
    mark2[x][y]=1;
    ans[x][y]=p;
    if(check(x-1,y)==1 && !mark2[x-1][y])dfs2(x-1,y);
    if(check(x+1,y)==1 && !mark2[x+1][y])dfs2(x+1,y);
    if(check(x,y-1)==1 && !mark2[x][y-1])dfs2(x,y-1);
    if(check(x,y+1)==1 && !mark2[x][y+1])dfs2(x,y+1);
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    for(int i=0;i<n;i++)cin>>s[i];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(!mark[i][j] && s[i][j]!='*')
            {
                p=0;
                dfs(i,j);
                //cout<<p<<endl;
                dfs2(i,j);
            }
            
    while(k--)
    {
        ll x,y;
        cin>>x>>y;
        cout<<ans[x-1][y-1]<<endl;
    }               
    return 0;
}