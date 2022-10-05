#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

int ask(int x)
{
    cout << "? " << x << endl;
    int res;
    cin >> res;
    return res;
}

void solve()
{
    int n;
    cin >> n;
    int l = 1, r = 5e6;
    while (l <= r)
    {
        int m = (l + r) >> 1;
        if (ask(m) != 1)
            l = m + 1;
        else
            r = m - 1;
    }
    int cur = l;
    for (int i = 2; i <= n; i++)
    {
        while (true)
        {
            int need = cur / i;
            if (need * i == cur)
                need--;
            if (ask(need) == i)
                cur = need * i;
            // else
                break;
        }
    }

    cout << "! " << cur << endl;
}
int main()
{
    int t = 1;
    // scanf ("%d", &t);
    while (t--)
        solve();
}