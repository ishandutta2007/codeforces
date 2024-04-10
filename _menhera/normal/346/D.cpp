#include<bits/stdc++.h>
using namespace std;

const int MAXN = (int)1e6;

int N, M;
vector<int> conn[MAXN], rev[MAXN];
int outcnt[MAXN], dis[MAXN];
int s, t;

int main()
{
    scanf("%d%d", &N, &M);
    for(int i=0; i<M; ++i)
    {
        int a, b; scanf("%d%d", &a, &b); --a; --b;
        conn[a].push_back(b); rev[b].push_back(a);
    }
    scanf("%d%d", &s, &t); --s; --t;
    memset(dis, -1, sizeof dis);
    deque<pair<int, int> > Q; Q.emplace_back(0, t);
    while(!Q.empty())
    {
        auto [d, v] = Q.back(); Q.pop_back();
        if(v == s){ printf("%d\n", d); return 0; }
        if(dis[v] != -1) continue; dis[v] = d;
        for(auto x: rev[v])
        {
            if(++outcnt[x] == conn[x].size()) Q.emplace_back(d, x);
            else Q.emplace_front(d+1, x);
        }
    }
    puts("-1"); return 0;

}