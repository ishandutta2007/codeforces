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
const int N = 5003;

int n;
int a[N];

int rec(int l, int r, int u)
{
    if (l > r)
        return 0;
    int ans = (r - l + 1);

    int minu = a[l];
    for (int i = l; i <= r; ++i)
    {
        minu = min(minu, a[i]);
    }

    int yans = minu - u;
    int ul = l;
    for (int i = l; i <= r; ++i)
    {
        if (a[i] == minu)
            ul = i + 1;
        else
        {
            if (i == r || a[i + 1] == minu)
                yans += rec(ul, i, minu);
        }
    }

    return min(ans, yans);
}

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);

    printf("%d\n", rec(1, n, 0));
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    int tt;
    tt = 1;
    while (tt--)
        solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}