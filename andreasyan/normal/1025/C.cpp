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
char a[N];

void solv()
{
    cin >> a;
    n = strlen(a);
    for (int i = n; i < n * 2; ++i)
        a[i] = a[i - n];

    int ans = 0;

    int q = 1;
    for (int i = 1; i < n * 2; ++i)
    {
        if (a[i] != a[i - 1])
            ++q;
        else
        {
            ans = max(ans, min(n, q));
            q = 1;
        }
    }
    ans = max(ans, min(n, q));

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
    //cin >> tt;
    while (tt--)
        solv();
    return 0;
}