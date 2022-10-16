#include <bits/stdc++.h>

#define lint long long int
#define lsb(x) ((x) & (-(x)))
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define inf (1 << 30)
using namespace std;

int v[100005];

int main()
{
    int n = 0, k = 0;
    cin >> n >> k;

    int ans = 2 * (n - 1) - k + 1;
    for (int i = 1; i <= k; i++) {
        int x = 0;
        cin >> x;

        for (int j = 1; j <= x; j++)
            cin >> v[j];

        for (int j = 1; j <= x; j++)
            if (j == v[j])
                ans -= 2 * (j > 1);
            else
                break;
    }

    cout << ans << '\n';
    return 0;
}