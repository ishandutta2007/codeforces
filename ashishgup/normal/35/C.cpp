#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2005;

int n, m, k;
bool vis[N][N];
pair<int, int> last;
queue<pair<int, int> > q;
int dx[4]={0, 0, +1, -1};
int dy[4]={+1, -1, 0, 0};

int32_t main()
{
    IOS;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=k;i++)
    {
        int x, y;
        cin>>x>>y;
        vis[x][y]=1;
        q.push({x, y});
    }
    while(!q.empty())
    {
        pair<int, int> p=q.front();
        q.pop();
        last=p;
        for(int k=0;k<4;k++)
        {
            int x=p.first+dx[k];
            int y=p.second+dy[k];
            if(x>=1&&x<=n&&y>=1&&y<=m)
            {
                if(vis[x][y]!=1)
                {
                    vis[x][y]=1;
                    q.push({x, y});
                }
            }
        }
    }
    cout<<last.first<<" "<<last.second;
    return 0;
}