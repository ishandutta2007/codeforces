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
const int N = 100005, M = 1000000007;

vector<int> v[N];

int n;
int a[N];

int phi[N];

int q[N];

vector<int> u[N];

void solv()
{
    for (int i = 1; i < N; ++i)
    {
        if (i == 1)
            phi[i] = 1;
        else if (sz(v[i]) == 1)
            phi[i] = i - 1;
        else
        {
            int x = i;
            int y = 1;
            while (x % v[i][1] == 0)
            {
                x /= v[i][1];
                y *= v[i][1];
            }
            if (x != 1)
                phi[i] = (phi[x] * phi[y]);
            else
                phi[i] = (i - (i / v[i][1]));
        }
        for (int j = i; j < N; j += i)
        {
            v[j].push_back(i);
        }
    }

    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1; i <= n; ++i)
    {
        for (int j = i; j <= n; j += i)
        {
            for (int k = 0; k < sz(v[a[j]]); ++k)
                q[v[a[j]][k]]++;
        }
        for (int j = i; j <= n; j += i)
        {
            int yans = 0;
            for (int k = 0; k < sz(v[a[j]]); ++k)
            {
                yans = (yans + q[v[a[j]][k]] * 1LL * phi[v[a[j]][k]]) % M;
            }
            u[j].push_back(yans);
        }
        for (int j = i; j <= n; j += i)
        {
            for (int k = 0; k < sz(v[a[j]]); ++k)
                q[v[a[j]][k]] = 0;
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < sz(v[i]); ++j)
            q[v[i][j]] = u[i][j];
        for (int j = sz(v[i]) - 1; j >= 0; --j)
        {
            for (int k = sz(v[v[i][j]]) - 2; k >= 0; --k)
                q[v[v[i][j]][k]] = (q[v[v[i][j]][k]] - q[v[i][j]]) % M;
        }
        for (int j = 0; j < sz(v[i]); ++j)
            ans = (ans + q[v[i][j]] * 1LL * v[i][j]) % M;
    }
    ans = (ans + M) % M;
    cout << ans << "\n";
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
        solv();
    return 0;
}