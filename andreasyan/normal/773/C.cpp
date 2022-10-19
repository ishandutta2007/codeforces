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

int n;
ll a[N];

const int m = 44;
int q[m];
int cq[m];

int qq[m];
int v[m];
int t[m];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    vector<ll> b;
    for (int i = 1; i <= n; ++i)
    {
        bool z = false;
        for (int j = 0; j < m; ++j)
        {
            if (a[i] == (1LL << j))
            {
                ++q[j];
                z = true;
                break;
            }
        }
        if (!z)
            b.push_back(a[i]);
    }

    for (int i = 0; i < sz(b); ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (b[i] <= (1LL << j))
            {
                cq[j]++;
                break;
            }
        }
    }

    bool zz = false;
    for (int i = 1; i <= n; ++i)
    {
        if (q[0] < i)
            break;
        v[0] = i;
        for (int j = 1; j < m; ++j)
        {
            v[j] = min(v[j - 1], q[j]);
        }

        for (int j = 0; j < m; ++j)
            qq[j] = q[j] - v[j];

        for (int j = 0; j < m - 1; ++j)
            t[j + 1] = v[j] - v[j + 1];

        for (int j = 0; j < m; ++j)
            qq[j] += cq[j];

        int s = 0;
        for (int j = 0; j < m; ++j)
            s += qq[j];
        if (s > i)
            continue;
        qq[0] += (i - s);

        bool z = true;
        int qqq = 0;
        for (int j = 0; j < m; ++j)
        {
            qqq += qq[j];
            if (qqq < t[j])
            {
                z = false;
                break;
            }
            qqq -= t[j];
        }

        if (z)
        {
            zz = true;
            cout << i << ' ';
        }
    }

    if (!zz)
        cout << "-1\n";
    else
        cout << "\n";
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