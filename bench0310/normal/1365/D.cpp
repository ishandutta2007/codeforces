#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        vector<string> s(n);
        for(int o=0;o<n;o++) cin >> s[o];
        auto in=[&](int o,int i)->bool{return (0<=o&&o<n&&0<=i&&i<m);};
        vector<array<int,2>> z={{1,0},{-1,0},{0,-1},{0,1}};
        for(int o=0;o<n;o++)
        {
            for(int i=0;i<m;i++)
            {
                if(s[o][i]!='B') continue;
                for(auto [a,b]:z)
                {
                    if(in(o+a,i+b)&&s[o+a][i+b]=='.') s[o+a][i+b]='#';
                }
            }
        }
        vector<vector<bool>> vis(n,vector<bool>(m,0));
        queue<array<int,2>> q;
        if(s[n-1][m-1]!='#')
        {
            q.push({n-1,m-1});
            vis[n-1][m-1]=1;
        }
        while(!q.empty())
        {
            auto [o,i]=q.front();
            q.pop();
            for(auto [a,b]:z)
            {
                if(in(o+a,i+b)&&s[o+a][i+b]!='#'&&vis[o+a][i+b]==0)
                {
                    vis[o+a][i+b]=1;
                    q.push({o+a,i+b});
                }
            }
        }
        bool ok=1;
        for(int o=0;o<n;o++)
        {
            for(int i=0;i<m;i++)
            {
                if(s[o][i]=='G'&&vis[o][i]==0) ok=0;
                if(s[o][i]=='B'&&vis[o][i]==1) ok=0;
            }
        }
        if(ok) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}