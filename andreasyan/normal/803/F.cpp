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
const int N = 100005, M = 1000000007;

int n;
int q[N];

int ast[N];

int ans[N];

void solv()
{
    scanf("%d", &n);
    while (n--)
    {
        int x;
        scanf("%d", &x);
        ++q[x];
    }
    ast[0] = 1;
    for (int i = 1; i < N; ++i)
        ast[i] = (ast[i - 1] * 2) % M;
    for (int i = N - 1; i >= 1; --i)
    {
        int qq = 0;
        for (int j = i; j < N; j += i)
            qq += q[j];
        ans[i] = (ast[qq] - 1 + M) % M;
        for (int j = i + i; j < N; j += i)
            ans[i] = (ans[i] - ans[j] + M) % M;
    }
    printf("%d\n", ans[1]);
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