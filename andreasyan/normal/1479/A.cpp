#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rnf(2106);
const int N = 100005;

int n;

int qry(int i)
{
    if (i == 0 || i == n + 1)
        return N;
    printf("? %d\n", i);
    fflush(stdout);
    int ans;
    scanf("%d", &ans);
    return ans;
}

void solv()
{
    scanf("%d", &n);

    int l = 1, r = n;
    while (1)
    {
        int m = (l + r) / 2;
        int ul = qry(m - 1);
        int u = qry(m);
        int ur = qry(m + 1);
        if (ul > u && u < ur)
        {
            printf("! %d\n", m);
            fflush(stdout);
            return;
        }
        else
        {
            if (ul < u)
                r = m - 1;
            else
                l = m + 1;
        }
    }
}

int main()
{
    #ifdef SOMETHING
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    int tt = 1;
    //scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}