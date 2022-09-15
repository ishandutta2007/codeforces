#include<bits/stdc++.h>
using namespace std;

int N, M;
vector<pair<int, int> > conn[303030];
long long d1[303030], dN[303030];

void dfs(int a, int p, long long* d, long long w)
{
    d[a] = w;
    for(auto [x, ww]: conn[a])
        if(x != p)
            dfs(x, a, d, w+ww);
}

int main()
{
    scanf("%d%d", &N, &M);
    for(int i=0; i<N-1; ++i)
    {
        int u, v, w; scanf("%d%d%d", &u, &v, &w);
        conn[u].emplace_back(v, w);
        conn[v].emplace_back(u, w);
    }
    dfs(1, 0, d1, 0); dfs(N, 0, dN, 0);

    vector<int> ord(N); iota(ord.begin(), ord.end(), 1);
    sort(ord.begin(), ord.end(), [&](int a, int b){
        return d1[a]-dN[a] > d1[b]-dN[b];
    });

    set<pair<long long, int> > S;
    long long ans = 0;
    for(auto v: ord)
    {
        vector<pair<long long, int> > te;
        for(auto [x, _]: conn[v])
        {
            auto qq = make_pair(dN[x], x);
            if(S.count(qq))
            {
                te.push_back(qq);
                S.erase(qq);
            }
        }
        if(S.size())
            ans = max(ans, d1[v]+S.rbegin()->first);
        for(auto qq: te) S.insert(qq);
        S.emplace(dN[v], v);
    }

    while(M--)
    {
        int t; scanf("%d", &t);
        printf("%lld\n", min(ans+t, d1[N]));
    }

}