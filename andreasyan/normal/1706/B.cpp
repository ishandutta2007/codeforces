#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
typedef long long ll;
const int N = 100005;

int n;
int a[N];

int u[N];
int ans[N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1; i <= n; ++i)
    {
        u[i] = -1;
        ans[i] = 0;
    }

    for (int i = 1; i <= n; ++i)
    {
        if (u[a[i]] == -1 || (u[a[i]] % 2 != i % 2))
        {
            ++ans[a[i]];
            u[a[i]] = i;
        }
    }

    for (int i = 1; i <= n; ++i)
        cout << ans[i] << ' ';
    cout << "\n";
}

int main()
{
    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}