#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2100);
const int N = 1000006, M = 1000000007;

int n, k;
int a[N];
int b[N];

int t[N * 4];
void bil(int tl, int tr, int pos)
{
    if (tl == tr)
    {
        t[pos] = a[tl];
        return;
    }
    int m = (tl + tr) / 2;
    bil(tl, m, pos * 2);
    bil(m + 1, tr, pos * 2 + 1);
    t[pos] = max(t[pos * 2], t[pos * 2 + 1]);
}

int qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return 0;
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    return max(qry(tl, m, l, min(m, r), pos * 2),
               qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

int ul[N], ur[N];

vector<int> v, p;

int q(int d)
{
    int i = upper_bound(all(v), d) - v.begin() - 1;
    if (i == -1)
        return 0;
    return (((d + 1) * 1LL * (i + 1)) % M - p[i] + M) % M;
}

void solv()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
    }
    bil(1, n, 1);

    stack<int> s;
    for (int i = 1; i <= n; ++i)
    {
        while (!s.empty() && a[s.top()] <= a[i])
            s.pop();
        if (s.empty())
            ul[i] = 0;
        else
            ul[i] = s.top();
        s.push(i);
    }

    while (!s.empty())
        s.pop();
    for (int i = n; i >= 1; --i)
    {
        while (!s.empty() && a[s.top()] < a[i])
            s.pop();
        if (s.empty())
            ur[i] = n + 1;
        else
            ur[i] = s.top();
        s.push(i);
    }

    for (int i = 1; ; ++i)
    {
        v.push_back(i * k - (i - 1));
        if (v.back() > n)
            break;
    }
    for (int i = 0; i < v.size(); ++i)
    {
        if (i == 0)
            p.push_back(0);
        else
            p.push_back(p[i - 1]);
        p[i] += v[i];
        p[i] %= M;
    }

    int ans = 0;

    for (int i = 1; i <= n; ++i)
    {
        ++ul[i];
        --ur[i];
        ans = (ans + (q(ur[i] - ul[i] + 1) * 1LL * a[i]) % M) % M;
        ans = (ans - (q(i - ul[i]) * 1LL * a[i]) % M + M) % M;
        ans = (ans - (q(ur[i] - i) * 1LL * a[i]) % M + M) % M;
    }

    printf("%d\n", ans);
    return;

    int tans = 0;
    for (int i = 1; i <= n; ++i)
        printf("%d ", a[i]);
    printf("\n");
    for (int ii = 1; ii <= n; ++ii)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (j - ii * (k - 1) < 1)
                b[j] = 0;
            else
            {
                int maxu = 0;
                for (int t = j - k + 1; t <= j; ++t)
                    maxu = max(maxu, a[t]);
                b[j] = maxu;
            }
        }
        for (int j = 1; j <= n; ++j)
        {
            a[j] = b[j];
            printf("%d ", a[j]);
            tans += a[j];
        }
        printf("\n");
    }
    printf("%d\n", tans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}