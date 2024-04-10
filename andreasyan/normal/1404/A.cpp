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
const int N = 300005;

int n, k;
char a[N];

void solv()
{
    scanf("%d%d", &n, &k);
    scanf(" %s", a);

    for (int i = 0; i < k; ++i)
    {
        char u = '?';
        for (int j = i; j < n; j += k)
        {
            if (a[j] == '?')
                continue;
            if (u == '?')
            {
                u = a[j];
                continue;
            }
            if (a[j] != u)
            {
                printf("NO\n");
                return;
            }
        }
        for (int j = i; j < n; j += k)
            a[j] = u;
    }

    int q[2] = {};
    for (int i = 0; i < k; ++i)
    {
        if (a[i] != '?')
            q[a[i] - '0']++;
    }

    if (q[0] > k / 2 || q[1] > k / 2)
        printf("NO\n");
    else
        printf("YES\n");
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