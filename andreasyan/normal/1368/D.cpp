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

vector<int> v[20];

int n;
int a[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < 20; ++j)
        {
            if ((a[i] & (1 << j)))
                v[j].push_back(i);
        }
    }
    ll ans = 0;
    for (int ii = 0; ii < n; ++ii)
    {
        int x = 0;
        for (int j = 0; j < 20; ++j)
        {
            while (1)
            {
                if ((x & (1 << j)))
                    break;
                if (v[j].empty())
                    break;
                int xx = x;
                int yy = a[v[j].back()];
                x = (xx | yy);
                a[v[j].back()] = (xx & yy);
                v[j].pop_back();
            }
        }
        ans += (x * 1LL * x);
    }
    printf("%lld\n", ans);
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