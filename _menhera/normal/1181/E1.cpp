#include<bits/stdc++.h>
using namespace std;

const int MAXN = 101010;
int N;
int xs[MAXN], ys[MAXN], xe[MAXN], ye[MAXN];

using comp = function<bool(int, int)>;
using Set = std::set<int, comp>;

pair<int, int> key(int k, int idx)
{
    switch(k)
    {
        case 0: return {xs[idx], xe[idx]};
        case 1: return {ys[idx], ye[idx]};
        case 2: return {-xe[idx], -xs[idx]};
        case 3: return {-ye[idx], -ys[idx]};
    }
}

comp comps[4];

comp getcomp(const int k)
{
    return [=](int a, int b)
    {
        return make_pair(key(k, a).first, a) < make_pair(key(k, b).first, b);
    };
}

bool solve(array<Set, 4>& S)
{
    int N = S[0].size(); if(N <= 2) return true;

    array<Set::iterator, 4> Si; for(int i=0; i<4; ++i) Si[i] = S[i].begin();
    array<int, 4> maxv; for(int j=0; j<4; ++j) maxv[j] = key(j, *Si[j]).second;
    for(int i=1; i<N; ++i)
        for(int j=0; j<4; ++j)
        {
            ++Si[j];
            auto [from, to] = key(j, *Si[j]);
            if(maxv[j] <= from)
            {
                array<Set, 4> T; for(int j=0; j<4; ++j) T[j] = Set(comps[j]);
                vector<int> V(S[j].begin(), Si[j]);

                for(auto v: V)
                    for(int j=0; j<4; ++j)
                        S[j].erase(v), T[j].insert(v);
                return solve(T) && solve(S);
            }
            maxv[j] = max(maxv[j], to);
        }
    return false;
};

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; ++i)
        scanf("%d%d%d%d", xs+i, ys+i, xe+i, ye+i);
    array<Set, 4> S;
    for(int i=0; i<4; ++i)
    {
        comps[i] = getcomp(i);
        S[i] = Set(comps[i]);
        for(int j=0; j<N; ++j) S[i].insert(j);
    }
    if(solve(S)) puts("YES");
    else puts("NO");
}