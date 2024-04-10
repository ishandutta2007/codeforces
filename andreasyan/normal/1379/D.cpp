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
const int N = 100005;

int n, H, M, k;
int h[N], m[N];

bool so(const pair<int, int>& a, const pair<int, int>& b)
{
    if (a.fi < b.fi)
        return true;
    if (a.fi > b.fi)
        return false;
    return a.se > b.se;
}

void solv()
{
    scanf("%d%d%d%d", &n, &H, &M, &k);
    vector<pair<int, int> > v;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d", &h[i], &m[i]);
        int l = m[i] + 1;
        int r = m[i] + k - 1;
        l %= (M / 2);
        l += (M / 2);
        l %= (M / 2);
        r %= (M / 2);
        r += (M / 2);
        r %= (M / 2);
        if (l <= r)
        {
            v.push_back(m_p(l, 1));
            v.push_back(m_p(r + 1, -1));
        }
        else
        {
            v.push_back(m_p(l, 1));
            v.push_back(m_p(M / 2, -1));
            v.push_back(m_p(0, 1));
            v.push_back(m_p(r + 1, -1));
        }
    }
    sort(all(v), so);

    if (k == 1)
    {
        printf("0 0\n\n");
        return;
    }

    int minu = N;
    int t = -1;

    if (v[0].fi != 0)
    {
        minu = 0;
        t = 0;
    }

    int q = 0;
    for (int i = 0; i < sz(v); ++i)
    {
        q += v[i].se;
        if (q < minu && v[i].fi < (M / 2) && (i == sz(v) - 1 || v[i].fi != v[i + 1].fi))
        {
            minu = q;
            t = v[i].fi;
        }
    }

    printf("%d %d\n", minu, t);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d", &h[i], &m[i]);
        int l = m[i] + 1;
        int r = m[i] + k - 1;
        l %= (M / 2);
        l += (M / 2);
        l %= (M / 2);
        r %= (M / 2);
        r += (M / 2);
        r %= (M / 2);
        if (l <= r)
        {
            if (l <= t && t <= r)
                printf("%d ", i);
        }
        else
        {
            if (l <= t || t <= r)
                printf("%d ", i);
        }
    }
    printf("\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}