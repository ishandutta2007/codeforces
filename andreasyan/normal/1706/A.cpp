#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
typedef long long ll;
const int N = 55;

int n, m;
int q[N];
char ans[N];

void solv()
{
    cin >> m >> n;
    for (int i = 1; i <= n; ++i)
    {
        q[i] = 0;
        ans[i] = 'B';
    }
    while (m--)
    {
        int x;
        cin >> x;
        q[min(x, n + 1 - x)]++;
    }

    for (int i = 1; i <= n / 2 + n % 2; ++i)
    {
        if (q[i] == 1)
            ans[i] = 'A';
        else if (q[i] >= 2)
            ans[i] = ans[n - i + 1] = 'A';
    }
    for (int i = 1; i <= n; ++i)
        cout << ans[i];
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