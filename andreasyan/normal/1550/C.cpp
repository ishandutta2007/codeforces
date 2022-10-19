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

int n;
int a[N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    int ans = n + (n - 1);
    for (int i = 2; i < n; ++i)
    {
        if (a[i - 1] < a[i] && a[i] > a[i + 1])
            ++ans;
        if (a[i - 1] > a[i] && a[i] < a[i + 1])
            ++ans;
    }
    for (int i = 1; i <= n - 3; ++i)
    {
        bool z = true;
        for (int j = i; j <= i + 3; ++j)
        {
            vector<int> v;
            for (int k = i; k <= i + 3; ++k)
            {
                if (k == j)
                    continue;
                v.push_back(a[k]);
            }
            if (v[0] <= v[1] && v[1] <= v[2])
            {
                z = false;
                break;
            }
            if (v[0] >= v[1] && v[1] >= v[2])
            {
                z = false;
                break;
            }
        }
        ans += z;
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
    {
        solv();
    }
    return 0;
}