#include<bits/stdc++.h>
using namespace std;

struct SCC
{
    int N;
    vector<bool> vis;
    vector<vector<int>> conn;
    vector<vector<int>> revconn;
    stack<int> S;
    
    explicit SCC(int _N)
        : N(_N), vis(_N), conn(_N), revconn(_N)
    {

    }

    int add_edge(int from, int to)
    {
        conn[from].push_back(to);
        revconn[to].push_back(from);
    }

    void dfs(int a)
    {
        if(vis[a]) return;
        vis[a] = true;
        for(auto x: conn[a])
            dfs(x);
        S.push(a);
    }

    vector<int> comp;

    void dfs2(int a)
    {
        if(vis[a]) return;
        vis[a] = true;
        comp.push_back(a);
        for(auto x: revconn[a])
            dfs2(x);
        return;
    }

    vector<vector<int> > solve()
    {
        fill(vis.begin(), vis.end(), false);
        for(int i=0; i<N; ++i) dfs(i);

        vector<vector<int> > ans;
        fill(vis.begin(), vis.end(), false);
        while(!S.empty())
        {
            dfs2(S.top()); S.pop();
            if(!comp.empty())
            {
                ans.push_back(comp);
                comp.clear();
            }
        }
        return ans;
    }
};


int main()
{
    int T; scanf("%d", &T); while(T--)
    {
        int N, M;
        scanf("%d%d", &N, &M);
        SCC scc(N);
        for(int i=0; i<M; ++i)
        {
            int u, v; scanf("%d%d", &u, &v); --u; --v;
            if(u==v) continue;
            scc.add_edge(u, v);
        }
        vector<vector<int>> ans = scc.solve();
        if(ans.size() == 1) puts("No");
        else
        {
            puts("Yes");
            printf("%d %d\n", (int)ans.back().size(), N-(int)ans.back().size());
            vector<bool> ans1(N, false);
            for(auto x: ans.back()) ans1[x] = true;
            for(int i=0; i<N; ++i)
                if(ans1[i])
                    printf("%d ", i+1);
            puts("");
            for(int i=0; i<N; ++i)
                if(!ans1[i])
                    printf("%d ", i+1);
            puts("");
        }
    }    
}