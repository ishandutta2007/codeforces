#pragma GCC target("avx2,popcnt")
#include<bits/stdc++.h>
using namespace std;


int X;

void solve(int N, vector<long long> a, vector<vector<pair<int, int> > > conn, vector<int>& ans)
{
    if(N == 1) return;

    vector<int> color(N, -1);
    vector<long long> new_a(N);

    for(int i=0; i<N; ++i)
    {
        sort(conn[i].begin(), conn[i].end(), [&](pair<int, int> x, pair<int, int> y)
        {
            return a[x.first] > a[y.first];
        });
    }

    function<bool(int, int, long long&)> dfs = [&](int x, int c, long long& budget)
    {
        bool ret = false;
        color[x] = c;
        for(auto [u, v]: conn[x])
        {
            if(color[u] != -1) continue;
            if(budget + a[u] >= X)
            {
                budget += a[u] - X;
                ans.push_back(v);
                dfs(u, c, budget);
                ret = true;
            }
        }
        return ret;
    };


    int tpx = 0;
    for(int i=0; i<N; ++i)
    {
        if(color[i] == -1)
        {
            new_a[tpx] = a[i];
            bool ret = dfs(i, tpx, new_a[tpx]);
            if(!ret)
            {
                color[i] = -1;
                new_a[i] = 0;
            }
            else
                ++tpx;
        }
    }
    for(int i=0; i<N; ++i)
    {
        if(color[i] == -1)
        {
            new_a[tpx] = a[i];
            color[i] = tpx;
            ++tpx;
        }
    }
    if(tpx == N) {ans.clear(); return;}

    new_a.resize(tpx);

    vector<vector<pair<int, int> > > new_conn(N);
    set<pair<int, int> > S;

    for(int u=0; u<N; ++u)
    {
        for(auto [v, e]: conn[u])
        {
            if(color[u] != color[v])
            {
                int aa = min(color[u], color[v]);
                int bb = max(color[u], color[v]);
                if(!S.count(make_pair(aa,bb)))
                {
                    S.insert(make_pair(aa, bb));
                    new_conn[aa].emplace_back(bb, e);
                    new_conn[bb].emplace_back(aa, e);
                }
            }
        }
    }
    solve(tpx, new_a, new_conn, ans);

    return;
}

int main()
{
    int N, M;
    scanf("%d%d%d", &N, &M, &X);
    vector<long long> a(N);
    for(int i=0; i<N; ++i) scanf("%lld", &a[i]);
    vector<vector<pair<int, int> > > V(N);
    for(int i=1; i<=M; ++i)
    {
        int u, v;
        scanf("%d%d", &u, &v); --u; --v;
        V[v].emplace_back(u, i);
        V[u].emplace_back(v, i);
    }
    vector<int> ans;
    solve(N, a, V, ans);
    if(ans.size() == 0) puts("NO");
    else
    {
        puts("YES");
        for(auto x: ans) cout << x << endl;
    }
}