#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,t;
    cin >> n >> m >> t;
    vector<string> s(n);
    for(int i=0;i<n;i++) cin >> s[i];
    vector<array<int,2>> z={{1,0},{-1,0},{0,-1},{0,1}};
    auto in=[&](int r,int c)->bool{return (0<=r&&r<n&&0<=c&&c<m);};
    vector opt(n,vector(m,bool(1)));
    const ll inf=(1ll<<60);
    vector d(n,vector(m,ll(inf)));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            for(auto [di,dj]:z)
            {
                int ni=i+di;
                int nj=j+dj;
                if(in(ni,nj)&&s[ni][nj]==s[i][j]) opt[i][j]=0;
            }
            if(opt[i][j]) continue;
            for(auto [di,dj]:z)
            {
                int ni=i+di;
                int nj=j+dj;
                if(in(ni,nj)) d[ni][nj]=1;
            }
        }
    }
    queue<array<int,2>> q;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(opt[i][j]&&d[i][j]==1) q.push({i,j});
    while(!q.empty())
    {
        auto [r,c]=q.front();
        q.pop();
        for(auto [dr,dc]:z)
        {
            int nr=r+dr;
            int nc=c+dc;
            if(in(nr,nc)&&opt[nr][nc]&&d[nr][nc]==inf)
            {
                d[nr][nc]=d[r][c]+1;
                q.push({nr,nc});
            }
        }
    }
    while(t--)
    {
        int r,c;
        ll p;
        cin >> r >> c >> p;
        r--; c--;
        if(!opt[r][c]) cout << char('0'+((s[r][c]-'0'+p)&1)) << "\n";
        else
        {
            if(p<=d[r][c]) cout << s[r][c] << "\n";
            else cout << char('0'+((s[r][c]-'0'+p-d[r][c])&1)) << "\n";
        }
    }
    return 0;
}