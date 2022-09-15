#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int N, K; cin >> N >> K;
    vector<vector<int>> conn(N);
    for(int i=0; i<N-1; ++i)
    {
        int a, b; cin >> a >> b; --a; --b;
        conn[a].push_back(b); conn[b].push_back(a);
    }
    vector<int> h(N), t(N), p(N);
    function<void(int, int)> dfs = [&](int a, int pa)
    {
        p[a] = pa; h[a] = 1; t[a] = a;
        for(auto x: conn[a]) if(x != pa)
        {
            dfs(x, a);
            h[a] = max(h[a], h[x]+1);
            if(h[a] == h[x]+1) t[a] = t[x];
        }
        // cout << a+1 << " " << h[a] << " " << t[a]+1 << endl;
    };
    dfs(0, -1);
    priority_queue<pair<int, int>> Q; Q.emplace(h[0], 0);
    int bf = N, rf = 0;
    while(!Q.empty() && rf < K)
    {
        int a = Q.top().second; Q.pop();
        ++rf; bf -= h[a];
        int b = t[a];
        while(b != a)
        {
            int pp = p[b];
            for(auto x: conn[pp]) if(x != p[pp] && x != b)
                Q.emplace(h[x], x);
            b = pp;
        }
    }
    //cout << bf << " " << rf << " " << K << endl;
    if(rf < K) // filled all red
    {
        long long ans = 0;
        for(int i=rf; i<=K; ++i) ans = max(ans, 1LL*(N-i)*i);
        cout << ans << '\n';
        return 0;
    }
    // otherwise, blue can be filled
    long long ans = 1LL*(N-rf)*rf;
    for(int i=0; i<=bf; ++i) ans = min(ans, 1LL*(N-rf-i)*(rf-i));
    cout << ans << '\n';
}