#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> v[n+1];
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int sz=1;
    while(sz*sz<n) sz++;
    vector<int> p(n+1,0);
    vector<int> depth(n+1,0);
    vector<bool> in(n+1,0);
    vector<int> res;
    function<void(int)> dfs=[&](int a)
    {
        depth[a]=depth[p[a]]+1;
        for(int to:v[a])
        {
            if(depth[to]!=0)
            {
                if(depth[a]-depth[to]+1>=sz)
                {
                    cout << "2\n";
                    cout << depth[a]-depth[to]+1 << "\n";
                    int now=a;
                    while(now!=to)
                    {
                        cout << now << " ";
                        now=p[now];
                    }
                    cout << to << "\n";
                    exit(0);
                }
                continue;
            }
            p[to]=a;
            dfs(to);
        }
        bool ok=1;
        for(int to:v[a]) ok&=(in[to]==0);
        if(ok&&(int)res.size()<sz)
        {
            in[a]=1;
            res.push_back(a);
        }
    };
    dfs(1);
    cout << "1\n";
    for(int a:res) cout << a << " ";
    cout << "\n";
    return 0;
}