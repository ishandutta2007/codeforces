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
char a[N];

void solv()
{
    scanf(" %s", a);
    n = strlen(a);
    int bb = 0, aa = 0;
    int q = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == 'A')
            ++q;
        else
            --q;
        if (q < 0)
        {
            bb -= q;
            q = 0;
        }
    }
    aa = q;
    printf("%d\n", (bb % 2) + aa);
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