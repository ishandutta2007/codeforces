#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 100005;

int n, m, k;
vector<int> a[N];
bool c[N];
int q[N];

struct ban
{
    int x;
    int q, qq;
    ban(){}
    ban(int x, int q, int qq)
    {
        this->x = x;
        this->q = q;
        this->qq = qq;
    }
};

bool so(int x1, int y1, int x2, int y2)
{
    return x1 * 1LL * y2 < x2 * 1LL * y1;
}

bool operator<(const ban& a, const ban& b)
{
    return !so(a.q, a.qq, b.q, b.qq);
}

int ti;
int in[N];

void solv()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < k; ++i)
    {
        int x;
        scanf("%d", &x);
        c[x] = true;
    }
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for (int x = 1; x <= n; ++x)
        q[x] = a[x].size();
    for (int x = 1; x <= n; ++x)
    {
        if (!c[x])
            continue;
        for (int i = 0; i < a[x].size(); ++i)
        {
            int h = a[x][i];
            --q[h];
        }
    }
    priority_queue<ban> pq;
    for (int x = 1; x <= n; ++x)
    {
        if (!c[x])
            pq.push(ban(x, q[x], a[x].size()));
    }
    int ansq = -1, ansqq = 1;
    int ans;
    while (1)
    {
        ban t;
        do
        {
            if (pq.empty())
            {
                vector<int> ansv;
                for (int i = 1; i <= n; ++i)
                {
                    if (in[i] >= ans)
                        ansv.push_back(i);
                }
                printf("%d\n", ansv.size());
                for (int i = 0; i < ansv.size(); ++i)
                    printf("%d ", ansv[i]);
                printf("\n");
                return;
            }
            t = pq.top();
            pq.pop();
        } while (c[t.x]);
        c[t.x] = true;
        in[t.x] = ++ti;
        if (!so(t.q, t.qq, ansq, ansqq))
        {
            ansq = t.q;
            ansqq = t.qq;
            ans = in[t.x];
        }
        for (int i = 0; i < a[t.x].size(); ++i)
        {
            int h = a[t.x][i];
            --q[h];
            if (!c[h])
                pq.push(ban(h, q[h], sz(a[h])));
        }
    }
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