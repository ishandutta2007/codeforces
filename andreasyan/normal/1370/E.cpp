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
const int N = 1000006, INF = 1000000009;

int n;
char a[N], b[N];

void solv()
{
    scanf("%d", &n);
    scanf(" %s", a);
    scanf(" %s", b);
    int qa = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == '1')
            ++qa;
    }
    int qb = 0;
    for (int i = 0; i < n; ++i)
    {
        if (b[i] == '1')
            ++qb;
    }
    if (qa != qb)
    {
        printf("-1\n");
        return;
    }
    int q0 = 0, q1 = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == b[i])
            continue;
        if (a[i] == '0')
        {
            if (q1)
                --q1;
            ++q0;
        }
        else
        {
            if (q0)
                --q0;
            ++q1;
        }
    }
    printf("%d\n", q0 + q1);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}