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
const int N = 300005;

int u[N];

void pre()
{
    bool z = false;
    for (int i = 1; ; ++i)
    {
        int q[3] = {i / 3, i / 3, i / 3};
        for (int j = 0; j < i % 3; ++j)
            ++q[j];
        int s = 2 * (q[0] * q[1] + q[0] * q[2] + q[1] * q[2]);
        u[i] = s;

        if (s >= 1000000000)
        {
            z = true;
            break;
        }
    }

    for (int i = 1; i < N; ++i)
        u[i] = max(u[i], u[i - 1]);
}

void solv()
{
    int n;
    cin >> n;

    int l = 2, r = N - 1;
    int ans;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (u[m] >= n)
        {
            ans = m;
            r = m - 1;
        }
        else
            l = m + 1;
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

    pre();

    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}