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
const int N = 1000006;

vector<int> b[N];
void pre()
{
    for (int i = 1; i < N; ++i)
    {
        for (int j = i + i; j < N; j += i)
            b[j].push_back(i);
    }
}

int n;
pair<int, int> a[N];

int maxul[N], maxur[N];
int minul[N], minur[N];

int u[N];
ll solvv()
{
    stack<int> s;
    for (int i = 1; i <= n; ++i)
    {
        while (!s.empty() && a[i] > a[s.top()])
            s.pop();
        if (s.empty())
            maxul[i] = 0;
        else
            maxul[i] = s.top();
        s.push(i);
    }

    while (!s.empty())
        s.pop();
    for (int i = n; i >= 1; --i)
    {
        while (!s.empty() && a[i] > a[s.top()])
            s.pop();
        if (s.empty())
            maxur[i] = n + 1;
        else
            maxur[i] = s.top();
        s.push(i);
    }

    while (!s.empty())
        s.pop();
    for (int i = 1; i <= n; ++i)
    {
        while (!s.empty() && a[i].fi <= a[s.top()].fi)
            s.pop();
        if (s.empty())
            minul[i] = 0;
        else
            minul[i] = s.top();
        s.push(i);
    }

    while (!s.empty())
        s.pop();
    for (int i = n; i >= 1; --i)
    {
        while (!s.empty() && a[i] < a[s.top()])
            s.pop();
        if (s.empty())
            minur[i] = n + 1;
        else
            minur[i] = s.top();
        s.push(i);
    }

    ll ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        u[a[i].fi] = i;
        for (int j = 0; j < sz(b[a[i].fi]); ++j)
        {
            int x = b[a[i].fi][j];
            if (u[x])
            {
                if (maxul[i] + 1 <= u[x] && i <= minur[u[x]] - 1)
                {
                    ans += (u[x] - max(maxul[i], minul[u[x]])) * 1LL * (min(maxur[i], minur[u[x]]) - i);
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i)
        u[a[i].fi] = 0;
    return ans;
}

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i].fi;
        a[i].se = i;
    }

    ll ans = solvv();
    reverse(a + 1, a + n + 1);
    ans += solvv();

    int q = 1;
    for (int i = 2; i <= n; ++i)
    {
        if (a[i].fi == a[i - 1].fi)
            ++q;
        else
        {
            ans += q * 1LL * (q + 1) / 2;
            q = 1;
        }
    }
    ans += q * 1LL * (q + 1) / 2;

    cout << ans << "\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    pre();

    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}