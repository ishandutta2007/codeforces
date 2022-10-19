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

bool p[N];
void pre()
{
    p[0] = p[1] = true;
    for (int i = 2; i < N; ++i)
    {
        if (p[i])
            continue;
        for (int j = i + i; j < N; j += i)
            p[j] = true;
    }
    for (int i = 0; i < N; ++i)
        p[i] ^= true;
}

int n, e;
int a[N];

void solv()
{
    cin >> n >> e;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    ll ans = 0;

    for (int s = 1; s <= e; ++s)
    {
        vector<int> v;
        for (int j = s; j <= n; j += e)
            v.push_back(a[j]);

        vector<int> l;
        vector<int> r;
        l.assign(sz(v), 0);
        r.assign(sz(v), 0);

        for (int j = 0; j < sz(v); ++j)
        {
            if (v[j] == 1)
            {
                if (j - 1 >= 0)
                    l[j] = l[j - 1] + 1;
                else
                    l[j] = 1;
            }
            else
                l[j] = 0;
        }
        for (int j = sz(v) - 1; j >= 0; --j)
        {
            if (v[j] == 1)
            {
                if (j + 1 < sz(v))
                    r[j] = r[j + 1] + 1;
                else
                    r[j] = 1;
            }
            else
                r[j] = 0;
        }

        for (int j = 0; j < sz(v); ++j)
        {
            if (p[v[j]])
            {
                int ql = 1;
                if (j - 1 >= 0)
                    ql += l[j - 1];
                int qr = 1;
                if (j + 1 < sz(v))
                    qr += r[j + 1];
                ans += ql * 1LL * qr;
                --ans;
            }
        }
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

    pre();

    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}