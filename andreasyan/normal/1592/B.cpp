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

int n, x;
int a[N];

void solv()
{
    cin >> n >> x;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    if (x <= n / 2)
    {
        cout << "YES\n";
        return;
    }

    x = n - x;

    vector<int> v;
    for (int i = 1; i <= x; ++i)
        v.push_back(a[i]);
    for (int i = n - x + 1; i <= n; ++i)
        v.push_back(a[i]);
    sort(all(v));

    int j = 0;
    for (int i = 1; i <= x; ++i)
        a[i] = v[j++];
    for (int i = n - x + 1; i <= n; ++i)
        a[i] = v[j++];

    bool z = true;
    for (int i = 1; i < n; ++i)
    {
        if (a[i] > a[i + 1])
        {
            z = false;
            break;
        }
    }

    if (z)
        cout << "YES\n";
    else
        cout << "NO\n";
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