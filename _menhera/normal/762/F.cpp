#include<bits/stdc++.h>
using namespace std;

const int MOD = (int)1e9+7;

const int MAXN = 1000, MAXM = 12;

int ipow(int a, int b)
{
    if(b==0) return 1;
    int ans = ipow(a, b/2); ans = 1LL*ans*ans%MOD;
    if(b&1) ans = 1LL*ans*a%MOD;
    return ans;
}
int modInv(int a){ return ipow(a, MOD-2); }


// S(a), root = 1, T(a), T(p)
map<tuple<int, int, int, int>, int> solve(vector<vector<int>> S, vector<vector<int>> T, bool full = false)
{
    map<tuple<int, int, int, int>, int > MEM;
    int N = S.size()-1, M = T.size()-1;
    function<int(int, int, int, int)> solve = [&](int sa, int sp, int ta, int tp)
    {
        if(MEM.count({sa, sp, ta, tp})) return MEM[{sa, sp, ta, tp}];
        int K = 0; for(auto tx: T[ta]) if(tx != tp) ++K;
        int DP[1<<MAXM]; DP[0] = 1; for(int i=1; i<(1<<K); ++i) DP[i] = 0;
        int cnt1 = 0;
        for(auto sx: S[sa]) if(sx != sp)
        {
            ++cnt1;
            vector<int> child;
            for(auto tx: T[ta]) if(tx != tp)
                child.push_back(solve(sx, sa, tx, ta));
            for(int i=(1<<K)-1; i>=0; --i)
                for(int j=0; j<K; ++j) if(i&(1<<j))
                    DP[i] = (DP[i] + 1LL*DP[i-(1<<j)]*child[j])%MOD;
        }
        // if(tp == 0) cerr << sa << " " << sp << " " << ta << " " << tp << ": " << DP[(1<<K)-1] << endl;
        return MEM[{sa, sp, ta, tp}] = DP[(1<<K)-1];
    };
    function<void(int, int)> dfs = [&](int a, int p)
    {
        for(int j=1; j<=M; ++j) solve(a, p, j, 0);
        for(auto x: S[a]) if(x != p) dfs(x, a);
    };
    dfs(1, 0);
    if(full) for(int i=2; i<=N; ++i) dfs(i, 0);
    return MEM;
}

int main()
{
    auto inp = []()
    {
        int N; scanf("%d", &N);
        vector<vector<int>> conn(N+1);
        for(int i=0; i<N-1; ++i)
        {
            int u, v; scanf("%d%d", &u, &v);
            conn[u].push_back(v);
            conn[v].push_back(u);
        }
        return conn;
    };
    auto S = inp(), T = inp();
    int N = S.size()-1, M = T.size()-1;
    auto V1 = solve(S, T);
    // cerr <<"Hi!" << endl;
    auto V2 = solve(T, T, true);
    int ans = 0;
    for(int i=1; i<=M; ++i)
    {
        bool flag = true;
        for(int j=1; j<i; ++j)
            if(V2[{i, 0, j, 0}]) flag = false;
        if(flag)
        {
            int loc = 0;
            function<void(int, int)> dfs = [&](int a, int p)
            {
                loc += V1[{a, p, i, 0}];
                if(loc >= MOD) loc -= MOD;
                for(auto x: S[a]) if(x != p) dfs(x, a);
            };
            dfs(1, 0);
            // cerr << i << " " << V2[{i, 0, i, 0}] <<"!"<<endl;
            ans = (ans + 1LL*loc*modInv(V2[{i, 0, i, 0}]))%MOD;
        }
    }
    printf("%d\n", ans);
    return 0;
}