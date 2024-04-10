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

int n;
int a[N];

int q[N];
bool c[N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 0; i <= n; ++i)
        q[i] = 0;
    for (int i = 1; i <= n; ++i)
        ++q[a[i]];

    vector<int> ans;
    int u = 1;
    while (u <= n)
    {
        int yans = 0;
        for (int i = 0; ; ++i)
        {
            c[i] = false;
            if (!q[i])
            {
                yans = i;
                break;
            }
        }

        ans.push_back(yans);

        int qq = 0;
        for (int i = u; i <= n; ++i)
        {
            --q[a[i]];
            if (a[i] < yans)
            {
                if (!c[a[i]])
                {
                    c[a[i]] = true;
                    ++qq;
                }
            }
            if (qq == yans)
            {
                u = i + 1;
                break;
            }
        }
    }

    cout << sz(ans) << "\n";
    for (int i = 0; i < sz(ans); ++i)
        cout << ans[i] << ' ';
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