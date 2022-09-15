#include<bits/stdc++.h>
using namespace std;
long long x[101010];
int main()
{
    int N, M; scanf("%d%d", &N, &M);
    for(int i=0; i<M; ++i)
    {
        int u, v, d;
        scanf("%d%d%d", &u, &v, &d);
        x[u] += d; x[v] -= d;
    }
    vector<pair<long long, int> > V;
    for(int i=1; i<=N; ++i)
    {
        V.emplace_back(x[i], i);
    }
    sort(V.rbegin(), V.rend());
    int tp1 = 0, tp2 = N-1;
    vector<tuple<int, int, long long> > X;
    while(tp1 < tp2)
    {
        if(V[tp1].first == 0 || V[tp2].first == 0) break;
        long long am = V[tp1].first;
        long long bm = -V[tp2].first;
        long long x = min(am, bm);
        V[tp1].first -= x;
        V[tp2].first += x;
        X.emplace_back(V[tp1].second, V[tp2].second, x);
        if(x==am) ++tp1;
        if(x==bm) --tp2;
    }
    printf("%d\n", (int)X.size());
    for(auto [a, b, c]: X)
    {
        printf("%d %d %lld\n", a, b, c);
    }
    return 0;
}