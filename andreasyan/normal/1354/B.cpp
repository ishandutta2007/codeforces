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
    int u[3] = {-1, -1, -1};
    int ans = N;
    for (int i = 0; i < n; ++i)
    {
        u[a[i] - '1'] = i;
        int minu = N;
        for (int j = 0; j < 3; ++j)
            minu = min(minu, u[j]);
        if (minu >= 0)
            ans = min(ans, i - minu + 1);
    }
    if (ans == N)
        printf("0\n");
    else
        printf("%d\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}