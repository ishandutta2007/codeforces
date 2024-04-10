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
const int N = 1003;

int n;
int d[N];

int z;
int c[N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> d[i];

    z = 0;
    for (int i = 1; i <= n; ++i)
        c[i] = 0;
    while (1)
    {
        int maxu = -1;
        for (int i = 1; i <= n; ++i)
        {
            if (!c[i])
                maxu = max(maxu, d[i]);
        }
        if (maxu == -1)
            break;

        for (int i = 1; i <= n; ++i)
        {
            if (!c[i] && d[i] == maxu)
            {
                vector<int> v;
                for (int j = 0; j < d[i]; ++j)
                {
                    cout << "? " << i << endl;
                    int h;
                    cin >> h;
                    v.push_back(h);
                    if (c[h])
                        break;
                }

                int g = 0;
                for (int j = 0; j < sz(v); ++j)
                {
                    if (c[v[j]])
                    {
                        g = c[v[j]];
                        break;
                    }
                }

                if (g)
                {
                    c[i] = g;
                    for (int j = 0; j < sz(v); ++j)
                    {
                        if (!c[v[j]])
                            c[v[j]] = g;
                        else if (c[v[j]] != g)
                        {
                            int t = c[v[j]];
                            for (int i = 1; i <= n; ++i)
                            {
                                if (c[i] == t)
                                {
                                    c[i] = g;
                                }
                            }
                        }
                    }
                }
                else
                {
                    ++z;
                    c[i] = z;
                    for (int j = 0; j < sz(v); ++j)
                        c[v[j]] = z;
                }
                break;
            }
        }
    }

    cout << "! ";
    for (int i = 1; i <= n; ++i)
        cout << c[i] << ' ';
    cout << endl;
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