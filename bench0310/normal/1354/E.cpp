#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    int n1,n2,n3;
    cin >> n1 >> n2 >> n3;
    vector<int> v[n+1];
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    auto out=[]()
    {
        cout << "NO\n";
        exit(0);
    };
    if(n2==0)
    {
        if(m==0)
        {
            cout << "YES\n";
            cout << string(n1,'1')+string(n3,'3') << "\n";
            exit(0);
        }
        else out();
    }
    vector<int> vis(n+1,0);
    vector<vector<int>> one;
    vector<vector<int>> two;
    vector<vector<array<int,2>>> dp(n+1,vector<array<int,2>>(n+1,{0,0})); //id,color
    dp[0][0]={-1,1};
    int comp=0;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]!=0) continue;
        comp++;
        queue<int> q;
        q.push(i);
        vis[i]=1;
        vector<int> d[3];
        vector<int> cnt(3,0);
        d[1].push_back(i);
        cnt[1]=1;
        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            for(int to:v[x])
            {
                if(vis[to]==0)
                {
                    q.push(to);
                    vis[to]=3-vis[x];
                    d[vis[to]].push_back(to);
                    cnt[vis[to]]++;
                }
                else if(vis[to]==vis[x]) out();
            }
        }
        one.push_back(d[1]);
        two.push_back(d[2]);
        for(int j=0;j<=n;j++)
        {
            if(dp[comp-1][j][1]==0) continue;
            for(int k=1;k<=2;k++) if(dp[comp][j+cnt[k]][1]==0) dp[comp][j+cnt[k]]={(int)one.size()-1,k};
        }
    }
    if(dp[comp][n2][1]==0) out();
    string res(n+1,'0');
    int c=comp;
    int now=n2;
    while(now>0)
    {
        if(dp[c][now][1]==1)
        {
            for(int x:one[dp[c][now][0]]) res[x]='2';
            now-=one[dp[c][now][0]].size();
        }
        else
        {
            for(int x:two[dp[c][now][0]]) res[x]='2';
            now-=two[dp[c][now][0]].size();
        }
        c--;
    }
    for(int i=1;i<=n;i++)
    {
        if(res[i]=='2') continue;
        if(n1>0)
        {
            res[i]='1';
            n1--;
        }
        else res[i]='3';
    }
    cout << "YES\n";
    cout << res.substr(1,n) << "\n";
    return 0;
}