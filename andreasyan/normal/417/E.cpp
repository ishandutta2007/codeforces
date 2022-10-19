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
const int N = 102;

bool dp[N * N][N];
int p[N * N][N];

vector<int> v[N];

void solv()
{
    dp[0][0] = true;
    for (int i = 0; i < N * N; ++i)
    {
        for (int q = 0; q < N; ++q)
        {
            if (dp[i][q] && q < N - 1)
            {
                for (int j = 1; i + j * j < N * N; ++j)
                {
                    dp[i + j * j][q + 1] = true;
                    p[i + j * j][q + 1] = j;
                }
            }
        }
    }
    for (int q = 0; q < N; ++q)
    {
        int i = 10000;
        for (int qq = q; qq > 0; --qq)
        {
            v[q].push_back(p[i][qq]);
            i -= p[i][qq] * p[i][qq];
        }
    }
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            printf("%d ", v[n][i] * v[m][j]);
        }
        printf("\n");
    }
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