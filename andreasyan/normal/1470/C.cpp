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

int n, k;

int a[N];
int b[N];

int qry(int x)
{
    cout << "? " << x << endl;
    int ans;
    cin >> ans;
    return ans;
}

void solv()
{
    cin >> n >> k;

    /*for (int i = 1; i <= n; ++i)
        a[i] = k;

    int p;
    cin >> p;
    for (int ii = 0; ii < 100; ++ii)
    {
        for (int i = 1; i <= n; ++i)
            b[i] = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (i == p)
                b[i % n + 1] += a[i];
            else
            {
                b[i % n + 1] += (a[i] / 2 + a[i] % 2);
                b[(i - 2 + n) % n + 1] += (a[i] / 2);
            }
        }
        for (int i = 1; i <= n; ++i)
            a[i] = b[i];

        for (int i = 1; i <= n; ++i)
            cout << a[i] % 1000 << ' ';
        cout << "\n";
    }*/

    for (int q = 0; ; ++q)
    {
        int i = rnd() % n + 1;

        int u = qry(i);
        if (u != k)
        {
            if (u < k)
            {
                for (int j = 0; ; ++j)
                {
                    if (qry((i - 1 + (1 << j)) % n + 1) >= k)
                    {
                        vector<int> v;
                        for (int k = i; k <= i + (1 << j); ++k)
                        {
                            v.push_back((k - 1) % n + 1);
                        }
                        int l = 0, r = sz(v) - 1;
                        while (l <= r)
                        {
                            int m = (l + r) / 2;
                            int u = qry(v[m]);
                            if (u == k)
                            {
                                cout << "! " << v[m] << endl;
                                return;
                            }
                            if (u < k)
                                l = m + 1;
                            else
                                r = m - 1;
                        }
                    }
                }
            }
            else
            {
                for (int j = 0; ; ++j)
                {
                    if (qry((i - 1 - (1 << j) + n) % n + 1) >= k)
                    {
                        vector<int> v;
                        for (int k = i; k >= i - (1 << j); --k)
                        {
                            v.push_back((k - 1 + n) % n + 1);
                        }
                        reverse(all(v));
                        int l = 0, r = sz(v) - 1;
                        while (l <= r)
                        {
                            int m = (l + r) / 2;
                            int u = qry(v[m]);
                            if (u == k)
                            {
                                cout << "! " << v[m] << endl;
                                return;
                            }
                            if (u < k)
                                l = m + 1;
                            else
                                r = m - 1;
                        }
                    }
                }
            }
        }
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