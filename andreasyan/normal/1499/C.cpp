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

int minu[N];
ll s[N];
int q[N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    minu[1] = a[1];
    minu[2] = a[2];
    for (int i = 3; i <= n; ++i)
        minu[i] = min(minu[i - 2], a[i]);

    s[1] = a[1];
    s[2] = a[2];
    for (int i = 3; i <= n; ++i)
        s[i] = s[i - 2] + a[i];

    q[1] = 1;
    q[2] = 1;
    for (int i = 3; i <= n; ++i)
        q[i] = q[i - 2] + 1;

    ll ans = n * 1LL * a[1] + n * 1LL * a[2];
    for (int i = 2; i <= n; ++i)
    {
        ans = min(ans, (n - q[i] + 1) * 1LL * minu[i] + s[i] - minu[i] +
                        (n - q[i - 1] + 1) * 1LL * minu[i - 1] + s[i - 1] - minu[i - 1]);
    }

    cout << ans << endl;
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    //scanf("%d", &tt);
    cin >> tt;
    while (tt--)
        solv();
    return 0;
}