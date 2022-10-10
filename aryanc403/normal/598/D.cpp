/************************************************************************************************************************************************************************************
 *                                                                                                                                                                                  *
 *                                                                                                                                                                                  *
 *  ****************    **************    *               *    ****************    *           *    ****************    *              *    ****************    ****************    *
 *  *              *    *            *    *               *    *              *    **          *    *                   *              *    *              *                   *    *
 *  *              *    *            *    *               *    *              *    * *         *    *                   *              *    *              *                   *    *
 *  *              *    *            *    *               *    *              *    *  *        *    *                   *              *    *              *                   *    *
 *  *              *    *            *    *               *    *              *    *   *       *    *                   *              *    *              *                   *    *
 *  *              *    *            *    *               *    *              *    *    *      *    *                   *              *    *              *                   *    *
 *  ****************    **************    *****************    ****************    *     *     *    *                   ****************    *              *    ****************    *
 *  *              *    *  *                      *            *              *    *      *    *    *                                  *    *              *                   *    *
 *  *              *    *    *                    *            *              *    *       *   *    *                                  *    *              *                   *    *
 *  *              *    *      *                  *            *              *    *        *  *    *                                  *    *              *                   *    *
 *  *              *    *        *                *            *              *    *         * *    *                                  *    *              *                   *    *
 *  *              *    *          *              *            *              *    *          **    *                                  *    *              *                   *    *
 *  *              *    *            *            *            *              *    *           *    ****************                   *    ****************    ****************    *
 *                                                                                                                                                                                  *
 *                                                                                                                                                                                  *
 ************************************************************************************************************************************************************************************/

#include<iostream>
#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
#define fo(i,n)   for(i=0;i<(n);++i)
#define LLI long long int
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define MAX 1000002
typedef long long int lli;
typedef pair<lli,lli> ii;
typedef vector<ii> vii;
typedef vector<lli> vi;
const lli INF = 0xFFFFFFFFFFFFFFFL;
const lli MOD = 1000000007L;
    lli T,n,in,i,m,j,k,ansa[1005][1005];
    vi :: iterator it;
    char s[1005][1005];
    lli cnt;
    queue < pair<lli,lli> > q;
    bool vis[1005][1005];

void ans(lli x,lli y)
{
    if(vis[x][y])
        return;
    vis[x][y]=true;
    if(s[x][y]=='*')
    {
        return;
    }
    q.push(mp(x,y));
    if(x-1>=0&&x-1<n&&y>=0&&y<m&&vis[x-1][y]==false)
    {
        if(s[x-1][y]=='*')
            cnt++;
        else
            ans(x-1,y);
    }
    if(x>=0&&x<n&&y-1>=0&&y-1<m&&vis[x][y-1]==false)
    {
        if(s[x][y-1]=='*')
            cnt++;
        else
            ans(x,y-1);
    }
    if(x+1>=0&&x+1<n&&y>=0&&y<m&&vis[x+1][y]==false)
    {
        if(s[x+1][y]=='*')
            cnt++;
        else
            ans(x+1,y);
    }
    if(x>=0&&x<n&&y+1>=0&&y+1<m&&vis[x][y+1]==false)
    {
        if(s[x][y+1]=='*')
            cnt++;
        else
            ans(x,y+1);
    }
}

void solve(lli x,lli y)
{
    if(ansa[x][y])
        return;
    while(q.empty()==false) q.pop();
    cnt=0;
    ans(x,y);
    q.push(mp(x,y));
    
    while(q.empty()==false)
    {
        ii a=q.front();
        ansa[a.X][a.Y]=cnt;
        q.pop();
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m>>k;
    //cout<<n<<m<<k<<endl;
    fo(i,n)
    {
        cin>>s[i];
        //cout<<s[i]<<endl;
    }
    
    lli x,y;
    
    while(k--)
    {
        cin>>x>>y;
        x--;
        y--;
        solve(x,y);
        cout<<ansa[x][y]<<endl;
    }
    
    return 0;
}