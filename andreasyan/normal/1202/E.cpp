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
const int N = 400005;
int s;

int n;
string a;
int m;
string b[N];

int z;
int t[N][26];
int q[N];

int ans[N];

int f[N];

void solvv()
{
    z = 0;
    memset(t, 0, sizeof t);
    memset(q, 0, sizeof q);
    memset(ans, 0, sizeof ans);
    for (int i = 0; i < m; ++i)
    {
        int n = b[i].size();
        if (n <= s)
        {
            int pos = 0;
            for (int j = 0; j < n; ++j)
            {
                if (!t[pos][b[i][j] - 'a'])
                    t[pos][b[i][j] - 'a'] = ++z;
                pos = t[pos][b[i][j] - 'a'];
            }
            ++q[pos];
        }
        else
        {
            string u = b[i] + a;
            n += ::n;
            int k = 0, r = 0;
            memset(f, 0, sizeof f);
            for (int j = 1; j < n; ++j)
            {
                if (j <= r)
                    f[j] = min(r - j + 1, f[j - k]);
                while (j + f[j] < n && u[f[j]] == u[j + f[j]])
                    ++f[j];
                if (j + f[j] - 1 > r)
                {
                    r = j + f[j] - 1;
                    k = j;
                }
            }
            n -= ::n;
            for (int j = n; j < n + ::n; ++j)
            {
                if (f[j] >= n)
                {
                    ans[j - n]++;
                }
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        int pos = 0;
        for (int j = 0; j < n - i; ++j)
        {
            if (!t[pos][a[i + j] - 'a'])
                break;
            pos = t[pos][a[i + j] - 'a'];
            ans[i] += q[pos];
        }
    }
}

int ans1[N], ans2[N];

void solv()
{
    cin >> a;
    n = a.size();
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> b[i];
        s += b[i].size();
    }
    s = sqrt(s);
    solvv();
    for (int i = 0; i < n; ++i)
        ans1[i] = ans[i];
    reverse(all(a));
    for (int i = 0; i < m; ++i)
        reverse(all(b[i]));
    solvv();
    for (int i = 0; i < n; ++i)
        ans2[i] = ans[i];
    reverse(ans2, ans2 + n);
    ll yans = 0;
    for (int i = 1; i < n; ++i)
    {
        yans += ans1[i] * 1LL * ans2[i - 1];
    }
    printf("%lld\n", yans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}