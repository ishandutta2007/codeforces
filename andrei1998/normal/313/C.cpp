#include <bits/stdc++.h>

#define lint long long int
#define lsb(x) ((x) & (-(x)))
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define inf (1 << 30)
using namespace std;

int v[2000005];

int main()
{
    ios_base :: sync_with_stdio(false);

    int n = 0;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> v[i];
    sort(v + 1, v + n + 1);

    lint ans = 0;

    int cate = n;
    while (cate) {
        for (int i = 1; i <= cate; i++)
            ans += v[n - i + 1];

        cate /= 4;
    }

    cout << ans << '\n';
    return 0;
}