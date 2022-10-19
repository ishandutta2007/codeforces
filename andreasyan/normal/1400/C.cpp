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
char s[N];
int x;

char w[N];

void solv()
{
    scanf(" %s", s);
    n = strlen(s);
    scanf("%d", &x);
    for (int i = 0; i <= n; ++i)
        w[i] = 0;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '0')
        {
            if (i - x >= 0)
                w[i - x] = '0';
            if (i + x < n)
                w[i + x] = '0';
        }
    }
    for (int i = 0; i < n; ++i)
    {
        if (w[i] == 0)
            w[i] = '1';
    }
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '1')
        {
            if (i - x >= 0 && w[i - x] == '1')
                continue;
            if (i + x < n && w[i + x] == '1')
                continue;
            printf("-1\n");
            return;
        }
    }
    printf("%s\n", w);
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