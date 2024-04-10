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

int p, f;
int qs, qw;
int s, w;

void solv()
{
    scanf("%d%d", &p, &f);
    scanf("%d%d", &qs, &qw);
    scanf("%d%d", &s, &w);
    int ans = 0;
    for (int i = 0; i <= qs; ++i)
    {
        int yans = 0;

        int u = p;
        int qss = qs, qww = qw;
        if (i * s > u)
            break;
        yans += i;
        u -= i * s;
        qss -= i;

        int q = min(qww, u / w);
        yans += q;
        u -= q * w;
        qww -= q;

        u = f;
        if (s < w)
        {
            yans += min(qss, u / s);
            u -= min(qss, u / s) * s;

            yans += min(qww, u / w);
            u -= min(qww, u / w) * w;
        }
        else
        {
            yans += min(qww, u / w);
            u -= min(qww, u / w) * w;

            yans += min(qss, u / s);
            u -= min(qss, u / s) * s;
        }
        ans = max(ans, yans);
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

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}