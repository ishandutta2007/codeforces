#include <bits/stdc++.h>

using namespace std;

typedef long long li;

struct point
{
    int x, y;
    
    point(int x = 0, int y = 0): x(x), y(y) {}
    
    bool operator<(const point& p) const { return make_pair(x, y) < make_pair(p.x, p.y); }
};

int main()
{
    int w, h, k;
    scanf("%d %d %d", &h, &w, &k);
    
    map<int, vector<int>> xMinusY, xPlusY;
    
    const li INF = 1e18;
    vector<li> answer(k, INF);
    
    vector<point> p(k);
    for (int i = 0; i < k; i++)
    {
        scanf("%d %d", &p[i].y, &p[i].x);
        xMinusY[p[i].x - p[i].y].push_back(i);
        xPlusY[p[i].x + p[i].y].push_back(i);
    }
    
    set<pair<point, point>> visited;
    point current(0, 0);
    point dir(1, 1);
    
    li tSum = 0;
    
    while (!visited.count(make_pair(current, dir)))
    {
        visited.insert(make_pair(current, dir));
        //printf("%d %d, %d %d\n", current.x, current.y, dir.x, dir.y);
        
        // x = 0
        li tx0 = current.x / -dir.x;
        li txMax = (w - current.x) / dir.x;
        li ty0 = current.y / -dir.y;
        li tyMax = (h - current.y) / dir.y;
        
        if (tx0 <= 0) tx0 = INF;
        if (ty0 <= 0) ty0 = INF;
        if (txMax <= 0) txMax = INF;
        if (tyMax <= 0) tyMax = INF;
        
        li minTime = min(min(tx0, ty0), min(txMax, tyMax));
        
        assert(minTime != INF);
        
        if (current.x < 0 || current.y < 0 || current.x > w || current.y > h) break;
        
        if (dir.x + dir.y == 0)
        {
            // xpy ok
            for (int i: xPlusY[current.x + current.y])
                answer[i] = min(answer[i], tSum + abs(current.x - p[i].x));
        }
        else
        {
            for (int i: xMinusY[current.x - current.y])
                answer[i] = min(answer[i], tSum + abs(current.x - p[i].x));
        }
        
        tSum += minTime;
        current.x += dir.x * minTime;
        current.y += dir.y * minTime;
        
        if (current.x == 0 || current.x == w)
            dir.x = -dir.x;
        else
        {
            assert(current.y == 0 || current.y == h);
            dir.y = -dir.y;
        }
        
        if ((current.x == 0 || current.x == w) && (current.y == 0 || current.y == h))
            break;
        
        //printf("-> %d %d, %d %d\n", current.x, current.y, dir.x, dir.y);
    }
    
    for (int i = 0; i < k; i++)
        printf("%lld\n", answer[i] == INF ? -1 : answer[i]);
    
    return 0;
}