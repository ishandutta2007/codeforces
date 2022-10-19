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
int l[N], r[N];

int ans[31];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> l[i] >> r[i];

    for (int j = 0; j < 31; ++j)
    {
        vector<pair<int, int> > v;
        for (int i = 1; i <= n; ++i)
        {
            if (j == 30)
            {
                v.push_back(m_p(l[i], 1));
                v.push_back(m_p(r[i] + 1, -1));
                continue;
            }
            if ((r[i] - l[i] + 1) >= (1 << j))
            {
                v.push_back(m_p(0, 1));
                v.push_back(m_p((1 << j), -1));
            }
            else
            {
                if ((l[i] % (1 << j)) <= (r[i] % (1 << j)))
                {
                    v.push_back(m_p((l[i] % (1 << j)), 1));
                    v.push_back(m_p((r[i] % (1 << j)) + 1, -1));
                }
                else
                {
                    v.push_back(m_p(0, 1));
                    v.push_back(m_p((1 << j), -1));
                    v.push_back(m_p((l[i] % (1 << j)), 1));
                    v.push_back(m_p((r[i] % (1 << j)) + 1, -1));
                }
            }
        }

        sort(all(v));
        int yans = 0;
        for (int i = 0; i < sz(v); ++i)
        {
            yans += v[i].se;
            ans[j] = max(ans[j], yans);
        }
    }

    int qq;
    cin >> qq;
    while (qq--)
    {
        int x;
        cin >> x;

        int j = 30;
        for (int i = 0; i < 30; ++i)
        {
            if ((x & (1 << i)))
            {
                j = i;
                break;
            }
        }

        cout << ans[j] << "\n";
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