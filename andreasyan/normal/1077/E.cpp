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
int a[N];

map<int, int> mp;

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        int x;
        scanf("%d", &x);
        mp[x]++;
    }
    n = 0;
    for (map<int, int>::iterator it = mp.begin(); it != mp.end(); ++it)
    {
        a[++n] = it->se;
    }
    sort(a + 1, a + n + 1);
    int ans = 0;
    for (int sq = 1; sq <= 200000; ++sq)
    {
        int s = 1;
        int yans = 0;
        int q = sq;
        while (1)
        {
            int i = lower_bound(a + s, a + n + 1, q) - a;
            if (i <= n)
            {
                yans += q;
                s = i + 1;
                q *= 2;
            }
            else
                break;
        }
        ans = max(ans, yans);
    }
    printf("%d\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}