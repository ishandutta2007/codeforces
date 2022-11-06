#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>

using namespace std;

vector<int> r[300010];
vector<int> b[300010];
vector<int> g;

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, p, m, i, j;
    char c;
    long long res;
    scanf("%d", &n);
    m = 0;
    for(i = 0; i < n; i++)
    {
        scanf("%d %c", &p, &c);
        if(c == 'R')
            r[m].push_back(p);
        if(c == 'B')
            b[m].push_back(p);
        if(c == 'G')
        {
            g.push_back(p);
            m++;
        }
    }

    res = 0;

    if(m == 0)
    {
        if(!r[0].empty())
            res += r[0].back() - r[0].front();
        if(!b[0].empty())
            res += b[0].back() - b[0].front();
        printf("%lld", res);
        return 0;
    }

    if(!r[0].empty())
        res += g[0] - r[0].front();
    if(!b[0].empty())
        res += g[0] - b[0].front();
    if(!r[m].empty())
        res += r[m].back() - g[m - 1];
    if(!b[m].empty())
        res += b[m].back() - g[m - 1];

    for(i = 1; i < m; i++)
    {
        if(r[i].empty() && b[i].empty())
        {
            res += g[i] - g[i - 1];
            continue;
        }

        long long d, dr, db;
        d = db = dr = g[i] - g[i - 1];

        if(!r[i].empty())
        {
            dr = min(dr, d - (r[i].front() - g[i - 1]));
            dr = min(dr, d - (g[i] - r[i].back()));
            for(j = 0; j < r[i].size() - 1; j++)
                dr = min(dr, d - (r[i][j + 1] - r[i][j]));
        }

        if(!b[i].empty())
        {
            db = min(db, d - (b[i].front() - g[i - 1]));
            db = min(db, d - (g[i] - b[i].back()));
            for(j = 0; j < b[i].size() - 1; j++)
                db = min(db, d - (b[i][j + 1] - b[i][j]));
        }

        if(r[i].empty() || b[i].empty())
            res += db + dr;
        else
            res += min(d + db + dr, 2 * d);
    }
    printf("%lld", res);
    return 0;
}