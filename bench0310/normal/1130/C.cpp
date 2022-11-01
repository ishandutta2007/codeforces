#include <bits/stdc++.h>

using namespace std;

int n;
int w[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

bool in(int r,int c)
{
    if(r<0||c<0||r>=n||c>=n) return 0;
    return 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    a--; b--; c--; d--;
    vector<string> s(n);
    for(int i=0;i<n;i++) cin >> s[i];
    bool vis[n][n];
    for(int o=0;o<n;o++) for(int i=0;i<n;i++) vis[o][i]=0;
    queue<int> q;
    q.push(a);
    q.push(b);
    vis[a][b]=1;
    while(!q.empty())
    {
        int e=q.front();
        q.pop();
        int f=q.front();
        q.pop();
        if(e==c&&f==d)
        {
            cout << 0 << endl;
            return 0;
        }
        for(int i=0;i<4;i++)
        {
            if(in(e+w[i][0],f+w[i][1])&&s[e+w[i][0]][f+w[i][1]]=='0')
            {
                if(vis[e+w[i][0]][f+w[i][1]]==0)
                {
                    q.push(e+w[i][0]);
                    q.push(f+w[i][1]);
                    vis[e+w[i][0]][f+w[i][1]]=1;
                }
            }
        }
    }
    bool dist[n][n];
    for(int o=0;o<n;o++) for(int i=0;i<n;i++) dist[o][i]=0;
    q.push(c);
    q.push(d);
    dist[c][d]=1;
    while(!q.empty())
    {
        int e=q.front();
        q.pop();
        int f=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            if(in(e+w[i][0],f+w[i][1])&&s[e+w[i][0]][f+w[i][1]]=='0')
            {
                if(dist[e+w[i][0]][f+w[i][1]]==0)
                {
                    q.push(e+w[i][0]);
                    q.push(f+w[i][1]);
                    dist[e+w[i][0]][f+w[i][1]]=1;
                }
            }
        }
    }
    int res=1000000000;
    for(int o=0;o<n;o++)
    {
        for(int i=0;i<n;i++)
        {
            for(int e=0;e<n;e++)
            {
                for(int f=0;f<n;f++)
                {
                    if(vis[o][i]&&dist[e][f]) res=min(res,(e-o)*(e-o)+(f-i)*(f-i));
                }
            }
        }
    }
    cout << res << endl;
    return 0;
}