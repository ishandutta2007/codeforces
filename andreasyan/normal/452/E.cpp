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
const int N = 300005;
const ll M = 1000000007;

int n[3];
char a[3][N];

int m;
char s[N * 3];

int p[N * 3];
int z;
int c[N * 3];

int q[N * 3];
int np[N * 3];
int nc[N * 3];

int u[N];
int lcp[N * 3];

void bil()
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < n[i]; ++j)
        {
            s[m++] = a[i][j];
        }
        if (i == 0)
            s[m++] = 'A';
        else if (i == 1)
            s[m++] = 'B';
        else
            s[m++] = 'C';
    }
    vector<pair<char, int> > v;
    for (int i = 0; i < m; ++i)
    {
        v.push_back(m_p(s[i], i));
    }
    sort(all(v));
    for (int i = 0; i < m; ++i)
    {
        p[i] = v[i].se;
    }
    z = 0;
    c[p[0]] = z++;
    for (int i = 1; i < m; ++i)
    {
        if (s[p[i]] == s[p[i - 1]])
            c[p[i]] = c[p[i - 1]];
        else
            c[p[i]] = z++;
    }
    for (int u = 0; (1 << u) < m; ++u)
    {
        memset(q, 0, sizeof q);
        for (int i = 0; i < m; ++i)
        {
            q[c[i]]++;
        }
        for (int i = 1; i < z; ++i)
            q[i] += q[i - 1];
        for (int i = m - 1; i >= 0; --i)
        {
            int j = (p[i] - (1 << u));
            j %= m;
            if (j < 0)
                j += m;
            np[--q[c[j]]] = j;
        }
        memcpy(p, np, sizeof np);
        z = 0;
        nc[p[0]] = z++;
        for (int i = 1; i < m; ++i)
        {
            if (m_p(c[p[i]], c[(p[i] + (1 << u)) % m]) == m_p(c[p[i - 1]], c[(p[i - 1] + (1 << u)) % m]))
                nc[p[i]] = nc[p[i - 1]];
            else
                nc[p[i]] = z++;
        }
        memcpy(c, nc, sizeof nc);
    }
    for (int i = 0; i < m; ++i)
    {
        u[p[i]] = i;
    }
    int k = 0;
    for (int i = 0; i < m; ++i)
    {
        if (u[i] == m - 1)
        {
            k = 0;
            lcp[u[i]] = k;
            continue;
        }
        while (s[i + k] == s[p[u[i] + 1] + k])
            ++k;
        lcp[u[i]] = k;
        k = max(k - 1, 0);
    }
}

vector<pair<int, int> > v[N * 3];

int p1[N * 3];
int q1[N * 3][3];

int fi(int x)
{
    if (p1[x] == x)
        return x;
    return p1[x] = fi(p1[x]);
}

ll yans;

void kpc(int x, int y)
{
    x = fi(x);
    y = fi(y);
    yans = (yans - (((q1[x][0] * 1LL * q1[x][1]) % M) * 1LL * q1[x][2]) % M + M) % M;
    yans = (yans - (((q1[y][0] * 1LL * q1[y][1]) % M) * 1LL * q1[y][2]) % M + M) % M;
    q1[y][0] += q1[x][0];
    q1[y][1] += q1[x][1];
    q1[y][2] += q1[x][2];
    p1[x] = y;
    yans = (yans + (((q1[y][0] * 1LL * q1[y][1]) % M) * 1LL * q1[y][2]) % M) % M;
}

int ans[N];

void solv()
{
    for (int i = 0; i < 3; ++i)
    {
        scanf(" %s", a[i]);
        n[i] = strlen(a[i]);
    }
    bil();
    for (int i = 0; i < m - 1; ++i)
    {
        v[lcp[i]].push_back(m_p(p[i], p[i + 1]));
    }
    for (int i = 0; i < m; ++i)
    {
        p1[i] = i;
        if (0 <= i && i < n[0])
            q1[i][0] = 1;
        else if (n[0] + 1 <= i && i < n[0] + 1 + n[1])
            q1[i][1] = 1;
        else if (n[0] + 1 + n[1] + 1 <= i && i < n[0] + 1 + n[1] + 1 + n[2])
            q1[i][2] = 1;
    }
    for (int i = m; i >= 0; --i)
    {
        for (int j = 0; j < v[i].size(); ++j)
        {
            int x = v[i][j].fi;
            int y = v[i][j].se;
            if (fi(x) != fi(y))
            {
                kpc(x, y);
            }
        }
        ans[i] = yans;
    }
    /*printf("%s\n", s);
    for (int i = 0; i < m; ++i)
        printf("%d ", fi(i));
    printf("\n");*/
    for (int i = 1; i <= min(n[0], min(n[1], n[2])); ++i)
        printf("%d ", ans[i]);
    printf("\n");
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