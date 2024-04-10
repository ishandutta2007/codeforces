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
const int N = 200005, S = 400, M = 20;

int n, m;
int u[N];

struct ban
{
    int i;
    int l, r;
};
bool operator<(const ban& a, const ban& b)
{
    if (a.l / S < b.l / S)
        return true;
    if (a.l / S > b.l / S)
        return false;
    if ((a.l / S) % 2)
        return a.r < b.r;
    return a.r > b.r;
}

int k;
ban b[N];

int yans;
int z;
int t[N * 30][2];
int q[N * 30];

void ave(int x)
{
    yans ^= x;
    int pos = 0;
    for (int i = 0; i < M; ++i)
    {
        int u = !!(x & (1 << i));
        if (!t[pos][u])
            t[pos][u] = ++z;
        pos = t[pos][u];
        q[pos] ^= 1;
    }
}

void han(int x)
{
    ave(x);
}

void pp()
{
    int pos = 0;
    for (int i = 0; i < M; ++i)
    {
        yans ^= ((1 << i) * q[t[pos][0]]);
        yans ^= ((1 << i) * q[t[pos][1]]);
        swap(t[pos][0], t[pos][1]);
        pos = t[pos][0];
        if (!pos)
            break;
    }
}

void mm()
{
    int pos = 0;
    for (int i = 0; i < M; ++i)
    {
        yans ^= ((1 << i) * q[t[pos][0]]);
        yans ^= ((1 << i) * q[t[pos][1]]);
        swap(t[pos][0], t[pos][1]);
        pos = t[pos][1];
        if (!pos)
            break;
    }
}

char ans[N];

void solv()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        u[x] ^= 1;
    }

    cin >> k;
    for (int i = 0; i < k; ++i)
    {
        b[i].i = i;
        cin >> b[i].l >> b[i].r;
    }
    sort(b, b + k);

    int l = 1, r = 0;
    for (int i = 0; i < k; ++i)
    {
        while (r < b[i].r)
        {
            ++r;
            if (u[r])
                ave(r - l);
        }
        while (l > b[i].l)
        {
            --l;
            pp();
            if (u[l])
                ave(0);
        }
        while (r > b[i].r)
        {
            if (u[r])
                han(r - l);
            --r;
        }
        while (l < b[i].l)
        {
            if (u[l])
                han(0);
            mm();
            ++l;
        }
        if (yans)
            ans[b[i].i] = 'A';
        else
            ans[b[i].i] = 'B';
    }

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
    {
        solv();
    }
    return 0;
}