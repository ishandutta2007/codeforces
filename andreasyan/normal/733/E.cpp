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
const int N = 1000006;

int n;
char a[N];

int ql[N], qr[N];

void solv()
{
    scanf("%d", &n);
    scanf(" %s", (a + 1));
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == 'U')
            a[i] = 'R';
        else
            a[i] = 'L';
    }
    for (int i = 1; i <= n; ++i)
    {
        qr[i] = qr[i - 1];
        if (a[i] == 'R')
            ++qr[i];
    }
    for (int i = n; i >= 1; --i)
    {
        ql[i] = ql[i + 1];
        if (a[i] == 'L')
            ++ql[i];
    }
    vector<int> vl, vr;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == 'L')
            vl.push_back(i);
        else
            vr.push_back(i);
    }
    vector<ll> pl(vl.size()), pr(vr.size());
    for (int i = 0; i < vl.size(); ++i)
    {
        if (i)
            pl[i] = pl[i - 1];
        else
            pl[i] = 0;
        pl[i] += vl[i];
    }
    for (int i = 0; i < vr.size(); ++i)
    {
        if (i)
            pr[i] = pr[i - 1];
        else
            pr[i] = 0;
        pr[i] += vr[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        int l = 1, r = n;
        int mm;
        while (l <= r)
        {
            int m = (l + r) / 2;
            int ur = (m / 2);
            int ul = (m / 2);
            if (a[i] == 'L')
                ul += (m % 2);
            else
                ur += (m % 2);
            if (ul > qr[i - 1] || ur > ql[i + 1])
            {
                mm = m;
                r = m - 1;
            }
            else
                l = m + 1;
        }
        int ur = (mm / 2);
        int ul = (mm / 2);
        if (a[i] == 'L')
            ul += (mm % 2);
        else
            ur += (mm % 2);
        ll ans = 0;
        ll pans = 0;
        if (ul > qr[i - 1])
        {
            pans += i;
            --ul;
        }
        else
        {
            pans += (n - i + 1);
            --ur;
        }
        if (ur)
        {
            int s = upper_bound(all(vl), i) - vl.begin();
            ans += pl[s + ur - 1];
            if (s - 1 >= 0)
                ans -= pl[s - 1];
            ans -= ur * 1LL * i;
        }
        if (ul)
        {
            int s = lower_bound(all(vr), i) - vr.begin() - 1;
            ans -= pr[s];
            if (s - ul >= 0)
                ans += pr[s - ul];
            ans += ul * 1LL * i;
        }
        ans *= 2;
        ans += pans;
        printf("%lld ", ans);
    }
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