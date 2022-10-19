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
const int N = 2003;

int n, p;
int a[N];

void solv()
{
    scanf("%d%d", &n, &p);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    vector<int> ans;
    for (int s = 1; s < N; ++s)
    {
        int maxu = 0;
        int x = s;
        int i = 1;
        int q = 0;
        while (1)
        {
            if (i <= n && a[i] <= x)
            {
                ++q;
                ++i;
                continue;
            }
            maxu = max(maxu, q);
            if (q == 0)
            {
                if (i <= n)
                    maxu = N;
                break;
            }
            --q;
            ++x;
        }
        if (maxu < p)
        {
            ans.push_back(s);
        }
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i)
        printf("%d ", ans[i]);
    printf("\n");
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