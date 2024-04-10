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

int n, m;
int a[N];

void solv()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    int u = n + 1;
    while (u > 1 && a[u - 1] == u - 1)
        --u;

    double ans = 1;
    if (u == 1)
        ans = 0;
    while (m--)
    {
        int r;
        double p;
        cin >> r >> p;
        if (r + 1 >= u)
            ans *= (1 - p);
    }

    cout << (1 - ans) << endl;
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(9);
    int tt;
    cin >> tt;
    while (tt--)
        solv();
    return 0;
}