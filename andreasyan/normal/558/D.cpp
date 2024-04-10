#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
typedef long long ll;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);

ll h;
int qq;

pair<ll, ll> hat(const pair<ll, ll>& a, const pair<ll, ll>& b)
{
    return m_p(max(a.fi, b.fi), min(a.se, b.se));
}

long long yans = -1;
void ubd(pair<ll, ll> ans1, pair<ll, ll> u)
{
    u = hat(ans1, u);
    if (u.fi > u.se)
        return;
    if (u.se - u.fi + 1 > 1)
    {
        printf("Data not sufficient!\n");
        exit(0);
    }
    if (yans != -1)
    {
        printf("Data not sufficient!");
        exit(0);
    }
    yans = u.fi;
}

void solv()
{
    scanf("%lld%d", &h, &qq);
    pair<ll, ll> ans1 = m_p((1LL << (h - 1)), (1LL << h) - 1);
    vector<pair<ll, ll> > ans0;
    while (qq--)
    {
        ll i;
        int ty;
        pair<ll, ll> u;
        scanf("%lld%lld%lld%d", &i, &u.fi, &u.se, &ty);
        u = hat(u, m_p((1LL << (i - 1)), (1LL << i) - 1));
        for (ll j = i + 1; j <= h; ++j)
        {
            u.fi = (u.fi * 2);
            u.se = (u.se * 2 + 1);
        }
        if (ty == 1)
        {
            ans1 = hat(ans1, u);
        }
        else
        {
            if (u.fi <= u.se)
                ans0.push_back(u);
        }
    }
    vector<pair<ll, int> > v;
    v.push_back(m_p((1LL << (h - 1)), 0));
    for (int i = 0; i < ans0.size(); ++i)
    {
        v.push_back(m_p(ans0[i].fi, 1));
        v.push_back(m_p(ans0[i].se + 1, -1));
    }
    v.push_back(m_p((1LL << h), 0));
    sort(all(v));
    int q = 0;
    for (int i = 0; i < v.size() - 1; ++i)
    {
        q += v[i].se;
        if (q == 0)
        {
            ubd(ans1, m_p(v[i].fi, v[i + 1].fi - 1));
        }
    }
    if (yans == -1)
        printf("Game cheated!\n");
    else
        printf("%lld\n", yans);
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