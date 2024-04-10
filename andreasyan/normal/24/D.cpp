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

int n, m;
int si, sj;

double a[N], b[N], c[N];

void solv()
{
    scanf("%d%d", &n, &m);
    scanf("%d%d", &si, &sj);
    for (int i = n - 1; i >= si; --i)
    {
        for (int j = 1; j <= m; ++j)
            b[i] = 0;
        for (int k = 0; k < 80; ++k)
        {
            for (int j = 1; j <= m; ++j)
            {
                double u = a[j] + b[j];
                int q = 2;
                if (j > 1)
                {
                    u += b[j - 1];
                    ++q;
                }
                if (j < m)
                {
                    u += b[j + 1];
                    ++q;
                }
                c[j] = u / q + 1;
            }
            for (int j = 1; j <= m; ++j)
                b[j] = c[j];
        }
        for (int j = 1; j <= m; ++j)
            a[j] = b[j];
    }
    printf("%.9f\n", a[sj]);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}