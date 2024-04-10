#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 10004, M = 1003;
const int INF = 2000000009;
struct ban
{
    int x, t;
    int d;
    ban(){}
    ban(int x, int t, int d)
    {
        this->x = x;
        this->t = t;
        this->d = d;
    }
};

int n, m;
int d[N];
int g, r;

bool c[N][M];

void solv()
{
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &d[i]);
    scanf("%d%d", &g, &r);
    sort(d + 1, d + n + 1);
    int ans = INF;
    deque<ban> q;
    q.push_front(ban(1, 0, 0));
    while (!q.empty())
    {
        ban t = q.front();
        q.pop_front();
        if (c[t.x][t.t])
            continue;
        c[t.x][t.t] = true;
        if (t.x == n)
        {
            ans = min(ans, t.d * (r + g) + t.t);
        }
        if (t.t == g)
        {
            ban h = t;
            h.t = 0;
            h.d++;
            q.push_back(h);
        }
        if (t.x > 1)
        {
            ban h = t;
            h.x--;
            h.t += (d[t.x] - d[t.x - 1]);
            if (h.t <= g)
            {
                q.push_front(h);
            }
        }
        if (t.x < n)
        {
            ban h = t;
            h.x++;
            h.t += (d[t.x + 1] - d[t.x]);
            if (h.t <= g)
            {
                q.push_front(h);
            }
        }
    }
    if (ans == INF)
        printf("-1\n");
    else
        printf("%d\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}