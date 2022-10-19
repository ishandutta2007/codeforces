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
const int N = 200005;

int n;
int q[N];

vector<int> v[N];
bool stg(int d)
{
    for (int i = 1; i <= n; ++i)
        v[i].clear();
    for (int i = 1; i <= n; ++i)
    {
        if (q[i])
            v[1].push_back(q[i]);
    }
    priority_queue<int> q;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < v[i].size(); ++j)
            q.push(v[i][j]);
        if (q.empty())
            return false;
        int x = q.top();
        q.pop();
        --x;
        if (x)
            v[i + d + 1].push_back(x);
    }
    return true;
}

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        q[i] = 0;
    for (int i = 1; i <= n; ++i)
    {
        int x;
        scanf("%d", &x);
        ++q[x];
    }
    int l = 1, r = n;
    int ans = 0;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (stg(m))
        {
            ans = m;
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    printf("%d\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}