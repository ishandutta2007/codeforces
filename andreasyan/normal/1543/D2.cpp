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
const int N = 200005;

bool z[30];
int u[30];

void solv()
{
    int n, k;
    cin >> n >> k;

    memset(z, false, sizeof z);
    memset(u, 0, sizeof u);
    for (int x = 0; x < n; ++x)
    {
        vector<int> v;
        int y = x;
        while (y)
        {
            v.push_back(y % k);
            y /= k;
        }
        while (sz(v) < 30)
            v.push_back(u[sz(v)]);
        for (int i = 0; i < sz(v); ++i)
        {
            if (!z[i])
                v[i] = (v[i] + u[i]) % k;
            else
                v[i] = (-v[i] + u[i]) % k;
            if (v[i] < 0)
                v[i] += k;
        }

        int q = 0;
        for (int i = sz(v) - 1; i >= 0; --i)
        {
            if (v[i])
            {
                q = i;
                break;
            }
        }

        int a = 1;
        int h = 0;
        for (int i = 0; i <= q; ++i)
        {
            h += v[i] * a;
            a *= k;
        }
        cout << h << endl;

        int r;
        cin >> r;
        if (r == 1)
            return;

        for (int i = 0; i < sz(v); ++i)
        {
            z[i] ^= true;
            u[i] = (-u[i] + v[i]) % k;
            if (u[i] < k)
                u[i] += k;
        }
    }
}

int main()
{
    #ifdef SOMETHING
    //freopen("input.txt", "r", stdin);
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