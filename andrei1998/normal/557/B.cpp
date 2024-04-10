#include <bits/stdc++.h>

#define lint long long int
#define lsb(x) ((x) & (-(x)))
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define inf (1 << 30)
using namespace std;

int v[200005];

int main()
{
    int n = 0, w = 0;
    cin >> n >> w;

    for (int i = 1; i <= 2 * n; i++)
        cin >> v[i];
    sort (v + 1, v + 2 * n + 1);

    double ans = min((double)v[1], v[n + 1] * 0.5);
    ans = min(ans, w / (3.0 * n));

    cout << fixed << setprecision(6) << ' ' << ans * 3.0 * n << endl;
    return 0;
}