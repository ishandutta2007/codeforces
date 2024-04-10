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

int n, m;
int c[N], w[N];

int ans1[N], ans2[N];

struct ban
{
    int i, w;
    ban(){}
    ban(int i, int w)
    {
        this->i = i;
        this->w = w;
    }
};
bool operator<(const ban& a, const ban& b)
{
    return a.w > b.w;
}

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &c[i]);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &w[i]);
    priority_queue<ban> q;
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (c[i] % 100 == 0)
        {
            ans1[i] = c[i] / 100;
            continue;
        }
        ans1[i] = c[i] / 100;
        ans2[i] = c[i] % 100;
        m -= ans2[i];
        q.push(ban(i, (100 - c[i] % 100) * w[i]));
        while (m < 0)
        {
            ans += q.top().w;
            int i = q.top().i;
            q.pop();
            ++ans1[i];
            ans2[i] = 0;
            m += 100;
        }
    }
    printf("%lld\n", ans);
    for (int i = 1; i <= n; ++i)
        printf("%d %d\n", ans1[i], ans2[i]);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}