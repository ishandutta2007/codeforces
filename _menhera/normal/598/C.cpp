#include<bits/stdc++.h>
using namespace std;

using Point = pair<long long, long long>;
long long cross(Point a, Point b)
{
    auto [ax, ay] = a; auto [bx, by] = b;
    return ax*by-bx*ay;
}
long long dot(Point a, Point b)
{
    auto [ax, ay] = a; auto [bx, by] = b;
    return ax*bx+ay*by;
}

int main()
{
    int N; scanf("%d", &N);
    vector<pair<int, Point> > V;
    for(int i=0; i<N; ++i)
    {
        int x, y; scanf("%d%d", &x, &y);
        V.emplace_back(i+1, make_pair(x, y));
    }
    sort(V.begin(), V.end(), [&](pair<int, Point> a, pair<int, Point> b)
    {
        const Point O = {0, 0};
        bool al = a.second < O, bl = b.second < O;
        if(al != bl) return al;
        return cross(a.second, b.second) > 0;
    });

    pair<int, int> ansi = {-1, -1}; pair<long long, long long> ansv;
    for(int i=0; i<N; ++i)
    {
        auto [ai, A] = V[i]; auto [bi, B] = V[(i+1)%N];
        pair<long long, long long> ang = {dot(A, B), abs(cross(A, B))};
        if(ansi.first == -1 || cross(ang, ansv) > 0)
            ansi = {ai, bi}, ansv = ang;
    }
    printf("%d %d\n", ansi.first, ansi.second);
}