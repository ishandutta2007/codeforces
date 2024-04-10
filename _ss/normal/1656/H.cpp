#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(), vr.end()

//using ll = long long;
using ll = unsigned __int128;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;

const int N = 1e3 + 10;

ll gcd(ll a, ll b)
{
    while (b)
    {
        ll r = a % b;
        a = b;
        b = r;
    }
    return a;
}

struct segment_tree
{
    int n, v;
    ll it[N * 4], x;

    void build(int id, int l, int r, ll ar[])
    {
        if (l == r)
        {
            it[id] = ar[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(id << 1, l, mid, ar);
        build((id << 1) | 1, mid + 1, r, ar);
        it[id] = gcd(it[id << 1], it[(id << 1) | 1]);
    }

    void init(ll ar[], int len)
    {
        n = len;
        build(1, 1, n, ar);
    }

    void update(int id, int l, int r)
    {
        if (l == r)
        {
            it[id] = x;
            return;
        }
        int mid = (l + r) >> 1;
        if (v <= mid) update(id << 1, l, mid);
        else update((id << 1) | 1, mid + 1, r);
        it[id] = gcd(it[id << 1], it[(id << 1) | 1]);
    }

    void Update(int r, ll val)
    {
        v = r;
        x = val;
        update(1, 1, n);
    }

    ll Get()
    {
        return it[1];
    }
} segA[N], segB[N];

ll a[N], b[N], valAB[N][N], valBA[N][N];
int n, m;

ll read()
{
    string s;
    cin >> s;
    ll res = 0;
    for (char c : s) res = res * 10 + c - '0';
    return res;
}

void print(ll x)
{
    string s;
    while (x)
    {
        s += (char)(x % 10 + '0');
        x /= 10;
    }
    reverse(all(s));
    cout << s << " ";
}
int markA[N], markB[N];

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) a[i] = read();
        for (int i = 1; i <= m; ++i) b[i] = read();
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
            {
                ll g = gcd(a[i], b[j]);
                valAB[i][j] = a[i] / g;
                valBA[j][i] = b[j] / g;
            }
        for (int i = 1; i <= n; ++i) segA[i].init(valAB[i], m), markA[i] = 0;
        for (int i = 1; i <= m; ++i) segB[i].init(valBA[i], n), markB[i] = 0;
        bool check = true;
        while (check)
        {
            check = false;
            for (int i = 1; i <= n; ++i)
                if (!markA[i] && segA[i].Get() > 1)
                {
                    markA[i] = 1;
                    for (int j = 1; j <= m; ++j)
                        if (!markB[j]) segB[j].Update(i, 0);
                    check = true;
                }
            for (int i = 1; i <= m; ++i)
                if (!markB[i] && segB[i].Get() > 1)
                {
                    markB[i] = 1;
                    for (int j = 1; j <= n; ++j)
                        if (!markA[j]) segA[j].Update(i, 0);
                    check = true;
                }
        }
        vll resA, resB;
        for (int i = 1; i <= n; ++i)
            if (!markA[i]) resA.eb(a[i]);
        for (int i = 1; i <= m; ++i)
            if (!markB[i]) resB.eb(b[i]);
        if (resA.empty() || resB.empty())
        {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        cout << resA.size() << " " << resB.size() << "\n";
        for (ll x : resA) print(x);
        cout << "\n";
        for (ll x : resB) print(x);
        cout << "\n";
    }
    return 0;
}