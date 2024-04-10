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
const int N = 200005, M = 1000000007;

int n;
int b[N];

ll p[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &b[i]);

    for (int i = 1; i <= n; ++i)
        p[i] = p[i - 1] + b[i];

    map<ll, int> mp;
    mp[0] = 1;
    int s = 1;
    for (int i = 1; i <= n; ++i)
    {
        int u = (s - mp[p[i - 1]] + M) % M;
        mp[p[i - 1]] = (mp[p[i - 1]] + u) % M;
        s = (s + u) % M;
    }

    printf("%d\n", s);
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