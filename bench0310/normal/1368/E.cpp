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
        set<array<int,2>> edges;
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin >> a >> b;
            edges.insert({a,b});
        }
        vector<vector<int>> v(n+1);
        for(auto [a,b]:edges) v[a].push_back(b);
        vector<array<int,2>> two[n+1];
        for(int i=1;i<=n;i++)
        {
            for(int a:v[i])
            {
                for(int b:v[a])
                {
                    two[b].push_back({i,a});
                }
            }
        }
        vector<bool> x(n+1,0);
        vector<int> res;
        for(int i=1;i<=n;i++)
        {
            bool ok=1;
            for(auto [a,b]:two[i]) if(x[a]==0&&x[b]==0) ok=0;
            if(ok==0)
            {
                x[i]=1;
                res.push_back(i);
            }
        }
        cout << res.size() << "\n";
        for(int a:res) cout << a << " ";
        cout << "\n";
    }
    return 0;
}