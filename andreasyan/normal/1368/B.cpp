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
const int n = 10;
const char a[20] = "codeforces";

ll k;

int q[20];

void solv()
{
    scanf("%lld", &k);
    int i = 0;
    while (1)
    {
        ++q[i];
        i = (i + 1) % n;
        ll kk = 1;
        for (int i = 0; i < n; ++i)
            kk *= q[i];
        if (kk >= k)
        {
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < q[i]; ++j)
                {
                    printf("%c", a[i]);
                }
            }
            printf("\n");
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