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
const int N = 1000006, M = 1000000007;

int n, m;

int ans;
int a[N];
void rec(int i)
{
    if (i == n)
    {
        set<vector<int> > s;
        for (int x = 0; x < (1 << n); ++x)
        {
            //if (!(x & (1 << (n - 1))))
            //    continue;
            vector<int> v;
            for (int i = 0; i < n; ++i)
            {
                if ((x & (1 << i)))
                    v.push_back(a[i]);
            }
            s.insert(v);
        }
        ans += s.size();
        return;
    }
    for (int j = 1; j <= m; ++j)
    {
        a[i] = j;
        rec(i + 1);
    }
}

void solv()
{
    scanf("%d%d", &n, &m);
    //rec(0);
    //printf("%d\n", ans);
    ans = 1;
    int ast = 1;
    for (int i = 1; i <= n; ++i)
    {
        ans = (ans * 2LL * m - ans) % M;
        ans = (ans + ast) % M;
        ast = (ast * 1LL * m) % M;
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