#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T; cin >> T;
    while(T--)
    {
        int N; cin >> N;
        vector<vector<int>> conn(N);
        vector<int> ret(N);
        for(int i=0; i<N-1; ++i)
        {
            int u, v; cin >> u >> v;
            conn[u-1].push_back(v-1);
            conn[v-1].push_back(u-1);
        }
        function<void(int, int, int)> dfs = [&](int a, int p, int h)
        {
            int s = 0, t = 1;
            if(h > 0)
            {
                if(h%2 == 1) s = 1, t = -1;
                else s = -1, t = 1;
            }
            ret[a] = s;
            for(auto x: conn[a]) if(x != p)
            {
                dfs(x, a, h+1);
                ret[a] -= t;
            }
        };
        dfs(0, -1, 0);
        for(int x: ret) cout << x << " ";
        cout << endl;
    }
}