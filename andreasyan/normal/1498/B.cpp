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
const int N = 100005;

int n, w;

void solv()
{
    cin >> n >> w;
    map<int, int> q;
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        q[x]++;
    }

    int ans = 0;
    while (1)
    {
        int x = w;
        bool z = false;
        for (int i = (1 << 20); i; i /= 2)
        {
            while (x >= i && q[i])
            {
                x -= i;
                --q[i];
                z = true;
            }
        }
        if (!z)
            break;
        ++ans;
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