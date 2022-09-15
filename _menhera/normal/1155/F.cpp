#include<bits/stdc++.h>
using namespace std;

const int MAXN = 14;
int N, M;
bool conn[MAXN][MAXN];

bool dp[MAXN][MAXN][1<<MAXN]; // from, to, flag
bool can[1<<MAXN];
int t[1<<MAXN];

vector<pair<int, int> > b2(int from, int to, int flag)
{
    assert(dp[from][to][flag]);
    if(((1<<from)|(1<<to))==flag) return {{from, to}};
    for(int i=0; i<N; ++i)
        if(from != i && to != i && conn[to][i] && (flag&(1<<i)) && dp[from][i][flag-(1<<to)])
        {
            auto ans = b2(from, i, flag-(1<<to));
            ans.emplace_back(i, to);
            return ans;
        }
    assert(false);
}

vector<pair<int, int> > back(int flag)
{
    assert(can[flag]);
    for(int i=0; i<N; ++i)
        for(int j=0; j<N; ++j)
            if(i != j && conn[i][j] && dp[i][j][flag] )
            {
                auto ans = b2(i, j, flag);
                ans.emplace_back(i, j);
                return ans;
            }
    assert(false);
}

vector<pair<int, int> > track(int flag)
{
    if(can[flag]) return back(flag);
    for(int i=0; i=(i-flag)&flag;)
    {
        for(int from=0; from<N; ++from)
        {
            if(!(i&(1<<from))) continue;
            int prev = flag-i+(1<<from);
            if(can[i] && t[flag] == t[prev]+1)
            {
                auto ans = track(prev);
                for(auto x: back(i)) ans.push_back(x);
                return ans;
            }

            for(int to=0; to<N; ++to)
            {
                if(from == to || !(i&(1<<to))) continue;
                int prev = flag-i+(1<<from)+(1<<to);
                if(dp[from][to][i] && t[flag] == t[prev]+1)
                {
                    auto ans = track(prev);
                    for(auto x: b2(from, to, i)) ans.push_back(x);
                    return ans;
                }
            }
        }
    }
    assert(false);
}

int main()
{
    scanf("%d%d", &N, &M);
    for(int i=0; i<M; ++i)
    {
        int u, v; scanf("%d%d", &u, &v); --u; --v;
        conn[u][v] = conn[v][u] = 1;
        int uv = (1<<u)|(1<<v);
        dp[u][v][uv] = dp[v][u][uv] = 1;
    }
    for(int flag=0; flag<(1<<N); ++flag)
        for(int from=0; from<N; ++from)
            for(int to=0; to<N; ++to)
            {
                if(from == to) continue;
                int ft = (1<<from) | (1<<to);
                if((flag&ft) != ft) continue;
                for(int i=0; i<N; ++i)
                {
                    if(from == i || to == i || !(flag&(1<<i)) ) continue;
                    if(!conn[to][i] || !dp[from][i][flag^(1<<to)]) continue;
                    dp[from][to][flag] = 1;
                    if(ft != flag && conn[from][to]) can[flag] = 1;
                    break;
                }
            }
    memset(t, 0x3f, sizeof t);
    for(int flag=0; flag<(1<<N); ++flag)
    {
        if(can[flag])
        {
            // for(int i=0; i<N; ++i) if(flag&(1<<i)) cout << 1+i << " ";
            // cout << endl;
            t[flag] = 1; continue;
        }
        for(int i=0; i=(i-flag)&flag;)
        {
            for(int from=0; from<N; ++from)
            {
                if(!(i&(1<<from))) continue;
                int prev = flag-i+(1<<from);
                if(can[i]) t[flag]=min(t[flag], t[prev]+1);

                for(int to=0; to<N; ++to)
                {
                    if(from == to || !(i&(1<<to))) continue;
                    int prev = flag-i+(1<<from)+(1<<to);
                    if(dp[from][to][i]) t[flag]=min(t[flag], t[prev]+1);
                }
            }
        }
    }

    auto ans = track((1<<N)-1);
    cout << ans.size() << endl;
    for(auto [a, b]: ans) cout << 1+a << " " << 1+b << endl;

}