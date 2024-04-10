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

vector<int> v[11];

int n, k;

int q;
bool c[10];
bool stg(int l, int r)
{
    if (r < 178000)
        cout << "";
    vector<int> vl;
    while (l)
    {
        vl.push_back(l % 10);
        l /= 10;
    }

    vector<int> vr;
    while (r)
    {
        vr.push_back(r % 10);
        r /= 10;
    }

    while (sz(vl) < sz(vr))
        vl.push_back(-1);

    reverse(all(vl));
    reverse(all(vr));

    // right is good
    memset(c, false, sizeof c);
    for (int i = 0; i < sz(vr); ++i)
    {
        c[vr[i]] = true;
    }
    q = 0;
    for (int i = 0; i < 10; ++i)
        q += c[i];
    if (q <= k)
        return true;
    // left is good
    memset(c, false, sizeof c);
    for (int i = 0; i < sz(vl); ++i)
    {
        if (vl[i] == -1)
            continue;
        c[vl[i]] = true;
    }
    q = 0;
    for (int i = 0; i < 10; ++i)
        q += c[i];
    if (q <= k)
        return true;

    int ph = 0;
    while (ph < sz(vr) && vl[ph] == vr[ph])
        ++ph;

    // ri prefix
    for (int i = 0; i < sz(vr); ++i)
    {
        memset(c, false, sizeof c);
        for (int j = 0; j < i; ++j)
        {
            c[vr[j]] = true;
        }
        q = 0;
        for (int i = 0; i < 10; ++i)
            q += c[i];

        int vli;
        if (i - 1 < ph)
        {
            if (vl[i] == -1)
                vli = 0;
            else
                vli = vl[i];
        }
        else
            vli = -1;
        int vri = vr[i];
        for (int x = vli + 1; x < vri; ++x)
        {
            if (!c[x])
            {
                if (q + 1 <= k)
                    return true;
            }
            else
            {
                if (q <= k)
                    return true;
                break;
            }
        }
    }

    // li prefix
    for (int i = 0; i < sz(vl); ++i)
    {
        memset(c, false, sizeof c);
        for (int j = 0; j < i; ++j)
        {
            if (vl[j] == -1)
                continue;
            c[vl[j]] = true;
        }
        q = 0;
        for (int i = 0; i < 10; ++i)
            q += c[i];

        int vli;
        if (vl[i] == -1)
            vli = 0;
        else
            vli = vl[i];
        int vri;
        if (i - 1 < ph)
            vri = vr[i];
        else
            vri = 10;
        for (int x = vli + 1; x < vri; ++x)
        {
            if (!c[x])
            {
                if (q + 1 <= k)
                    return true;
            }
            else
            {
                if (q <= k)
                    return true;
                break;
            }
        }
    }

    return false;
}

void solv()
{
    cin >> n >> k;

    int l = n, r = 1111111111;
    int ans;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (stg(n, m))
        {
            ans = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }

    stg(n, ans);
    cout << ans << "\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    /*for (int x = 0; x < (1 << 10); ++x)
    {
        int q = 0;
        for (int i = 0; i < 10; ++i)
        {
            if ((x & (1 << i)))
                ++q;
        }
        v[q].push_back(x);
    }

    /*int s = 0;
    for (int q = 0; q <= 2; ++q)
        s += sz(v[q]);
    cout << s << "\n";
    return 0;*/

    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}