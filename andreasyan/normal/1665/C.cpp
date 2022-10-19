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
int q[N];

bool stg(const vector<int>& v, int t)
{
    int u = 0;
    for (int i = 0; i < sz(v); ++i)
    {
        if (v[i] > t)
            u += (v[i] - t);
    }
    return (u <= t);
}

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        q[i] = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        int x;
        cin >> x;
        ++q[x];
    }

    sort(q + 1, q + n + 1);
    reverse(q + 1, q + n + 1);
    for (int i = 1; i <= n; ++i)
    {
        if (q[i] == 0)
        {
            q[i] = 1;
            break;
        }
    }

    int ans = 0;
    vector<int> v;
    for (int i = 1; i <= n; ++i)
    {
        if (q[i] == 0)
        {
            sort(all(v));
            reverse(all(v));
            while (!v.empty() && v.back() == 0)
                v.pop_back();
            if (v.empty())
                break;
            int l = 1, r = v[0];
            int u;
            while (l <= r)
            {
                int m = (l + r) / 2;
                if (stg(v, m))
                {
                    u = m;
                    r = m - 1;
                }
                else
                    l = m + 1;
            }
            ans += u;
            break;
        }
        ++ans;

        sort(all(v));
        reverse(all(v));
        while (!v.empty() && v.back() == 0)
            v.pop_back();
        for (int i = 0; i < sz(v); ++i)
            v[i]--;
        v.push_back(q[i] - 1);
    }

    cout << ans << "\n";
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