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
const int N = 2003;
const ll INF = 1000000009000000009;

int n, k;
ll x;
char a[N];

void solv()
{
    cin >> n >> k >> x;
    cin >> a;

    vector<int> v;

    int q = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == '*')
        {
            q += k;
        }
        else
        {
            if (q)
                v.push_back(q);
            q = 0;
            v.push_back(0);
        }
    }
    if (q)
        v.push_back(q);

    for (int i = 0; i < sz(v); ++i)
    {
        if (v[i] == 0)
        {
            putchar('a');
            continue;
        }

        ll u = 1;
        for (int j = i + 1; j < sz(v); ++j)
        {
            if (u > (long double)INF / (v[j] + 1))
                u = x + 1;
            else
                u *= (v[j] + 1);
        }

        for (int q = 0; q <= v[i]; ++q)
        {
            if (x <= u)
            {
                for (int j = 0; j < q; ++j)
                    putchar('b');
                break;
            }
            else
                x -= u;
        }
    }
    putchar('\n');
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}