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
const int N = 12, M = 10004;

int n, m;
int s[N];
char a[N][M];

int ansv[M];

void solv()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    int ans = -1;
    for (int x = 0; x < (1 << n); ++x)
    {
        int yans = 0;
        for (int i = 0; i < n; ++i)
        {
            if ((x & (1 << i)))
                yans += s[i];
            else
                yans -= s[i];
        }

        vector<pair<int, int> > v;
        for (int j = 0; j < m; ++j)
        {
            int q = 0;
            for (int i = 0; i < n; ++i)
            {
                if (a[i][j] == '1')
                {
                    if ((x & (1 << i)))
                        --q;
                    else
                        ++q;
                }
            }
            v.push_back(m_p(q, j));
        }

        sort(all(v));
        for (int i = 0; i < m; ++i)
            yans += v[i].fi * (i + 1);

        if (yans > ans)
        {
            ans = yans;
            for (int i = 0; i < m; ++i)
                ansv[v[i].se] = i + 1;
        }
    }

    for (int i = 0; i < m; ++i)
        cout << ansv[i] << ' ';
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
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}