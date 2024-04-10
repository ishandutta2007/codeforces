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
const int N = 2000006, m = 2000000, M = 1000000007;

int ast(int x, int n)
{
    int ans = 1;
    while (n)
    {
        if (n % 2 == 1)
            ans = (ans * 1LL * x) % M;
        x = (x * 1LL * x) % M;
        n /= 2;
    }
    return ans;
}

int n, p;
int a[N];

int q[N];
bool laz[N * 4];
bool t[N * 4];

void shi(int pos)
{
    if (!laz[pos])
        return;
    t[pos * 2] = false;
    t[pos * 2 + 1] = false;
    laz[pos * 2] = true;
    laz[pos * 2 + 1] = true;
    laz[pos] = false;
}

vector<int> vq;
void ubd(int tl, int tr, int x, int pos)
{
    if (tl == tr)
    {
        if (q[x])
            t[pos] = true;
        else
            t[pos] = false;
        return;
    }
    shi(pos);
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, pos * 2);
    else
        ubd(m + 1, tr, x, pos * 2 + 1);
    t[pos] = (t[pos * 2] || t[pos * 2 + 1]);
}

int qry(int tl, int tr, int pos)
{
    if (tl == tr)
    {
        return tl;
    }
    shi(pos);
    int m = (tl + tr) / 2;
    if (t[pos * 2 + 1])
        return qry(m + 1, tr, pos * 2 + 1);
    return qry(tl, m, pos * 2);
}

void solv()
{
    scanf("%d%d", &n, &p);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    if (p == 1)
    {
        printf("%d\n", (n % 2));
        return;
    }
    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        int x = a[i];
        int u;
        if (t[1] == false)
            u = -1;
        else
            u = qry(0, m, 1);
        if (u == -1 || q[u] < 0)
        {
            ans = (ans + ast(p, x)) % M;
            ++q[x];
            vq.push_back(x);
            ubd(0, m, x, 1);
            while (1)
            {
                if (q[x] == p)
                {
                    q[x] = 0;
                    ubd(0, m, x, 1);
                    ++x;
                    ++q[x];
                    vq.push_back(x);
                    ubd(0, m, x, 1);
                }
                else
                    break;
            }
        }
        else
        {
            ans = (ans - ast(p, x) + M) % M;
            --q[x];
            vq.push_back(x);
            ubd(0, m, x, 1);
            while (1)
            {
                if (q[x] == -p)
                {
                    q[x] = 0;
                    ubd(0, m, x, 1);
                    ++x;
                    --q[x];
                    vq.push_back(x);
                    ubd(0, m, x, 1);
                }
                else
                    break;
            }
        }
    }
    if (t[1] == false)
        printf("0\n");
    else
    {
        int u = qry(0, m, 1);
        if (q[u] < 0)
            ans = (-ans + M) % M;
        printf("%d\n", ans);
    }
    laz[1] = true;
    for (int i = 0; i < vq.size(); ++i)
    {
        q[vq[i]] = 0;
    }
    vq.clear();
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