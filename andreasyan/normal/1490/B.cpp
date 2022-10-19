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
const int N = 30004;

int n;
int a[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);

    int q[3] = {};
    for (int i = 1; i <= n; ++i)
        q[a[i] % 3]++;

    int ans = 0;
    while (1)
    {
        if (q[0] == q[1] && q[1] == q[2])
            break;
        if (q[0] >= q[1] && q[0] >= q[2])
        {
            --q[0];
            ++q[1];
        }
        else if (q[1] >= q[0] && q[1] >= q[2])
        {
            --q[1];
            ++q[2];
        }
        else if (q[2] >= q[0] && q[2] >= q[1])
        {
            --q[2];
            ++q[0];
        }
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

    int tt = 1;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}