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
const int N = 100005, S = 2100;

struct ban
{
    int l, r, k, t;
    int i;
    ban(){}
    ban(int l, int r, int k, int t, int i)
    {
        this->l = l;
        this->r = r;
        this->k = k;
        this->t = t;
        this->i = i;
    }
};

bool operator<(const ban& a, const ban& b)
{
    if (a.l / S != b.l / S)
        return a.l / S < b.l / S;
    if (a.r / S != b.r / S)
        return a.r / S < b.r / S;
    return a.t < b.t;
}

int n, m;
int a[N];

int ti;
int p[N], x[N], xx[N];
vector<ban> b;

int ans[N];

int q[N];
int qq[N];
bool c[N];
vector<int> v;

void ubd(int x, int y)
{
    --qq[q[x]];
    q[x] += y;
    ++qq[q[x]];
    if (qq[q[x]] == 1 && !c[q[x]])
    {
        c[q[x]] = true;
        v.push_back(q[x]);
    }
}

vector<int> vv;

void solv()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= m; ++i)
    {
        int ty;
        cin >> ty;
        if (ty == 1)
        {
            ban u;
            cin >> u.l >> u.r >> u.k;
            u.t = ti;
            u.i = i;
            b.push_back(u);
        }
        else
        {
            ++ti;
            cin >> p[ti] >> x[ti];
            xx[ti] = a[p[ti]];
            a[p[ti]] = x[ti];
        }
        ans[i] = -2;
    }
    for (int i = ti; i >= 1; --i)
    {
        a[p[i]] = xx[i];
    }

    sort(all(b));
    int l = 1, r = 0, t = 0;
    qq[0] = N;
    for (int i = 0; i < sz(b); ++i)
    {
        while (r < b[i].r)
        {
            ++r;
            ubd(a[r], 1);
        }
        while (l > b[i].l)
        {
            --l;
            ubd(a[l], 1);
        }
        while (r > b[i].r)
        {
            ubd(a[r], -1);
            --r;
        }
        while (l < b[i].l)
        {
            ubd(a[l], -1);
            ++l;
        }
        while (t < b[i].t)
        {
            ++t;
            if (l <= p[t] && p[t] <= r)
                ubd(a[p[t]], -1);
            a[p[t]] = x[t];
            if (l <= p[t] && p[t] <= r)
                ubd(a[p[t]], 1);
        }
        while (t > b[i].t)
        {
            if (l <= p[t] && p[t] <= r)
                ubd(a[p[t]], -1);
            a[p[t]] = xx[t];
            if (l <= p[t] && p[t] <= r)
                ubd(a[p[t]], 1);
            --t;
        }

        vv.clear();
        for (int i = 0; i < sz(v); ++i)
        {
            if (qq[v[i]])
                vv.push_back(v[i]);
            else
                c[v[i]] = false;
        }
        v = vv;
        sort(all(v));

        {
            ans[b[i].i] = N;
            int k = 0;
            int l = 0;
            for (int r = 0; r < sz(v); ++r)
            {
                k += qq[v[r]];
                while (k - qq[v[l]] >= b[i].k)
                {
                    k -= qq[v[l]];
                    ++l;
                }
                if (k >= b[i].k)
                    ans[b[i].i] = min(ans[b[i].i], v[r] - v[l]);
            }
            if (ans[b[i].i] == N)
                ans[b[i].i] = -1;
        }
    }

    for (int i = 1; i <= m; ++i)
    {
        if (ans[i] == -2)
            continue;
        cout << ans[i] << "\n";
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    //scanf("%d", &tt);
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}