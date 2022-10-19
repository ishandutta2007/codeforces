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
const int N = 1000006;

int n;
char a[N];

int pa[N], pb[N], pc[N];

void solv()
{
    cin >> n;
    cin >> (a + 1);

    for (int i = 1; i <= n; ++i)
    {
        pa[i] = pa[i - 1];
        pb[i] = pb[i - 1];
        pc[i] = pc[i - 1];
        if (a[i] == 'a')
            ++pa[i];
        else if (a[i] == 'b')
            ++pb[i];
        else
            ++pc[i];
    }

    for (int d = 2; d <= 20; ++d)
    {
        for (int l = 1; l <= n - d + 1; ++l)
        {
            int r = l + d - 1;
            if (pa[r] - pa[l - 1] > pb[r] - pb[l - 1] && pa[r] - pa[l - 1] > pc[r] - pc[l - 1])
            {
                cout << d << "\n";
                return;
            }
        }
    }

    cout << "-1\n";
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
    {
        solv();
    }
    return 0;
}