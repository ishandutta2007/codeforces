#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(), vr.end()

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;

const int N = 5e5 + 10;


namespace myrand
{
    mt19937 mt(chrono::system_clock::now().time_since_epoch() / chrono::microseconds(1));
    ll Int(ll l,ll r) {return uniform_int_distribution<ll> (l,r)(mt);}
}
using namespace myrand;
auto start_time = chrono::system_clock::now();

ld get_time()
{
    auto Now = chrono::system_clock::now();
    return (chrono::duration_cast<chrono::nanoseconds>(Now - start_time).count() * 1e-9);
}

struct RMQ_min
{
    int lg[N];
    pii spr[20][N];
    void build(pii a[], int n)
    {
        for (int i = 1; i <= n; ++i)
        {
            spr[0][i] = a[i];
            int x = i;
            lg[i] = 0;
            while (x > 1) lg[i]++, x >>= 1;
        }
        for (int i = 1; i <= lg[n]; ++i)
            for (int j = 1; j <= n - (1 << i) + 1; ++j)
                spr[i][j] = min(spr[i - 1][j], spr[i - 1][j + (1 << (i - 1))]);
    }

    pii rmq(int l, int r)
    {
        int k = lg[r - l + 1];
        return min(spr[k][l], spr[k][r - (1 << k) + 1]);
    }
} tab_min;

struct RMQ_max
{
    int lg[N];
    pii spr[20][N];
    void build(pii a[], int n)
    {
        for (int i = 1; i <= n; ++i)
        {
            spr[0][i] = a[i];
            int x = i;
            lg[i] = 0;
            while (x > 1) lg[i]++, x >>= 1;
        }
        for (int i = 1; i <= lg[n]; ++i)
            for (int j = 1; j <= n - (1 << i) + 1; ++j)
                spr[i][j] = max(spr[i - 1][j], spr[i - 1][j + (1 << (i - 1))]);
    }

    pii rmq(int l, int r)
    {
        int k = lg[r - l + 1];
        return max(spr[k][l], spr[k][r - (1 << k) + 1]);
    }
} tab_max;

pii a[N];

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    //t = 2;
    while (t--)
    {
        int n;
        cin >> n;
        /*n = 1e5;
        vi p(n);
        for (int i = 0; i < n; ++i) p[i] = i + 1;
        shuffle(all(p), mt);*/
        for (int i = 1; i <= n; ++i) cin >> a[i].fi/*a[i].fi = p[i - 1]*/, a[i].se = i;
        if (n == 1)
        {
            cout << "0\n";
            continue;
        }
        tab_min.build(a, n);
        tab_max.build(a, n);
        int l = tab_min.rmq(1, n).se;
        int r = tab_max.rmq(1, n).se;
        int fl = 0, fr = 1;
        if (l > r)
        {
            swap(l, r);
            swap(fl, fr);
        }
        int res = 1;
        while (l != 1)
        {
            fl ^= 1;
            if (fl) l = tab_max.rmq(1, l).se;
            else l = tab_min.rmq(1, l).se;
            res++;
        }
        while (r != n)
        {
            fr ^= 1;
            if (fr) r = tab_max.rmq(r, n).se;
            else r = tab_min.rmq(r, n).se;
            res++;
        }
        cout << res << "\n";
    }
    return 0;
}