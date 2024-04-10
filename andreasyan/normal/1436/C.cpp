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
const int N = 1003, M = 1000000007;

int x, n, pos;

void solv()
{
    scanf("%d%d%d", &n, &x, &pos);
    --x;

    int l = 0, r = n;
    int ql = 0, qr = 0;
    while (l < r)
    {
        int m = (l + r) / 2;
        if (m <= pos)
        {
            if (m < pos)
                ++ql;
            l = m + 1;
        }
        else
        {
            ++qr;
            r = m;
        }
    }
    int qll = x;
    int qrr = n - 1 - x;
    if (!(ql <= qll && qr <= qrr))
    {
        printf("0\n");
        return;
    }
    int ans = 1;
    for (int i = qll; i >= qll - ql + 1; --i)
        ans = (ans * 1LL * i) % M;
    for (int i = qrr; i >= qrr - qr + 1; --i)
        ans = (ans * 1LL * i) % M;
    for (int i = 1; i <= n - 1 - ql - qr; ++i)
        ans = (ans * 1LL * i) % M;
    printf("%d\n", ans);
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