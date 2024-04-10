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

int n;
int a[N];

int ans[N];

int b[N];
void ubd()
{
    vector<int> v;
    vector<int> nv;
    for (int i = 1; i <= n; ++i)
    {
        nv.clear();
        int x = b[i];
        for (int j = 0; j < sz(v); ++j)
        {
            if ((v[j] & b[i]))
                x |= v[j];
            else
                nv.push_back(v[j]);
        }
        nv.push_back(x);
        v = nv;
    }

    if (sz(v) > 1)
        return;

    int yans = 0;
    for (int i = 1; i <= n; ++i)
    {
        yans += abs(a[i] - b[i]);
    }
    for (int i = 1; i <= n; ++i)
    {
        yans -= abs(a[i] - ans[i]);
    }
    if (yans < 0)
    {
        for (int i = 1; i <= n; ++i)
            ans[i] = b[i];
    }
}

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1; i <= n; ++i)
    {
        ans[i] = a[i];
        if (ans[i] % 2 == 0)
            ++ans[i];
    }

    for (int i = 1; i <= n; ++i)
    {
        b[i] = a[i];
        if (b[i] == 0)
            ++b[i];
    }
    ubd();

    for (int i = 1; i <= n; ++i)
    {
        ++b[i];
        ubd();
        --b[i];

        --b[i];
        ubd();
        ++b[i];
    }

    vector<int> v[30];
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < 30; ++j)
        {
            if ((b[i] & (1 << j)))
            {
                v[j].push_back(i);
                break;
            }
        }
    }

    for (int j = 29; j > 0; --j)
    {
        if (!v[j].empty())
        {
            if (sz(v[j]) == 1)
            {
                --b[v[j][0]];
                ubd();
                ++b[v[j][0]];
            }
            else
            {
                --b[v[j][0]];
                ++b[v[j][1]];
                ubd();
                ++b[v[j][0]];
                --b[v[j][1]];
            }
            break;
        }
    }

    for (int z = 1; z <= n; ++z)
    {
        if (a[z] == 0)
        {
            ++b[z];
            for (int i = 1; i <= n; ++i)
            {
                ++b[i];
                ubd();
                --b[i];

                --b[i];
                ubd();
                ++b[i];
            }
            break;
        }
    }

    int yans = 0;
    for (int i = 1; i <= n; ++i)
        yans += abs(ans[i] - a[i]);
    cout << yans << "\n";
    for (int i = 1; i <= n; ++i)
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