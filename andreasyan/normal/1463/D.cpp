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
const int N = 400005;

int n;
int a[N];

int u[N];

bool c1[N], c2[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);

    for (int i = 0; i <= n * 2; ++i)
    {
        u[i] = 0;
        c1[i] = c2[i] = false;
    }

    vector<int> v;
    for (int i = 1; i <= n * 2; ++i)
    {
        if (!binary_search(a + 1, a + n + 1, i))
            v.push_back(i);
    }

    int j = 0;
    for (int i = 1; i <= n; ++i)
    {
        while (j < n && v[j] < a[i])
            ++j;
        u[i] = j;
    }

    int minu = N;
    c2[n + 1] = true;
    for (int i = n; i >= 1; --i)
    {
        minu = min(minu - 1, u[i] - 1);
        if (minu < 0)
            break;
        c2[i] = true;
    }

    minu = N;
    c1[0] = true;
    for (int i = 1; i <= n; ++i)
    {
        minu = min(minu - 1, (n - u[i]) - 1);
        if (minu < 0)
            break;
        c1[i] = true;
    }

    int ans = 0;
    for (int i = 0; i <= n; ++i)
    {
        if (c1[i] && c2[i + 1])
            ++ans;
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
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}