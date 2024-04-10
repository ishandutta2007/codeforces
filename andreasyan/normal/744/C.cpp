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
const int N = 16;
const int INF = 1000000009;

int n;
int ty[N], r[N], b[N];

vector<pair<int, int> > v[(1 << N)];

void solv()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf(" %c%d%d", &ty[i], &r[i], &b[i]);
    }
    v[0].push_back(m_p(0, 0));
    for (int x = 1; x < (1 << n); ++x)
    {
        int R = 0, B = 0;
        for (int i = 0; i < n; ++i)
        {
            if ((x & (1 << i)))
            {
                if (ty[i] == 'R')
                    ++R;
                else
                    ++B;
            }
        }
        vector<pair<int, int> > vv;
        for (int i = 0; i < n; ++i)
        {
            if ((x & (1 << i)))
            {
                if (ty[i] == 'R')
                    --R;
                else
                    --B;
                int y = (x ^ (1 << i));
                for (int j = 0; j < v[y].size(); ++j)
                {
                    vv.push_back(m_p(v[y][j].fi + max(0, r[i] - R), v[y][j].se + max(0, b[i] - B)));
                }
                if (ty[i] == 'R')
                    ++R;
                else
                    ++B;
            }
        }
        sort(all(vv));
        for (int i = 0; i < vv.size(); ++i)
        {
            if (!i || vv[i].fi != vv[i - 1].fi)
                v[x].push_back(vv[i]);
        }
    }
    int ans = INF;
    for (int i = 0; i < v[(1 << n) - 1].size(); ++i)
    {
        ans = min(ans, max(v[(1 << n) - 1][i].fi, v[(1 << n) - 1][i].se));
    }
    ans += n;
    printf("%d\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}