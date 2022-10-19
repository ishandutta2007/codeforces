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

int n, k;
char a[N];

void solv()
{
    scanf("%d%d", &n, &k);
    scanf("%s", a);

    vector<int> v;
    bool z = false;
    int q = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == 'L')
            ++q;
        else
        {
            if (z)
                v.push_back(q);
            q = 0;
            z = true;
        }
    }

    q = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == 'W')
            ++q;
    }

    if (q + k >= n)
    {
        printf("%d\n", n * 2 - 1);
        return;
    }

    if (q == 0)
    {
        printf("%d\n", max(0, k * 2 - 1));
        return;
    }

    int ans = q * 2;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == 'W' && (i == 0 || a[i - 1] == 'L'))
            --ans;
    }
    sort(all(v));
    for (int i = 0; i < sz(v); ++i)
    {
        if (v[i] == 0)
            continue;
        if (k >= v[i])
        {
            k -= v[i];
            ans += v[i] * 2;
            ++ans;
        }
        else
            break;
    }
    ans += k * 2;
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

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}