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
const int N = 1003;

int n, r;
vector<int> a[N];

int q[N];
void dfs(int x, int p)
{
    q[x] = 1;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        dfs(h, x);
        q[x] += q[h];
    }
}

void solv()
{
    scanf("%d%d", &n, &r);
    for (int i = 1; i <= n; ++i)
        a[i].clear();
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    if (n == 1)
    {
        printf("Ayush\n");
        return;
    }
    dfs(r, r);
    priority_queue<int> pq;
    for (int i = 0; i < a[r].size(); ++i)
    {
        int h = a[r][i];
        pq.push(q[h]);
    }
    bool z = false;
    while (1)
    {
        if (pq.size() == 1)
        {
            if (!z)
            {
                printf("Ayush\n");
            }
            else
            {
                printf("Ashish\n");
            }
            return;
        }
        int u = pq.top();
        pq.pop();
        --u;
        if (u)
            pq.push(u);
        z ^= true;
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}