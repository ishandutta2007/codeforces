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
const int N = 500005;

int n;
char a[N];

ll ans = 0;

void rec(int l, int r)
{
    if (l == r)
    {
        if (a[l] == '1')
            ++ans;
        return;
    }
    int m = (l + r) / 2;

    bool z = true;
    int qr = 0;
    vector<int> vr;
    int q = 0;
    for (int i = m + 1; i <= r; ++i)
    {
        if (z)
        {
            if (a[i] == '1')
                ++qr;
            else
            {
                z = false;
                vr.push_back(qr);
            }
        }
        else
        {
            if (a[i] == '1')
                ++q;
            else
                q = 0;
            vr.push_back(max(vr.back(), q));
        }
    }

    z = true;
    int ql = 0;
    vector<int> vl;
    q = 0;
    for (int i = m; i >= l; --i)
    {
        if (z)
        {
            if (a[i] == '1')
                ++ql;
            else
            {
                z = false;
                vl.push_back(ql);
            }
        }
        else
        {
            if (a[i] == '1')
                ++q;
            else
                q = 0;
            vl.push_back(max(vl.back(), q));
        }
    }

    for (int i = 1; i <= ql; ++i)
    {
        ans += i * 1LL * qr;
        ans += (qr * 1LL * (qr + 1)) / 2;
    }

    vector<ll> sl;
    sl.assign(sz(vl) + 1, 0);
    for (int i = sz(vl) - 1; i >= 0; --i)
        sl[i] = sl[i + 1] + vl[i];

    vector<ll> sr;
    sr.assign(sz(vr) + 1, 0);
    for (int i = sz(vr) - 1; i >= 0; --i)
        sr[i] = sr[i + 1] + vr[i];

    int j = 0;
    for (int i = 0; i < sz(vr); ++i)
    {
        while (j < sz(vl) && max(vr[i], ql + qr) > vl[j])
        {
            ++j;
        }
        ans += j * 1LL * max(vr[i], ql + qr);
        ans += sl[j];
    }

    j = 0;
    for (int i = 1; i <= qr; ++i)
    {
        while (j < sz(vl) && i + ql > vl[j])
        {
            ++j;
        }
        ans += j * 1LL * (i + ql);
        ans += sl[j];
    }

    j = 0;
    for (int i = 1; i <= ql; ++i)
    {
        while (j < sz(vr) && i + qr > vr[j])
        {
            ++j;
        }
        ans += j * 1LL * (i + qr);
        ans += sr[j];
    }

    rec(l, m);
    rec(m + 1, r);
}

void solv()
{
    scanf("%d", &n);
    scanf(" %s", (a + 1));
    rec(1, n);
    printf("%lld\n", ans);
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