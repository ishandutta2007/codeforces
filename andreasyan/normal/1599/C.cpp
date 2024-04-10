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

int C(int n, int k)
{
    int ans = 1;
    for (int i = n; i >= n - k + 1; --i)
        ans *= i;
    for (int i = 1; i <= k; ++i)
        ans /= i;
    return ans;
}

void solv()
{
    int n;
    double s;
    cin >> n >> s;

    for (int q = 0; q <= n; ++q)
    {
        double p[4];
        for (int i = 0; i < 4; ++i)
        {
            p[i] = (C(q, i) * C(n - q, 3 - i)) / (double)C(n, 3);
        }

        double ans = p[3] + p[2] + p[1] / 2;

        if (ans >= s)
        {
            cout << q << "\n";
            return;
        }
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
        solv();
    return 0;
}