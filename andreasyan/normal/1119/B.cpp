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
const int N = 1003;

int n, h;
int a[N];

int b[N];
bool stg(int k)
{
    for (int i = 1; i <= k; ++i)
    {
        b[i] = a[i];
    }
    sort(b + 1, b + k + 1);
    int hh = 0;
    for (int i = k; i >= 1; i -= 2)
    {
        hh += b[i];
        if (hh > h)
            return false;
    }
    return true;
}

void solv()
{
    scanf("%d%d", &n, &h);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int k = n; k >= 1; --k)
    {
        if (stg(k))
        {
            printf("%d\n", k);
            return;
        }
    }
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