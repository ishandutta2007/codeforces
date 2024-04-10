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

int n, m;
int a[N];
bool c[N];

multiset<int> b;

int maxu(int x)
{
    if (b.empty())
        return -1;
    auto it = b.upper_bound(m - 1 - x);
    if (it == b.begin())
    {
        return (x + *(--b.end())) % m;
    }
    --it;
    return (x + *it) % m;
}

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i)
    {
        int x;
        scanf("%d", &x);
        b.insert(x);
    }
    priority_queue<pair<int, int> > q;
    for (int i = 1; i <= n; ++i)
    {
        q.push(m_p(maxu(a[i]), i));
    }
    while (!q.empty())
    {
        pair<int, int> x = q.top();
        q.pop();
        if (c[x.se])
            continue;
        int tmax = maxu(a[x.se]);
        if (tmax == x.fi)
        {
            printf("%d ", x.fi);
            c[x.se] = true;
            b.erase(b.find((x.fi - a[x.se] + m) % m));
        }
        else
        {
            q.push(m_p(tmax, x.se));
        }
    }
    printf("\n");
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