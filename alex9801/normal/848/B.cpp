#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

struct str
{
    int p, t, x, i;
    bool operator <(const str &a) const
    {
        return p != a.p ? p < a.p : t < a.t;
    }
};

vector<int> com;
int idx(int x)
{
    return lower_bound(com.begin(), com.end(), x) - com.begin();
}

vector<str> hor, ver;
queue<str> que[100010];
priority_queue<int> hei[100010];

pair<int, int> res[100010];

int main()
{
    int n, w, h, g, p, t, k, i;
    scanf("%d%d%d", &n, &w, &h);
    for(i = 0; i<n; i++)
    {
        scanf("%d%d%d", &g, &p, &t);
        if(g == 1)
            ver.push_back({ p, t, t-p, i });
        else
            hor.push_back({ p, t, t-p, i });
        com.push_back(t-p);
    }

    sort(com.begin(), com.end());
    com.erase(unique(com.begin(), com.end()), com.end());

    sort(ver.begin(), ver.end());
    sort(hor.begin(), hor.end());
    reverse(hor.begin(), hor.end());

    for(str s : hor)
    {
        k = idx(s.x);
        que[k].push(s);
        hei[k].push(s.p);
    }

    for(str s : ver)
    {
        k = idx(s.x);
        if(que[k].empty())
            res[s.i] = { s.p, h };
        else
        {
            str tmp = que[k].front();
            que[k].pop();
            res[tmp.i] = { s.p, h };
            tmp.i = s.i;
            que[k].push(tmp);
        }
    }

    for(i = 0; i<com.size(); i++)
    {
        while(!que[i].empty())
        {
            str tmp = que[i].front();
            res[tmp.i] = { w, hei[i].top() };
            que[i].pop();
            hei[i].pop();
        }
    }

    for(i = 0; i<n; i++)
        printf("%d %d\n", res[i].first, res[i].second);
    return 0;
}