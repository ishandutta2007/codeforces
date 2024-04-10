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
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1; i <= n; ++i)
        a[i] %= 2;

    int q[2] = {};
    for (int i = 1; i <= n; ++i)
        q[a[i]]++;

    if (abs(q[0] - q[1]) >= 2)
        cout << "-1\n";
    else
    {
        vector<int> v;
        for (int i = 1; i <= n; ++i)
        {
            if (a[i] == 1)
                v.push_back(i);
        }

        ll ans = 0;
        if (q[1] > q[0])
        {
            for (int i = 0; i < sz(v); ++i)
            {
                ans += abs(v[i] - (i * 2 + 1));
            }
        }
        else if (q[1] < q[0])
        {
            for (int i = 0; i < sz(v); ++i)
            {
                ans += abs(v[i] - (i + 1) * 2);
            }
        }
        else
        {
            for (int i = 0; i < sz(v); ++i)
            {
                ans += abs(v[i] - (i * 2 + 1));
            }
            ll yans = 0;
            for (int i = 0; i < sz(v); ++i)
            {
                yans += abs(v[i] - (i + 1) * 2);
            }
            ans = min(ans, yans);
        }
        cout << ans << "\n";
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
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}