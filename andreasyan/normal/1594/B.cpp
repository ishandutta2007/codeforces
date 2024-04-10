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
const int N = 30;
const int M = 1000000007;

int n, k;

int ast[N];

void solv()
{
    cin >> n >> k;

    ast[0] = 1;
    for (int i = 1; i < N; ++i)
        ast[i] = (ast[i - 1] * 1LL * n) % M;

    int ans = 0;
    for (int i = 0; i < N; ++i)
    {
        if ((k & (1 << i)))
            ans = (ans + ast[i]) % M;
    }

    cout << ans << "\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    cin >> tt;
    while (tt--)
        solv();
    return 0;
}