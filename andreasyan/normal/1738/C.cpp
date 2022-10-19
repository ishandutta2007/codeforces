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

bool dp[N][N][2][2];
void pre()
{
    for (int q0 = 0; q0 < N; ++q0)
    {
        for (int q1 = 0; q1 < N; ++q1)
        {
            for (int z = 0; z < 2; ++z)
            {
                for (int s = 0; s < 2; ++s)
                {
                    if (q0 == 0 && q1 == 0)
                    {
                        if (z == 0 && s == 0)
                            dp[q0][q1][z][s] = true;
                        else if (z == 1 && s == 1)
                            dp[q0][q1][z][s] = true;
                    }
                    else
                    {
                        if (q0 && dp[q0 - 1][q1][(z ^ 1)][s] == false)
                            dp[q0][q1][z][s] = true;
                        if (q1 && dp[q0][q1 - 1][(z ^ 1)][(s ^ (z ^ 1))] == false)
                            dp[q0][q1][z][s] = true;
                    }
                }
            }
        }
    }
}

int n;
int a[N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    int q0 = 0, q1 = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] % 2 == 0)
            ++q0;
        else
            ++q1;
    }

    if (dp[q0][q1][0][0])
        cout << "Alice\n";
    else
        cout << "Bob\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    pre();

    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}