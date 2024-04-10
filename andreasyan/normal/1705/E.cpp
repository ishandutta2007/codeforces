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
const int N = 210005, S = 450, M = 200000;

int n, qq;
int a[N];
int q[N];

int v[S], u[S];
int t[S];
void ubd(int x)
{
    v[x] = 0;
    memset(t, 0, sizeof t);
    for (int i = x * S; i < (x + 1) * S; ++i)
    {
        v[x] /= 2;
        v[x] += q[i];
        t[i - x * S] = (v[x] % 2);
    }

    u[x] = 1;
    for (int i = S - 2; i >= 0; --i)
    {
        u[x] *= 2;
        u[x] -= t[i];
        if (u[x] > N)
            break;
    }
    u[x] *= 2;
}

void solv()
{
    n = 10;
    qq = 1;
    cin >> n >> qq;
    for (int i = 1; i <= M; ++i)
        q[i] = 0;
    for (int i = 1; i <= n; ++i)
    {
        a[i] = rnf() % M + 1;
        cin >> a[i];
        ++q[a[i]];
    }

    for (int x = 1 / S; x <= M / S; ++x)
        ubd(x);

    multiset<int> s;
    for (int i = 1; i <= n; ++i)
        s.insert(a[i]);

    while (qq--)
    {
        int i, b;
        i = rnf() % n + 1;
        b = rnf() % M + 1;
        cin >> i >> b;

        s.erase(s.find(a[i]));
        --q[a[i]];
        ubd(a[i] / S);

        a[i] = b;

        s.insert(a[i]);
        ++q[a[i]];
        ubd(a[i] / S);

        int maxu = *(--s.end());

        int qq;
        int g = (maxu / S) - 1;
        if (g == -1)
            qq = 0;
        else
        {
            qq = v[g];
            int m = 1;
            bool z = false;
            for (int i = g; i >= 0; --i)
            {
                if (m > 1)
                    break;
                if (m == 1)
                {
                    m = u[i];
                    if (i)
                        m -= v[i - 1];
                }
                else
                {
                    ++qq;
                    z = true;
                    break;
                }
            }
            if (!z && m <= 0)
            {
                ++qq;
            }
        }

        for (int i = (g + 1) * S; i <= maxu; ++i)
        {
            qq /= 2;
            qq += q[i];
        }

        int ans = maxu;
        while (qq >= 2)
        {
            qq /= 2;
            ++ans;
        }

        cout << ans << "\n";

        /*int ans0 = 0;
        int gg = 0;
        for (int i = 0; i <= M + 40; ++i)
        {
            gg /= 2;
            gg += q[i];
            if (gg)
                ans0 = i;
        }

        if (ans != ans0)
        {
            cout << "WA" << endl;
            cout << n << endl;
            for (int i = 1; i <= n; ++i)
                cout << a[i] << ' ';
            cout << endl;
            cout << qq << endl;
            cout << i << ' ' << b << endl;
            exit(0);
        }*/
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
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}