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

int n, qq;
int a[N];

ll p[N], s[N];

void solv()
{
    cin >> n >> qq;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 2; i <= n; ++i)
    {
        p[i] = p[i - 1] + max(0, a[i - 1] - a[i]);
    }
    for (int i = n - 1; i >= 1; --i)
    {
        s[i] = s[i + 1] + max(0, a[i + 1] - a[i]);
    }
    while (qq--)
    {
        int l, r;
        cin >> l >> r;

        if (l <= r)
            cout << p[r] - p[l] << "\n";
        else
            cout << s[r] - s[l] << "\n";
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