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
int a[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);

    int ans = 0;
    int q = 1;
    vector<pair<int, int> > v;
    for (int i = 2; i <= n; ++i)
    {
        if (a[i] == a[i - 1])
            ++q;
        else
        {
            v.push_back(m_p(a[i - 1], q));
            if (q == 1)
                ++ans;
            else
                ans += 2;
            q = 1;
        }
    }
    v.push_back(m_p(a[n], q));
    if (q == 1)
        ++ans;
    else
        ans += 2;

    for (int i = 0; i < sz(v); ++i)
    {
        if (v[i].se > 1)
        {
            for (int j = i + 1; j < sz(v); ++j)
            {
                if (v[j].se > 1)
                {
                    if (v[i].fi != v[j].fi)
                        break;
                    bool z = true;
                    for (int k = i + 2; k < j; k += 2)
                    {
                        if (v[k].fi != v[i].fi)
                        {
                            z = false;
                            break;
                        }
                    }
                    if (z)
                        --ans;
                    break;
                }
            }
        }
    }

    printf("%d\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    int tt = 1;
    //scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}