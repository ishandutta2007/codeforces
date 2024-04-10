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
const int N = 50004567;

ll n;
bool c[N];
int t[N];

vector<int> p;

map<ll, ll> ans;
inline void rec0(ll i, int j)
{
    if (j == 0)
        return;
    if (p[j] > i)
        return;
    if (i < N)
    {
        ans[i * N + j] = 0;
        return;
    }
    rec0(i, j - 1);
    rec0(i / p[j - 1], j - 1);
}

int f[N / 9];
void ubd(int x)
{
    ++x;
    while (x < N / 9)
    {
        f[x]++;
        x += (x & (-x));
    }
}
int qry(int x)
{
    ++x;
    int ans = 0;
    while (x)
    {
        ans += f[x];
        x -= (x & (-x));
    }
    return ans;
}

inline ll rec(ll i, int j)
{
    if (j == 0)
        return i;
    if (p[j] > i)
        return 1;
    if (i < N)
        return ans[i * N + j];
    return rec(i, j - 1) - rec(i / p[j - 1], j - 1);
}

void solv()
{
    cin >> n;
    c[0] = c[1] = true;
    int z = 0;
    int uu = sqrt(n) + 100;
    for (int i = 1; i < N; ++i)
    {
        if (c[i])
            continue;
        t[i] = z;
        if (i * 1LL * i < N)
        {
            for (int j = i * i; j < N; j += i)
            {
                if (!c[j])
                    t[j] = z;
                c[j] = true;
            }
        }
        ++z;
    }

    for (int i = 1; i <= uu; ++i)
    {
        if (!c[i])
            p.push_back(i);
    }

    ll yans = 0;
    for (int i = 0; i < p.size(); ++i)
    {
        if (p[i] * 1LL * p[i] * p[i] <= n)
            ++yans;
        else
            break;
    }

    for (int i = 0; i < p.size(); ++i)
    {
        if (p[i] * 1LL * p[i] < n)
        {
            if (p.back() <= n / p[i])
                rec0(n / p[i], sz(p) - 1);
        }
    }

    int u = 1;
    for (auto it = ans.begin(); it != ans.end(); ++it)
    {
        while (u < it->fi / N)
        {
            ++u;
            ubd(t[u]);
        }
        ans[it->fi] = u - qry(it->fi % N - 1);
    }

    for (int i = 0; i < p.size(); ++i)
    {
        if (p[i] * 1LL * p[i] < n)
        {
            if (p.back() <= n / p[i])
                yans += rec(n / p[i], sz(p) - 1) - 1 + sz(p) - 1 - (i + 1);
            else
            {
                for (int j = i + 1; j < p.size(); ++j)
                {
                    if (p[i] * 1LL * p[j] <= n)
                        ++yans;
                    else
                        break;
                }
            }
        }
    }

    cout << yans << "\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}