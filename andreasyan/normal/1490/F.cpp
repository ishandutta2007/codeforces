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
int a[N];

int p[N];
int s[N];
void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);

    sort(a + 1, a + n + 1);

    vector<int> v;
    int q = 1;
    for (int i = 2; i <= n; ++i)
    {
        if (a[i] == a[i - 1])
            ++q;
        else
        {
            v.push_back(q);
            q = 1;
        }
    }
    v.push_back(q);

    v.push_back(0);
    sort(all(v));

    for (int i = 1; i < sz(v); ++i)
        p[i] = p[i - 1] + v[i];
    s[sz(v)] = 0;
    for (int i = sz(v) - 1; i >= 1; --i)
        s[i] = s[i + 1] + v[i];

    int ans = n;
    for (int i = 1; i < sz(v); ++i)
    {
        ans = min(ans, p[i - 1] + s[i] - (sz(v) - i) * v[i]);
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

    int tt = 1;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}